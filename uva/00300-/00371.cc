#include<iostream>
using namespace std;
const int BUF = 1000005;

int rec(long long v, int dp[BUF]){
  if(v==1) return 0;
  if(v>=BUF) return rec(v&1?3*v+1:v/2,dp)+1;
  int &ret = dp[v];
  if(ret!=-1) return ret;
  return ret = rec(v&1?3*v+1:v/2,dp)+1;
}

int main(){
  static int dp[BUF];
  memset(dp,-1,sizeof(dp));

  int L, R;
  while(1){
    cin >> L >> R;
    if(!(L|R)) break;
    int maxV = -1, ans;
    if(L>R) swap(L,R);
    for(int i=L;i<=R;i++){
      int t = i==1?3:rec(i,dp);
      if(maxV<t){
        ans = i;
        maxV = t;
      }
    }
    cout << "Between " << L << " and " << R << ", " << ans 
         << " generates the longest sequence of " << maxV << " values." << endl;
  }

  return 0;
}
