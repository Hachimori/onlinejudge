#include<iostream>
using namespace std;
const int BUF = 55;

int nVal, val[BUF], nQuery, query[BUF];

bool read(){
  cin >> nVal >> nQuery;
  if(nVal==0 && nQuery==0) return false;
  for(int i=0;i<nVal;i++) cin >> val[i];
  for(int i=0;i<nQuery;i++) cin >>query[i];
  return true;
}

long long rec(int valIdx, int nChose, int chooseLimit, 
              int cnt[BUF], long long dp[BUF][BUF]){
  if(valIdx==BUF) return nChose==chooseLimit;
  long long &ret = dp[valIdx][nChose];
  if(ret>=0) return ret;
  ret = 0;
  for(int i=0;i<=cnt[valIdx] && nChose+i<=chooseLimit;i++)
    ret += rec(valIdx+1,nChose+i,chooseLimit,cnt,dp);
  return ret;
}

void work(int cases){
  int cnt[BUF];
  memset(cnt,0,sizeof(cnt));
  
  for(int i=0;i<nVal;i++)
    cnt[val[i]]++;

  cout << "Case " << cases << ":" << endl;
  for(int i=0;i<nQuery;i++){
    long long dp[BUF][BUF];
    memset(dp,-1,sizeof(dp));
    cout << rec(0,0,query[i],cnt,dp) << endl;
  }
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  return 0;
}
