#include<iostream>
#include<numeric>
#include<cstdio>
#define BUF (505*2)
#define TYPE 6
#define INF (1<<20)
using namespace std;

int val[TYPE]={5, 10, 20, 50, 100, 200};
int cnt[TYPE], toPay;

bool read(){
  for(int i=0;i<TYPE;i++) cin >> cnt[i];
  if(accumulate(cnt,cnt+TYPE,0)==0) return false;
  
  double t;
  cin >> t;
  toPay = (int)(t*100+1e-8);

  return true;
}

int cntChangeCoin(int payed){
  int cnt = 0;
  for(int i=TYPE-1;i>=0;i--)
    while(payed-val[i]>=toPay){
      payed -= val[i];
      cnt++;
    }
  return cnt;
}

void work(){
  // dp[t][v]: minimum amount of coins to pay *exactly* v cents
  //           using t types of coins.

  int dp[TYPE+1][BUF]; 
  for(int i=0;i<=TYPE;i++)
    for(int j=0;j<BUF;j++)
      dp[i][j] = INF;
  dp[0][0] = 0;
  
  for(int i=0;i<TYPE;i++)
    for(int j=0;j<BUF;j++)
      if(dp[i][j]!=INF)
        for(int k=0;j+k*val[i]<BUF && k<=cnt[i];k++)
          dp[i+1][j+k*val[i]] = min(dp[i+1][j+k*val[i]],dp[i][j]+k);

  int ans = INF;
  for(int i=toPay;i<BUF;i++)
    if(dp[TYPE][i]!=INF)
      ans = min(ans,dp[TYPE][i]+cntChangeCoin(i));

  printf("%3d\n",ans);
}

int main(){
  while(read())
    work();

  return 0;
}
