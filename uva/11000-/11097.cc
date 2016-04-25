#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cassert>
#define NODE 605
#define WALK 1001
#define QUERY 100000
#define INF 2000000000
#define EPS (1.0e-8)
#define LT(x,y) ((x)<=(y)-EPS)
using namespace std;

class Node{
public:
  int pos, nWalk;
  
  Node(){}
  Node(int p, int n): pos(p), nWalk(n){}
};

class Edge{
public:
  int dst, cost;
  
  Edge(){}
  Edge(int d, int c): dst(d), cost(c){}
};

int nNode, src, nQuery, query[QUERY];
vector<Edge> adj[NODE];

bool read(){
  int nEdge;
  if(scanf("%d%d%d",&nNode,&nEdge,&src)==EOF) return false;
  
  for(int i=0;i<nNode;i++)
    adj[i].clear();
  
  for(int i=0;i<nEdge;i++){
    int s, t, c;
    scanf("%d%d%d",&s,&t,&c);
    adj[s].push_back(Edge(t,c));
  }
  
  scanf("%d",&nQuery);
  assert(nQuery<QUERY);
  
  for(int i=0;i<nQuery;i++)
    scanf("%d",&query[i]);
    
  return true;
}

void calc(int cost[NODE][WALK]){
  queue<Node> Q;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<WALK;j++)
      cost[i][j] = INF;
  
  Q.push(Node(src,0));
  cost[src][0] = 0;
  
  while(!Q.empty()){
    Node curr = Q.front();
    Q.pop();
    if(curr.nWalk>=WALK-1) continue;
    
    for(int i=0;i<adj[curr.pos].size();i++){
      int dst = adj[curr.pos][i].dst;
      int nextCost = cost[curr.pos][curr.nWalk]+adj[curr.pos][i].cost;
      
      if(cost[dst][curr.nWalk+1]>nextCost){
	if(cost[dst][curr.nWalk+1]==INF) 
	  Q.push(Node(dst,curr.nWalk+1));
	cost[dst][curr.nWalk+1] = nextCost;
      }
    }
  }
}

void work(){
  static int cost[NODE][WALK];
  calc(cost);
  
  pair<double,int> ans[NODE];
  for(int i=0;i<nNode;i++){
    ans[i] = make_pair(cost[i][0],0);
    for(int j=1;j<WALK;j++)
      if(cost[i][j]!=INF){
	if(LT(1.0*cost[i][j]/j,ans[i].first))
	  ans[i] = make_pair(1.0*cost[i][j]/j,j);
      }
  }
  
  for(int i=0;i<nQuery;i++){
    if(query[i]==src) 
      printf("0.0000 0\n");
    else if(ans[query[i]].first==INF && ans[query[i]].second==0)
      printf("No Path\n");
    else
      printf("%.4lf %d\n",1.0*ans[query[i]].first+EPS,ans[query[i]].second);
  }
}

int main(){
  while(read()){
    work();
    cout << endl;
  }
  
  return 0;
}
