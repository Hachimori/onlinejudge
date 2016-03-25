#include<iostream>
using namespace std;
const int BUF = 255, INF = 1<<30;

int nVal, val[BUF], subsum[BUF][BUF];

bool read(){
  if(!(cin >> nVal)) return false;
  for(int i=0;i<nVal;i++) cin >> val[i];
  memset(subsum,0,sizeof(subsum));
  for(int i=0;i<nVal;i++){
    subsum[i][i] = val[i];
    for(int j=i+1;j<nVal;j++)
      subsum[i][j] = val[j]+subsum[i][j-1];
  }
  return true;
}

int rec(int L, int R, int dp[BUF][BUF]){
  int &ret = dp[L][R];
  if(L>R) return 0;
  if(ret!=-1) return ret;
  if(L==R) return ret = 0;

  ret = INF;
  for(int i=L;i<=R;i++){
    int t = rec(L,i-1,dp)+subsum[L][i-1]+rec(i+1,R,dp)+subsum[i+1][R];
    ret = min(ret,t);
  }
  return ret;
}

void work(){
  static int dp[BUF][BUF];
  memset(dp,-1,sizeof(dp));

  cout << rec(0,nVal-1,dp) << endl;
}

int main(){
  while(read()) work();
  return 0;
}
