// Graph, dijkstra+枝狩り
//
//
// グラフのノードを (現在地)*(それまでに辿った一番栄えていた都市は、何番目に栄えていたか) 
// に拡張。 priority first search と枝狩りをする。
//
// 枝狩りは、ある都市に着いたとき、そこに着くまでにかかったコストが以前よりも高く、
// かつそこに着くまでに通った一番栄えていた都市の度合いが以前よりも高い場合、探索を打ち切るもの。
//　　↓↓↓↓↓
// if(maxCost[curr.pos]!=-1 && maxCost[curr.pos]<=curr.cost && maxCity[curr.pos]<=curr.order)
//
// これが、maxCost[curr.pos]<=curr.cost か、maxCity[curr.pos]<=curr.order のどちらかが成り立たない
// ならば次のノードを更新できる可能性があるのだが、両方成り立ってしまうと次に辿るノードよりも確実に
// コストが高くなってしまうからである。

#include<iostream>
#include<map>
#include<set>
#include<utility>
#include<queue>

#define INF 1000000000
#define MAX_SIZE 85
#define MAX_QUERY 6400

using namespace std;

class Data{
public:

  int pos, order, cost;

  Data(){}
  Data(int p, int o, int c): pos(p), order(o), cost(c){}

  bool operator<(const Data &d) const {
    if(cost==d.cost) return order>d.order;
    return cost>d.cost;
  }
};

int nNode, nQuery, city[MAX_SIZE];
pair<int,int> query[MAX_QUERY];
int adjList[MAX_SIZE][MAX_SIZE];

bool read(){
  int nEdge;
  cin >> nNode >> nEdge >> nQuery;
  if(nNode==0 && nEdge==0 && nQuery==0) return false;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adjList[i][j] = INF;
  
  for(int i=0;i<nNode;i++)
    cin >> city[i];
  
  for(int i=0;i<nEdge;i++){
    int s, t, c;
    cin >> s >> t >> c;
    s--, t--;
    adjList[s][t] = c;
    adjList[t][s] = c;
  }
  
  for(int i=0;i<nQuery;i++){
    cin >> query[i].first >> query[i].second;
    query[i].first--, query[i].second--;
  }

  return true;
}

void dijkstra(int s, int ans[][MAX_SIZE], int order[], int oToC[]){
  // cost の右側の添え字nは、n番目に栄えている都市のn
  int cost[MAX_SIZE][MAX_SIZE];
  int maxCost[MAX_SIZE], maxCity[MAX_SIZE];  // maxCost[n]: 都市nを辿ったときの最大のコスト
  priority_queue<Data> Q;                    // maxCost[n]: 都市nを辿ったときに一番栄えていた都市
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++){
      cost[i][j] = INF;
      maxCost[i] = -1;
      maxCity[i] = -1;
    }

  Q.push(Data(s,order[s],0));

  while(!Q.empty()){
    Data curr = Q.top();
    Q.pop();

    if(cost[curr.pos][curr.order]<=curr.cost) continue;
    cost[curr.pos][curr.order] = curr.cost;
    
    if(maxCost[curr.pos]!=-1 && maxCost[curr.pos]<=curr.cost && maxCity[curr.pos]<=curr.order) continue;
    
    maxCost[curr.pos] = max(maxCost[curr.pos],curr.cost);
    maxCity[curr.pos] = max(maxCity[curr.pos],curr.order);
    
    for(int i=0;i<nNode;i++){
      if(adjList[curr.pos][i]==INF) continue;
      
      Data next = curr;

      next.pos = i;
      next.order = max(curr.order,order[i]);
      next.cost += adjList[curr.pos][i];

      if(cost[next.pos][next.order]<=next.cost) continue;
      Q.push(next);
    }
  }
 
  for(int i=0;i<nNode;i++){
    int minVal = INF;
    for(int j=0;j<nNode;j++)
      if(minVal>cost[i][j]+city[oToC[j]])
	minVal = cost[i][j]+city[oToC[j]];
      
    if(minVal!=INF)
      ans[s][i] = minVal;
    else
      ans[s][i] = -1;
  }
}

void work(int cases){
  int ans[MAX_SIZE][MAX_SIZE];
  int order[MAX_SIZE], oToC[MAX_SIZE];  // order[n] は都市nが何番目に栄えているのかを表す。
                                        // oToC[n] はn番目に栄えている都市はどこかを表す。
  for(int i=0;i<nNode;i++){
    int nLow = 0;
    for(int j=0;j<nNode;j++)
      if(city[i]>city[j]) nLow++;
    
    oToC[nLow] = i;
    order[i] = nLow;
  }
    
  for(int i=0;i<nNode;i++)
    dijkstra(i,ans,order,oToC);
  
  cout << "Case #" << cases << endl;
  for(int i=0;i<nQuery;i++)
    cout << ans[query[i].first][query[i].second] << endl;
}

int main(){
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }

  return 0;
}
