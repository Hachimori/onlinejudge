#include<iostream>
using namespace std;
const int SZ = 10, BUF = 1<<SZ, INF = 1<<30;

char type;
int row, col;

void read(){
  cin >> type >> row >> col;
}


int cntBit(int mask){
  return mask ? cntBit(mask>>1)+(mask&1) : 0;
}


int calcKnight(int r, int mask1, int mask2, int dp[SZ][BUF][BUF]){
  if(r==row) return 0;
  int &ret = dp[r][mask1][mask2];
  if(ret!=-1) return ret;
  ret = -INF;
  for(int nexMask=0;nexMask<(1<<col);nexMask++){
    bool ok = true;
    for(int i=0;i<col && ok;i++){
      if(!(nexMask&(1<<i))) continue;
      if(i-1>=0  && (mask1&(1<<(i-1)))) ok = false;
      if(i+1<col && (mask1&(1<<(i+1)))) ok = false;
      if(i-2>=0  && (mask2&(1<<(i-2)))) ok = false;
      if(i+2<col && (mask2&(1<<(i+2)))) ok = false;      
    }
    if(ok) ret = max(ret,calcKnight(r+1,mask2,nexMask,dp)+cntBit(nexMask));
  }
  return ret;
}


int calcQueen(int r, int history[SZ]){
  if(r==row) return 0;
  int ret = 0;
  for(int c=0;c<col;c++){
    bool ok = true;
    for(int i=0;i<r && ok;i++)
      if(history[i]!=-1 && abs(i-r)==abs(history[i]-c))
        ok = false;
    if(ok){
      history[r] = c;
      ret = max(ret,calcQueen(r+1,history)+1);
      history[r] = -1;
    }
  }
  ret = max(ret,calcQueen(r+1,history));
  return ret;
}


int calcKing(int r, int mask, int dp[SZ][BUF]){
  if(r==row) return 0;
  int &ret = dp[r][mask];
  if(ret!=-1) return ret;
  for(int nexMask=0;nexMask<(1<<col);nexMask++){
    bool ok = true;
    for(int c=0;c<col && ok;c++){
      if(!(nexMask&(1<<c))) continue;
      if(c-1>=0  && (mask&(1<<(c-1)))) ok = false;
      if(           (mask&(1<<c    ))) ok = false;
      if(c+1<col && (mask&(1<<(c+1)))) ok = false;
      if(c+1<col && (nexMask&(1<<(c+1)))) ok = false;
    }
    if(ok) ret = max(ret,calcKing(r+1,nexMask,dp)+cntBit(nexMask));
  }
  return ret;
}


void work(){
  int history[SZ];
  static int dp1[SZ][BUF][BUF], dp2[SZ][BUF];
  memset(history,-1,sizeof(history));
  memset(dp1,-1,sizeof(dp1));
  memset(dp2,-1,sizeof(dp2));
  switch(type){
  case 'r':
    cout << min(row,col) << endl;
    break;
  case 'k':
    cout << calcKnight(0,0,0,dp1) << endl;
    break;
  case 'Q':
    cout << calcQueen(0,history) << endl;
    break;
  case 'K':
    cout << calcKing(0,0,dp2) << endl;
    break;
  }
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
