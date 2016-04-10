// uva 10480
// max flow min cut

#include<iostream>
#include<numeric>
#include<algorithm>
#include<climits>
#include<vector>
#include<queue>
#include<cassert>

#define INF INT_MAX
#define SRC 53
#define SINK 54
#define SIZE 55

using namespace std;

class Flow{
public:
  int flow, dst;
  
  Flow(){}
  Flow(int f, int d): flow(f), dst(d){}
};

class Edge{
public:
  int dst, cap;

  Edge(){}
  Edge(int d, int c): dst(d), cap(c){}
};

int nNode;
vector<Edge> adj[SIZE];

bool read(){
  int nEdge;
  
  cin >> nNode >> nEdge;
  if(nNode==0 && nEdge==0) return false;
  
  for(int i=0;i<SIZE;i++)
    adj[i].clear();
  
  for(int i=0;i<nEdge;i++){
    int src, dst, c;
    cin >> src >> dst >> c;
    
    src--, dst--;
    if(src==dst) continue;
    
    adj[src].push_back(Edge(dst,c));
    adj[dst].push_back(Edge(src,c));
  }
  
  adj[SRC].push_back(Edge(0,INF));
  adj[0].push_back(Edge(SRC,0));

  adj[1].push_back(Edge(SINK,INF));
  adj[SINK].push_back(Edge(1,0));
  
  return true;
}

void dfs(int curr, bool avail[]){
  avail[curr] = true;
  
  for(int i=0;i<adj[curr].size();i++){
    if(avail[adj[curr][i].dst]) continue;
    if(adj[curr][i].cap==0) continue;

    dfs(adj[curr][i].dst,avail);
  }
}

void addFlow(int pi[], int &flow){
  int visited[SIZE];
  queue<Flow> Q;
  
  for(int i=0;i<SIZE;i++)
    visited[i] = 0;
  visited[SRC] = INF;
  
  Q.push(Flow(INF,SRC));

  while(!Q.empty()){
    Flow curr = Q.front();
    Q.pop();
    
    if(visited[curr.dst]>curr.flow) continue;
    
    if(curr.dst==SINK){
      flow = curr.flow;
      break;
    }
    
    for(int i=0;i<adj[curr.dst].size();i++){
      if(adj[curr.dst][i].cap<=0) continue;

      Flow next;
      next.flow = min(curr.flow,adj[curr.dst][i].cap);
      next.dst = adj[curr.dst][i].dst;

      if(visited[next.dst]>=next.flow) continue;
      visited[next.dst] = next.flow;
      pi[next.dst] = curr.dst;

      Q.push(next);
    }
  }
}

vector< pair<int,int> > minCut(){
  while(true){
    int pi[SIZE], flow = 0;
    pi[SRC] = -1;
    
    addFlow(pi,flow);
    if(flow==0) break;

    int curr = SINK;
    while(pi[curr]!=-1){
      for(int i=0;i<adj[curr].size();i++)
	if(adj[curr][i].dst==pi[curr]){
	  adj[curr][i].cap += flow;
	  break;
	}
      
      for(int i=0;i<adj[pi[curr]].size();i++)
	if(adj[pi[curr]][i].dst==curr && adj[pi[curr]][i].cap>=flow){
	  adj[pi[curr]][i].cap -= flow;
	  break;
	}
      curr = pi[curr];
    }
  }

  bool avail[SIZE];
  fill(avail,avail+SIZE,false);
  
  dfs(SRC,avail);
  
  vector< pair<int,int> > ret;
  for(int i=0;i<nNode;i++){
    if(!avail[i]) continue;
    for(int j=0;j<adj[i].size();j++){
      if(avail[adj[i][j].dst]) continue;
      ret.push_back(make_pair(i,adj[i][j].dst));
    }
  }
  
  return ret;
}

void work(){
  vector< pair<int,int> > ans = minCut();
  
  for(int i=0;i<ans.size();i++)
    cout << ans[i].first+1 << ' ' << ans[i].second+1 << endl;
}

int main(){
  while(read()){
    work();
    cout << endl;
  }
  
  return 0;
}
