#include<iostream>
using namespace std;
typedef unsigned long long integer;
const int BUF = 61;

integer rec(int a, int b, integer dp[BUF][BUF]){
  if(a<=1) return 0;
  integer &ret = dp[a][b];
  if(ret!=(integer)(-1)) return ret;
  ret = 0;
  for(int i=1;i<=b;i++){
    ret += rec(a-i,b,dp);
    ret++;
  }
  return ret;
}

int main(){
  integer dp[BUF][BUF];
  memset(dp,-1,sizeof(dp));
  for(int cases=1;;cases++){
    int a, b;
    cin >> a >> b;
    if(a>60) break;
    cout << "Case " << cases << ": " << rec(a,b,dp)+1 << endl;
  }
  return 0;
}
