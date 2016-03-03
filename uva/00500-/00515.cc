#include<iostream>
#include<string>
#define NODE 105
#define EDGE 1005
#define INF (1<<28)
using namespace std;

class Edge{
public:
  int src, dst, cost;

  Edge(){}
  Edge(int s, int d, int c): src(s), dst(d), cost(c){}
};

int nNode, nEdge;
Edge edge[EDGE];

bool read(){
  cin >> nNode;
  if(nNode==0) return false;
  cin >> nEdge;

  nNode += 2;
  
  for(int i=0;i<nEdge;i++){
    string ope;
    int s, n, c;
    cin >> s >> n >> ope >> c;

    if(ope=="lt")
      edge[i] = Edge(s+n+1,s,c-1);
    else
      edge[i] = Edge(s,s+n+1,-c-1);
  }
  
  for(int i=1;i<nNode;i++)
    edge[nEdge++] = Edge(0,i,0);
  
  return true;
}

bool bellman(){
  int dist[NODE];
  for(int i=0;i<nNode;i++)
    dist[i] = INF;
  dist[0] = 0;

  for(int i=0;i<nNode-1;i++){
    bool ok = false;
    for(int j=0;j<nEdge;j++)
      if(dist[edge[j].src]!=INF && dist[edge[j].dst]>dist[edge[j].src]+edge[j].cost){
        dist[edge[j].dst] = dist[edge[j].src]+edge[j].cost;
        ok = true;
      }

    if(!ok) break;
  }
    
  for(int i=0;i<nEdge;i++)
    if(dist[edge[i].dst]>dist[edge[i].src]+edge[i].cost)
      return false;
  return true;
}

void work(){
  cout << (bellman() ? "lamentable kingdom" : "successful conspiracy" ) << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
