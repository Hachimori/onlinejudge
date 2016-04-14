#include<iostream>
using namespace std;
const int BUF = 55;

long long rec(int leng, int nBar, int barLeng, long long dp[BUF][BUF][BUF]){
  long long &ret = dp[leng][nBar][barLeng];
  if(ret!=-1) return ret;
  if(nBar==0 && leng==0) return ret = 1;
  if(nBar==0 || leng==0) return ret = 0;
  ret = 0;
  for(int i=1;i<=barLeng && leng-i>=0;i++)
    ret += rec(leng-i,nBar-1,barLeng,dp);
  return ret;
}

int main(){
  long long dp[BUF][BUF][BUF];
  memset(dp,-1,sizeof(dp));
  int leng, nBar, barLeng;
  while(cin >> leng >> nBar >> barLeng)
    cout << rec(leng,nBar,barLeng,dp) << endl;
  return 0;
}
