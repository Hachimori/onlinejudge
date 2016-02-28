#include<iostream>
using namespace std;
const int BUF = 256;

string s;

bool read(){
  return cin >> s;
}

bool rec(int L, int R, int dp[BUF][BUF]){
  if(L>R) return false;
  if(L==R) return 'p'<=s[L] && s[L]<='z';
  int &ret = dp[L][R];
  if(ret!=-1) return ret;
  ret = false;
  if(s[L]=='N' && rec(L+1,R,dp)) return ret = true;
  if(string("CDEI").find(s[L])!=string::npos)
    for(int i=L+1;i<R;i++)
      if(rec(L+1,i,dp) && rec(i+1,R,dp))
        return ret = true;
  return ret;
}

void work(){
  int dp[BUF][BUF];
  memset(dp,-1,sizeof(dp));
  cout << (rec(0,s.size()-1,dp) ? "YES" : "NO") << endl;
}

int main(){
  while(read()) work();
  return 0;
}
