#include<iostream>
using namespace std;
const int BUF = 8;


long long rec(int idx, int nPut, int mask, long long dp[BUF*2-1][BUF*2-1][1<<(BUF*2-1)], int N, int K){
  if(idx==N*2-1) return nPut==K;
  long long &ret = dp[idx][nPut][mask];
  if(ret!=-1) return ret;
  ret = 0;
  if(idx<N){
    for(int bit=N-idx-1;bit<=N-1+idx;bit+=2){
      if(mask&(1<<bit)) continue;
      ret += rec(idx+1,nPut+1,mask|(1<<bit),dp,N,K);
    }
  }
  else{
    for(int bit=idx-N+1;bit<=2*(N-1)+N-idx-1;bit+=2){
      if(mask&(1<<bit)) continue;
      ret += rec(idx+1,nPut+1,mask|(1<<bit),dp,N,K);
    }    
  }
  ret += rec(idx+1,nPut,mask,dp,N,K);
  
  return ret;
}


int main(){
  long long tbl[BUF+1][BUF*2];
  for(int N=1;N<=8;N++)
    for(int K=0;K<=N*2-1;K++){
      static long long dp[BUF*2-1][BUF*2-1][1<<(BUF*2-1)]; // dp[idx][nPut][mask]
      memset(dp,-1,sizeof(dp));
      tbl[N][K] = rec(0,0,0,dp,N,K);
    }
  
  int n, k;
  while(cin >> n >> k, n|k){
    if(k>2*n-1)
      cout << 0 << endl;
    else
      cout << tbl[n][k] << endl;
  }
  return 0;
}
