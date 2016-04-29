#include<iostream>
using namespace std;
const int BUF = 2005, QUERY = 55, INF = 1<<20;

int nNode, adj[BUF][BUF], nQuery, query[QUERY][2];
bool airport[BUF];

void read(){
  memset(airport,0,sizeof(airport));

  int nAirport, nEdge;
  cin >> nNode >> nEdge >> nAirport;

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adj[i][j] = INF;

  for(int i=0;i<nAirport;i++){
    int t;
    cin >> t;
    airport[t-1] = true;
  }

  for(int i=0;i<nEdge;i++){
    int s, t;
    cin >> s >> t;
    s--, t--;
    adj[s][t] = !airport[t];
    adj[t][s] = !airport[s];
  }

  cin >> nQuery;
  for(int i=0;i<nQuery;i++){
    cin >> query[i][0] >> query[i][1];
    query[i][0]--;
    query[i][1]--;
  }
}

int dijkstra(int s, int t){
  if(s==t) return 0;

  int cost[BUF];
  bool visited[BUF];
  for(int i=0;i<nNode;i++){
    cost[i] = INF;
    visited[i] = false;
  }
  cost[s] = !airport[s];
  
  for(int k=0;k<nNode;k++){
    int minV = INF, minPos;
    for(int i=0;i<nNode;i++)
      if(minV>cost[i] && !visited[i]){
        minV = cost[i];
        minPos = i;
      }
    if(minV==INF) break;
    visited[minPos] = true;
    for(int i=0;i<nNode;i++)
      cost[i] = min(cost[i],cost[minPos]+adj[minPos][i]);
  }
  return cost[t]==INF ? -1 : cost[t];
}

void work(int cases){
  cout << "Case " << cases << ":" << endl;
  for(int i=0;i<nQuery;i++)
    cout << dijkstra(query[i][0],query[i][1]) << endl;
  cout << endl;
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
