#include<iostream>
using namespace std;
const int BUF = 45;

int leng, nPeak, height;

bool read(){
  if(!(cin >> leng >> nPeak >> height)) return false;
  leng *= 2;
  return true;
}

int rec(bool preUp, int peak, int pos, int curH, int dp[2][BUF][BUF][BUF]){
  if(pos==leng) return curH==0 && peak==nPeak;
  int &ret = dp[preUp][peak][pos][curH];
  if(ret!=-1) return ret;
  ret = 0;
  if(curH>=1) ret += rec(false,peak+(preUp && curH==height),pos+1,curH-1,dp);
  ret += rec(true,peak,pos+1,curH+1,dp);
  return ret;
}

void work(){
  int dp[2][BUF][BUF][BUF];
  memset(dp,-1,sizeof(dp));
  cout << rec(false,0,0,0,dp) << endl;
}

int main(){
  while(read()) work();
  return 0;
}
