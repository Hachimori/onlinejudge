#include<iostream>
#include<string>
using namespace std;
const int BUF = 1<<16;

bool rec(int s, int dp[BUF]){
  if(s==0) return true;
  if(dp[s]!=-1) return dp[s];
 
  for(int r=0;r<4;r++)
    for(int c=0;c<4;c++)
      if(s&(1<<(r*4+c)))
        if(!rec(s^(1<<(r*4+c)),dp)) return dp[s] = true;

  static int fstPos[4][2]={{0,0},{0,3},{0,0},{3,0}};
  static int posItr[4][2]={{1,0},{1,0},{0,1},{0,1}};
  static int delta[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
      int r = fstPos[i][0]+j*posItr[i][0];
      int c = fstPos[i][1]+j*posItr[i][1];
      int nex = s;
      for(int k=0;k<3;k++){
        if(!(nex&(1<<(r*4+c)))) break;
        nex ^= (1<<(r*4+c));
        if(nex!=s && !rec(nex,dp)) return dp[s] = true;
        r += delta[i][0];
        c += delta[i][1];
      }      
    }

  return dp[s] = false;
}

int main(){
  int dp[BUF];
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<(1<<16);i++)
    rec(i,dp);

  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    int mask = 0;
    for(int j=0;j<4;j++){
      string s;
      cin >> s;
      for(int k=0;k<4;k++)
        mask |= (s[k]=='.' ? (1<<(j*4+k)) : 0);
    }
    cout << (dp[mask] ? "WINNING" : "LOSING") << endl;
  }
  return 0;
}
