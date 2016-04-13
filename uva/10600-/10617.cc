#include<iostream>
#include<string>
#define BUF 65
using namespace std;
typedef long long integer;

string s;

void read(){
  cin >> s;
}

integer rec(int L, int R, int len, integer dp[BUF][BUF][BUF]){
  if(L>R || len<0) return 0;
  if((L==R && len==1) || len==0) return dp[len][L][R]=1;
  if(L+1==R && s[L]==s[R] && len==2) return dp[len][L][R]=1;
  if(dp[len][L][R]!=-1) return dp[len][L][R];

  dp[len][L][R] = 0;

  if(s[L]==s[R]) dp[len][L][R] += rec(L+1,R-1,len-2,dp);
  dp[len][L][R] += rec(L+1,R,len,dp);
  dp[len][L][R] += rec(L,R-1,len,dp);
  dp[len][L][R] -= rec(L+1,R-1,len,dp);

  return dp[len][L][R];
}

void work(){
  static integer dp[BUF][BUF][BUF];

  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      for(int k=0;k<BUF;k++)
        dp[i][j][k] = -1;

  integer sum = 0;
  for(int len=1;len<=s.size();len++)
    sum += rec(0,s.size()-1,len,dp);
 
  cout << sum << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
