#include<iostream>
using namespace std;
const int NUM = 20, BUF = 1<<20, INF = 1<<20;

int n, a[NUM], b[NUM];

bool read(){
  if(!(cin >> n)) return false;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];
  return true;
}

void work(){
  static int dp[BUF], tbl[BUF];
  memset(dp,-1,sizeof(dp));
  memset(tbl,0,sizeof(tbl));

  tbl[0] = 0;
  for(int mask=1;mask<(1<<n);mask++)
    for(int i=0;i<n;i++)
      if(mask&(1<<i)){
        tbl[mask] = tbl[mask&~(1<<i)]+a[i];
        break;
      }
  
  dp[0] = 0;
  for(int mask=1;mask<(1<<n);mask++){
    int minV = INF;
    for(int i=0;i<n;i++){
      if(!(mask&(1<<i))) continue;
      minV = min(minV,max(tbl[mask],dp[mask&~(1<<i)])+b[i]);
    }
    dp[mask] = minV;
  }
  cout << dp[(1<<n)-1] << endl;
}

int main(){
  while(read()) work();
  return 0;
}
