#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#define INF (1<<30)
#define NODE 20005
using namespace std;

class State{
public:
  int pos, cost;
  
  State(){}
  State(int p, int c): pos(p), cost(c){}
  
  bool operator< (const State &s) const {
    return cost>s.cost;
  }
};

class Edge{
public:
  int dst, cost;
  
  Edge(){}
  Edge(int d, int c): dst(d), cost(c){}
};

int nNode, src, dst;
vector<Edge> adj[NODE];

void read(){
  int nEdge;
  cin >> nNode >> nEdge >> src >> dst;
  
  for(int i=0;i<nNode;i++)
    adj[i].clear();
  
  for(int i=0;i<nEdge;i++){
    int s, t, c;
    scanf("%d%d%d",&s,&t,&c);
    
    adj[s].push_back(Edge(t,c));
    adj[t].push_back(Edge(s,c));
  }
}

int dijkstra(){
  int cost[NODE];
  priority_queue<State> Q;

  for(int i=0;i<nNode;i++)
    cost[i] = INF;
  
  cost[src] = 0;
  Q.push(State(src,0));

  while(!Q.empty()){
    State curr = Q.top();
    Q.pop();
    
    if(curr.pos==dst) return curr.cost;
    if(cost[curr.pos]<curr.cost) continue;
    
    for(int i=0;i<adj[curr.pos].size();i++){
      int nextP = adj[curr.pos][i].dst;
      int nextC = cost[curr.pos]+adj[curr.pos][i].cost;
      if(cost[nextP]>nextC){
	cost[nextP] = nextC;
	Q.push(State(nextP,nextC));
      }
    }
  }
  
  return -1;
}

void work(int cases){
  int ret = dijkstra();

  cout << "Case #" << cases << ": ";
  if(ret==-1) cout << "unreachable" << endl;
  else cout << ret << endl;
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
