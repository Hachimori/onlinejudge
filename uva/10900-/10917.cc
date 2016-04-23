#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#define INF INT_MAX
#define NODE 1005
#define COM 0
#define HOME 1
using namespace std;

int nNode, adj[NODE][NODE];

bool read(){
  cin >> nNode;
  if(nNode==0) return false;
  int nEdge;
  cin >> nEdge;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adj[i][j] = INF;
  
  for(int i=0;i<nEdge;i++){
    int s, t, c;
    cin >> s >> t >> c;
    s--, t--;
    adj[s][t] = adj[t][s] = c;
  }

  return true;
}

void dijkstra(bool subAdj[][NODE]){
  int cost[NODE];
  bool visited[NODE];

  for(int i=0;i<nNode;i++){
    cost[i] = INF;
    visited[i] = false;
  }
  cost[HOME] = 0;

  for(int k=0;k<nNode;k++){
    int minV = INF, minP;
    for(int i=0;i<nNode;i++)
      if(minV>cost[i] && !visited[i]){
	minV = cost[i];
	minP = i;
      }

    if(minV==INF) break;
    visited[minP] = true;

    for(int i=0;i<nNode;i++){
      if(adj[minP][i]==INF) continue;
      if(cost[i]>cost[minP]+adj[minP][i])
	cost[i] = cost[minP]+adj[minP][i];
    }
  }

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      subAdj[i][j] = cost[i]>cost[j];
}

int cntPath(int curr, int dp[], bool subAdj[][NODE]){
  if(dp[curr]!=-1) return dp[curr];
  if(curr==HOME) return 1;
  
  int sum = 0;
  for(int i=0;i<nNode;i++)
    if(subAdj[curr][i] && adj[curr][i]!=INF)
      sum += cntPath(i,dp,subAdj);

  return dp[curr] = sum;
}

void work(){
  bool subAdj[NODE][NODE];
  
  dijkstra(subAdj);
  
  
  int dp[NODE];
  for(int i=0;i<nNode;i++)
    dp[i] = -1;

  cout << cntPath(COM,dp,subAdj) << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
