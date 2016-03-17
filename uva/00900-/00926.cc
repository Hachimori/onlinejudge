#include<iostream>
using namespace std;
const int BUF = 33, BROKEN = 10000;

struct Broken{
  int r, c;
  char dir;
};

int sz, initR, initC, goalR, goalC, nBroken;
Broken broken[BROKEN];

void read(){
  cin >> sz >> initC >> initR >> goalC >> goalR;
  initR--, initC--, goalR--, goalC--;
  cin >> nBroken;
  for(int i=0;i<nBroken;i++){
    cin >> broken[i].c >> broken[i].r >> broken[i].dir;
    switch(broken[i].dir){
    case 'S':
      broken[i].dir = 'N';
      broken[i].r -= 2;
      broken[i].c -= 1;
      break;
    case 'W':
      broken[i].dir = 'E';
      broken[i].r -= 1;
      broken[i].c -= 2;
      break;      
    default:
      broken[i].r -= 1;
      broken[i].c -= 1;
      break;
    }
  }
}

long long rec(int r, int c, long long dp[BUF][BUF]){
  if(r==goalR && c==goalC) return 1;
  if(r==sz || c==sz) return 0;
  long long &ret = dp[r][c];
  if(ret!=-1) return ret;
  ret = 0;
  bool canGoNorth = true, canGoEast = true;
  for(int i=0;i<nBroken;i++)
    if(broken[i].r==r && broken[i].c==c){
      if(broken[i].dir=='N') canGoNorth = false;
      if(broken[i].dir=='E') canGoEast = false;
    }
  return ret = (canGoNorth ? rec(r+1,c,dp) : 0) + (canGoEast ? rec(r,c+1,dp) : 0);
}

void work(){
  long long dp[BUF][BUF];
  memset(dp,-1,sizeof(dp));
  cout << rec(initR,initC,dp) << endl;
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
