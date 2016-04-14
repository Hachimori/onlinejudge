#include<iostream>
#include<algorithm>
#define INF (1<<24)
#define BUF 105
using namespace std;

int nNode, adj[BUF][BUF];

void read(){
  int nEdge;
  cin >> nNode >> nEdge;

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adj[i][j] = INF;
  
  for(int i=0;i<nEdge;i++){
    int s, t, c;
    cin >> s >> t >> c;
    s--, t--;

    if(adj[s][t]>c)
      adj[s][t] = adj[t][s] = c;
  }
}

void warshall(int cost[BUF][BUF]){
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      cost[i][j] = adj[i][j];

  for(int i=0;i<nNode;i++)
    cost[i][i] = 0;
  
  for(int k=0;k<nNode;k++)
    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
        cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
}

void work(int cases){
  int cost[BUF][BUF];
  warshall(cost);
  
  int minV = INF;
  for(int i=0;i<nNode;i++){
    bool ok = true;
    for(int j=1;j<5;j++)
      if(cost[i][j]!=cost[i][j-1])
        ok = false;
    
    if(ok)
      minV = min(minV,*max_element(cost[i],cost[i]+nNode));
  }
  
  cout << "Map " << cases << ": " << (minV==INF ? -1 : minV) << endl;
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
