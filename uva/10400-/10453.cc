#include<iostream>
using namespace std;
const int BUF = 1005;

int rec(int L, int R, int dp[BUF][BUF], string &s){
  int &ret = dp[L][R];
  if(ret!=-1) return ret;
  if(L>=R) return ret = 0;
  if(s[L]==s[R]) return ret = rec(L+1,R-1,dp,s);
  return ret = min(rec(L,R-1,dp,s),rec(L+1,R,dp,s))+1;
}

string trac(int L, int R, int dp[BUF][BUF], string &s){
  if(L>R) return "";
  if(L==R) return string(1,s[L]);
  if(s[L]==s[R]) return s[L]+trac(L+1,R-1,dp,s)+s[R];
  return dp[L][R-1]<dp[L+1][R] ? s[R]+trac(L,R-1,dp,s)+s[R] : s[L]+trac(L+1,R,dp,s)+s[L];
}

int main(){
  string s;
  while(cin>>s){
    static int dp[BUF][BUF];
    memset(dp,-1,sizeof(dp));
    cout << rec(0,s.size()-1,dp,s);
    cout << ' ' << trac(0,s.size()-1,dp,s) << endl;
  }
  return 0;
}
