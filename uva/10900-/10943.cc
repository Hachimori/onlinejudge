#include<iostream>
#define MOD 1000000
#define BUF 105
using namespace std;

int N, K, dp[BUF][BUF];

bool read(){
  cin >> N >> K;
  return N!=0 || K!=0;
}

int rec(int n, int k){
  if(dp[n][k]!=-1) return dp[n][k];
  if(n==0) return dp[n][k] = 1;
  if(k==0) return dp[n][k] = 0;
  return dp[n][k] = (rec(n-1,k)+rec(n,k-1))%MOD;
}

void work(){
  cout << rec(N,K) << endl;
}

int main(){
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      dp[i][j] = -1;

  while(read())
    work();

  return 0;
}