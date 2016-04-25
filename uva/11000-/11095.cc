// 全探索＋枝狩り
//
// 
// 枝のどちらにもinformation centerがなければ、どちらかの頂点に置く。
// それまでにinformation centerを置いた頂点の集合を保存しておいて、
// 重複があれば探索を打ち切る。
//
// また、枝を辿る順番はdfsで頂点を辿った順にし、連結成分ごとに
// 探索すると効率が良くなる。

#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#define NODE 35
using namespace std;

class Edge{
public:
  int src, dst;
  
  Edge(){}
  Edge(int s, int d): src(s), dst(d){}
};

int nNode;
bool adj[NODE][NODE];

void read(){
  int nEdge;
  cin >> nNode >> nEdge;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adj[i][j] = false;

  for(int i=0;i<nEdge;i++){
    int s, t;
    cin >> s >> t;
    adj[s][t] = adj[t][s] = true;
  }
}

void dfs(int curr, bool visited[][NODE], vector<Edge> &component){
  for(int i=0;i<nNode;i++){
    if(visited[curr][i] || !adj[curr][i]) continue;
    visited[curr][i] = visited[i][curr] = true;
    component.push_back(Edge(curr,i));
    dfs(i,visited,component);
  }
}

int minV, minPut;

void calc(int idx, int put, int nPut, set<int> &S, vector<Edge> &edge){
  if(minV<=nPut) return;

  if(idx==edge.size()){
    minV = nPut;
    minPut = put;
    return;
  }
  
  if((put&(1<<edge[idx].src)) || (put&(1<<edge[idx].dst)))
    calc(idx+1,put,nPut,S,edge);
  else{
    int nextPut = put|(1<<edge[idx].src);
    if(!S.count(nextPut)){
      S.insert(nextPut);
      calc(idx+1,nextPut,nPut+1,S,edge);
    }

    nextPut = put|(1<<edge[idx].dst);
    if(!S.count(nextPut)){
      S.insert(nextPut);
      calc(idx+1,nextPut,nPut+1,S,edge);
    }
  }
}

void work(int cases){
  bool visited[NODE][NODE];
  vector< vector<Edge> > component;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      visited[i][j] = false;
  
  for(int i=0;i<nNode;i++){
    component.push_back(vector<Edge>());
    dfs(i,visited,component.back());
    if(component.back().size()==0)
      component.pop_back();
  }
  
  vector<int> ans;
  
  for(int i=0;i<component.size();i++){
    set<int> S;
    minV = (1<<30), minPut;
    
    calc(0,0,0,S,component[i]);

    for(int j=0;j<nNode;j++)
      if(minPut&(1<<j))
	ans.push_back(j);
  }
  
  cout << "Case #" << cases << ": " << ans.size() << endl;
  for(int i=0;i<ans.size();i++){
    if(i) cout << ' ';
    cout << ans[i];
  }cout << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
