// BellmanFord
// 10449

#include<iostream>

#define INF 100000000
#define MAX_QUEUE 100000
#define MAX_SIZE 205

using namespace std;

int nNode, adjList[MAX_SIZE][MAX_SIZE];
int nQuery, query[MAX_QUEUE];

bool read(){
  int busy[MAX_SIZE];
  
  if(!(cin >> nNode)) return false;

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adjList[i][j] = INF;
  
  for(int i=0;i<nNode;i++)
    cin >> busy[i];
  
  int nEdge;
  cin >> nEdge;
  
  for(int i=0;i<nEdge;i++){
    int src, dst;
    cin >> src >> dst;
    src--, dst--;

    adjList[src][dst] = (busy[dst]-busy[src]);
    adjList[src][dst] *= (busy[dst]-busy[src]);
    adjList[src][dst] *= (busy[dst]-busy[src]);
  }
  
  cin >> nQuery;
  for(int i=0;i<nQuery;i++){
    cin >> query[i];
    query[i]--;
  }

  return true;
}

void dfs(int curr, bool isCycle[]){
  isCycle[curr] = true;
  
  for(int i=0;i<nNode;i++){
    if(adjList[curr][i]==INF) continue;
    if(isCycle[i]) continue;

    dfs(i,isCycle);
  }
}

void bellman(int cost[], bool isCycle[]){
  for(int i=0;i<nNode;i++)
    cost[i] = INF;
  
  cost[0] = 0;
  
  for(int i=0;i<nNode-1;i++)
    for(int j=0;j<nNode;j++){
      if(cost[j]==INF) continue;
      for(int k=0;k<nNode;k++)
	if(cost[k]>cost[j]+adjList[j][k])
	  cost[k] = cost[j]+adjList[j][k];
    }

  for(int i=0;i<nNode;i++)
    isCycle[i] = false;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++){
      if(cost[i]<=cost[j]+adjList[j][i]) continue;
      
      dfs(j,isCycle);
    }
}

void work(int cases){
  int cost[MAX_SIZE];
  bool isCycle[MAX_SIZE];
  
  cout << "Set #" << cases << endl;
  
  bellman(cost,isCycle);
  
  for(int i=0;i<nQuery;i++)
    if(cost[query[i]]==INF || cost[query[i]]<3 || isCycle[query[i]]) 
      cout << '?' << endl;
    else 
      cout << cost[query[i]] << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
