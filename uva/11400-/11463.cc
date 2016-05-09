#include<iostream>
#include<algorithm>
using namespace std;
const int BUF = 105, INF = 1<<29;

int nNode, adj[BUF][BUF], src, dst;

void read(){
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      adj[i][j] = i==j ? 0 : INF;

  int nEdge;
  cin >> nNode >> nEdge;
  for(int i=0;i<nEdge;i++){
    int s, t;
    cin >> s >> t;
    adj[s][t] = adj[t][s] = 1;
  }

  cin >> src >> dst;
}


void work(int cases){
  for(int k=0;k<nNode;k++)
    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
        adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
  
  int maxV = 0;
  for(int i=0;i<nNode;i++)
    maxV = max(maxV,adj[src][i]+adj[i][dst]);
  cout << "Case " << cases << ": " << maxV << endl;
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
