#include<iostream>
using namespace std;
const int BUF = 1005;

string s;

void read(){
  cin >> s;
}

int rec(int L, int R, int dp[BUF][BUF]){
  int &ret = dp[L][R];
  if(ret!=-1) return ret;
  if(L>=R) return ret = 0;
  return ret = s[L]==s[R] ? rec(L+1,R-1,dp) : min(rec(L+1,R,dp),min(rec(L,R-1,dp),rec(L+1,R-1,dp)))+1;
}

void work(int cases){
  static int dp[BUF][BUF];
  memset(dp,-1,sizeof(dp));
  cout << "Case " << cases << ": " << rec(0,s.size()-1,dp) << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
