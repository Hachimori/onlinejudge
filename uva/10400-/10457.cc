// 問題文では、道路を渡る際に車のスピードを調整しなくてはならない
// というような記述があるが、ここでは見方を少し変えて、
// 一番最初に車のスピードの上限と下限をきめて、速度制限の引っかからない
// 道路のみ通過可能とし、この問題の目的を車のスピードの上限と下限を求める
// というものに押し込める。最終的なコストを下限と上限の差+init+stopとする。
//
// init,stop: 入力で与えられる定数
//
// 
// まず、範囲の最大値を二分法で求める。スピードの下限をそれまでに現れた
// 速度制限の最小値とし、上限をその最大値とする。車が与えられた
// 範囲で通過できたら上限を減らし、通過できなければ下限を増やす。
//
// このようにして求められるのが範囲の最大値であり、次にこの範囲を
// 狭めていく。
// 
// 
// まずスピードの範囲の下限はforループで決めていく、
// 上限は下限の値+(以前に求めた範囲)のupper_boundでもとめる。
//
// なぜ、このように設定するのかというと、以前に求めた範囲より
// 狭くしないと、その範囲を更新できないので。
//
// bfsで通過可能ならば徐々に上限を狭めていく。
//
// 
// 範囲が徐々に小さくなっていくので、bfsをする回数が少なくなってゆき。
// 解に近づいてゆく。

#include<iostream>
#include<set>
#include<queue>
#include<algorithm>
#define NODE 205
#define EDGE 1000
#define QUERY 10
using namespace std;

class Edge{
public:
  int dst, fix;

  Edge(){}
  Edge(int d, int f): dst(d), fix(f){}
};

int nNode, nQuery;
vector<Edge> adj[NODE];
pair<int,int> query[QUERY];   // src, dst
int init, stop;

bool read(){
  int nEdge;
  if(!(cin >> nNode >> nEdge)) return false;
  
  for(int i=0;i<nNode;i++)
    adj[i].clear();

  for(int i=0;i<nEdge;i++){
    int src, dst, fix;
    cin >> src >> dst >> fix;
    src--, dst--;
    
    adj[src].push_back(Edge(dst,fix));
    adj[dst].push_back(Edge(src,fix));
  }
  
  cin >> init >> stop;
  
  cin >> nQuery;
  for(int i=0;i<nQuery;i++){
    cin >> query[i].first >> query[i].second;
    query[i].first--, query[i].second--;
  }
  
  return true;
}

bool bfs(int src, int dst, int low, int up){
  static bool visited[NODE];
  queue<int> Q;
  
  fill(visited,visited+nNode,false);
  Q.push(src);
  
  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();
    
    if(curr==dst) return true;
    
    for(int i=0;i<adj[curr].size();i++){
      int next = adj[curr][i].dst, fix = adj[curr][i].fix;
      if(visited[next]) continue;
      if(!(low<=fix && fix<=up)) continue;
      visited[next] = true;
      Q.push(next);
    }
  }

  return false;
}

int calcUpperBound(pair<int,int> query, int fix[], int nFix){
  int l = 0, r = nFix-1;
 
  while(l!=r){
    int mid = (l+r)/2;
    if(bfs(query.first,query.second,fix[l],fix[mid]))
      r = mid;
    else{
      if(l==mid)
	l = mid+1;
      else
	l = mid;
    }
  }
  
  return fix[l];
}

void work(){
  set<int> S;
  for(int i=0;i<nNode;i++)
    for(int j=0;j<adj[i].size();j++)
      S.insert(adj[i][j].fix);

  int fix[EDGE], nFix = 0;
  for(set<int>::iterator i=S.begin();i!=S.end();i++)
    fix[nFix++] = *i;
  
  for(int i=0;i<nQuery;i++){
    int ans = calcUpperBound(query[i],fix,nFix);
    
    for(int lBound=0;lBound<nFix;lBound++){
      int l = lBound, r = upper_bound(fix,fix+nFix,fix[lBound]+ans)-fix-1;
      
      while(l<=r && bfs(query[i].first,query[i].second,fix[l],fix[r])){
	ans = min(ans,fix[r]-fix[l]);
	r--;
      }
    }
    
    cout << ans+init+stop << endl;
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}
