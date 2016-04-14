#include<iostream>
using namespace std;
const int BUF = 105;

int nNode, src, nDst, dst[BUF], nRun, adj[BUF][BUF];

bool read(){
  cin >> nNode >> src >> nDst >> nRun;
  if(!(nNode|src|nDst|nRun)) return false;
  src--;
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      cin >> adj[i][j];
  for(int i=0;i<nDst;i++){
    cin >> dst[i];
    dst[i]--;
  }
  return true;
}

void work(){
  int dp[2][BUF];
  memset(dp,-1,sizeof(dp));
  dp[0][src] = 0;
  for(int i=0;i<nRun;i++){
    for(int j=0;j<nNode;j++) dp[(i+1)&1][j] = 0;
    for(int j=0;j<nNode;j++)
      if(dp[i&1][j]>=0)
        for(int k=0;k<nNode;k++)
          dp[(i+1)&1][k] = max(dp[(i+1)&1][k],dp[i&1][j]+adj[j][k]);
  }
  int maxV = 0;
  for(int i=0;i<nDst;i++)
    maxV = max(maxV,dp[nRun&1][dst[i]]);
  cout << maxV << endl;
}

int main(){
  while(read()) work();
  return 0;
}
