// http://citeseer.ist.psu.edu/dasdan98experimental.html

#include<iostream>
#include<algorithm>
#include<cstdio>
#define NODE 55
#define INF 10000001
using namespace std;

int nNode, adj[NODE][NODE];

void read(){
  for(int i=0;i<NODE;i++)
    for(int j=0;j<NODE;j++)
      adj[i][j] = INF;

  int nEdge;
  cin >> nNode >> nEdge;

  for(int i=0;i<nEdge;i++){
    int s, t, c;
    cin >> s >> t >> c;  s--, t--;
    adj[s][t] = min(adj[s][t],c);
  }
}

void work(int cases){
  double dp[NODE][NODE]; // dp[k][t]: shortest path of length k from src to t

  for(int i=0;i<=nNode;i++)
    for(int j=0;j<nNode;j++)
      dp[i][j] = 1.0*NODE*INF;
    
  for(int i=0;i<nNode;i++) dp[0][i] = 0;
  
  for(int step=1;step<=nNode;step++)
    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
        if(adj[i][j]!=INF)
          dp[step][j] = min(dp[step][j],dp[step-1][i]+adj[i][j]);
  
  double minV = INF;
  for(int i=0;i<nNode;i++){
    double maxV = 0;
    for(int step=0;step<nNode;step++)
      maxV = max(maxV,(dp[nNode][i]-dp[step][i])/(nNode-step));
    minV = min(minV,maxV);
  }
  
  cout << "Case #" << cases << ": ";
  if(minV>=INF)
    cout << "No cycle found." << endl;
  else
    printf("%.2lf\n",minV);
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
