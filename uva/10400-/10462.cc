#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
const int BUF = 105, INF = 1<<28;

class Edge{
public:
  int src, dst, cost;
  Edge(){}
  Edge(int s, int d, int c): src(s), dst(d), cost(c){}
  bool operator== (const Edge &e) const {
    return src==e.src && dst==e.dst && cost==e.cost;
  }
};

int nNode;
vector<Edge> _adj[BUF];

void read(){
  for(int i=0;i<BUF;i++) _adj[i].clear();
  int nEdge;
  cin >> nNode >> nEdge;
  for(int i=0;i<nEdge;i++){
    int s, t, c;
    cin >> s >> t >> c;
    s--, t--;
    _adj[s].push_back(Edge(s,t,c));
    _adj[t].push_back(Edge(t,s,c));
  }
}

int prim(vector<Edge> adj[BUF], bool fst){
  bool visited[BUF];
  int cost[BUF];
  Edge pre[BUF];
  for(int i=0;i<nNode;i++){
    visited[i] = false;
    cost[i] = INF;
  }
  cost[0] = 0;
  for(int k=0;k<nNode;k++){
    int minV = INF, minPos;
    for(int i=0;i<nNode;i++)
      if(minV>cost[i] && !visited[i]){
        minV = cost[i];
        minPos = i;
      }
    if(minV==INF) break;
    visited[minPos] = true;
    for(int i=0;i<adj[minPos].size();i++){
      Edge &e = adj[minPos][i];
      if(cost[e.dst]>e.cost && !visited[e.dst]){
        cost[e.dst] = e.cost;
        pre[e.dst] = e;
      }
    }
  }

  if(count(cost,cost+nNode,INF)) return INF*2;
  if(fst){
    int minV = INF;
    for(int i=1;i<nNode;i++){
      int p = pre[i].src, c = i, cost = pre[i].cost;
      adj[p].erase(find(adj[p].begin(),adj[p].end(),Edge(p,c,cost)));
      adj[c].erase(find(adj[c].begin(),adj[c].end(),Edge(c,p,cost)));
      minV = min(minV,prim(adj,false));
      adj[p].push_back(Edge(p,c,cost));
      adj[c].push_back(Edge(c,p,cost));
    }
    return minV;
  }
  else
    return accumulate(cost,cost+nNode,0);
}

void work(int cases){
  cout << "Case #" << cases << " : ";
  int t = prim(_adj,true);
  if(t==INF*2)
    cout << "No way" << endl;
  else if(t==INF)
    cout << "No second way" << endl;
  else
    cout << t << endl;
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
