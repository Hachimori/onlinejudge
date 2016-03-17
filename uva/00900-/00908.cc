#include<iostream>
#include<vector>
#include<queue>
#include<numeric>
#include<cstdio>
using namespace std;
const int BUF = 1000005, INF = 1<<30;

class Edge{
public:
  int pos, cost;
  Edge(){}
  Edge(int p, int c): pos(p), cost(c){}
  bool operator< (const Edge &e) const {
    return cost>e.cost;
  }
};

int nNode;
vector<Edge> adj[2][BUF];


bool read(){
  if(scanf("%d",&nNode)==EOF) return false;
  for(int i=0;i<2;i++)
    for(int j=0;j<nNode;j++)
      adj[i][j].clear();
  for(int i=0;i<nNode-1;i++){
    int s, t, c;
    scanf("%d%d%d",&s,&t,&c);
  }

  for(int i=0;i<2;i++){
    int nEdge;
    scanf("%d",&nEdge);
    for(int j=0;j<nEdge;j++){
      int s, t, c;
      scanf("%d%d%d",&s,&t,&c);
      adj[!i][s-1].push_back(Edge(t-1,c));
      adj[!i][t-1].push_back(Edge(s-1,c));
    }
  }
  return true;
}


int mst(int mode){
  static bool visited[BUF];
  static int cost[BUF];
  priority_queue<Edge> Q;
  
  for(int i=0;i<nNode;i++){
    visited[i] = false;
    cost[i] = INF;
  }
  Q.push(Edge(0,0));
  cost[0] = 0;

  while(!Q.empty()){
    Edge cur = Q.top();
    Q.pop();

    if(visited[cur.pos]) continue;
    visited[cur.pos] = true;
    
    for(int i=0;i<=mode;i++)
      for(int j=0;j<adj[i][cur.pos].size();j++){
        Edge &e = adj[i][cur.pos][j];
        if(cost[e.pos]>e.cost && !visited[e.pos]){
          cost[e.pos] = e.cost;
          Q.push(e);
        }
      }
  }

  return accumulate(cost,cost+nNode,0);
}


void work(){
  for(int i=0;i<2;i++)
    cout << mst(i) << endl;
}


int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  return 0;
}
