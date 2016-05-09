#include<iostream>
using namespace std;
const int BUF = 70;

long long dp[2][BUF][BUF];

long long rec(bool locked, int nBlock, int toSecure){
  long long &ret = dp[locked][nBlock][toSecure];
  if(ret!=-1) return ret;
  if(nBlock==0) return toSecure==0;
  ret = 0;
  ret += rec(false,nBlock-1,toSecure);
  if(locked){
    if(toSecure>=1) ret += rec(true,nBlock-1,toSecure-1);
  }
  else
    ret += rec(true,nBlock-1,toSecure);
  return ret;
}

int main(){
  memset(dp,-1,sizeof(dp));
  while(1){
    int nBlock, toSecure;
    cin >> nBlock >> toSecure;
    if(nBlock<0 && toSecure<0) break;
    cout << rec(1,nBlock,toSecure) << endl;
  }
  return 0;
}
