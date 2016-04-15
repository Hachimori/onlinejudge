#include<iostream>
#include<algorithm>
#define EMPTY 3
#define WALL 4
#define BUF 55
using namespace std;

int row, col, rate[3], pos[3];

bool read(){
  cin >> col >> row;
  for(int i=0;i<3;i++) cin >> rate[i];
  for(int i=0;i<3;i++) cin >> pos[i];
  
  return row!=0;
}

bool isFilled(int b[BUF][BUF]){
  for(int i=0;i<3;i++)
    if(rate[i]!=0 && b[row-1][pos[i]]==EMPTY)
      return false;
  return true;
}

int get(int r, int c, int b[BUF][BUF]){
  if(!(0<=c && c<col)) return WALL;
  return b[r][c];
}

void fall(int r, int c, int b[BUF][BUF]){
  for(;r>0 && b[r-1][c]==EMPTY;){
    swap(b[r][c],b[r-1][c]);
    r--;
  } 
  
  if(r<2 || (get(r-2,c-1,b)!=EMPTY && get(r-2,c+1,b)!=EMPTY))
    return;
    
  if(get(r-2,c-1,b)==EMPTY && get(r-2,c+1,b)==EMPTY){
    swap(b[r][c-1],b[r][c]);
    fall(r,c-1,b);
    
    swap(b[r-1][c],b[r-1][c+1]);
    fall(r-1,c+1,b);
  }
  else if(get(r-2,c-1,b)==EMPTY){
    swap(b[r][c-1],b[r][c]);
    fall(r,c-1,b);
  }
  else {
    swap(b[r][c+1],b[r][c]);
    fall(r,c+1,b);
  }
}

void work(int cases){
  int b[BUF][BUF];

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      b[i][j] = EMPTY;

  for(int time=0;!isFilled(b);time++)
    for(int i=0;i<3;i++){
      if(rate[i]==0) continue;
      if(time%rate[i]!=0 || b[row-1][pos[i]]!=EMPTY) continue;

      b[row-1][pos[i]] = i;
      fall(row-1,pos[i],b);
    }
  
  int cnt[]={0,0,0,0};
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cnt[b[i][j]]++;
  
  cout << "Case " << cases << ":";
  for(int i=0;i<4;i++)
    cout << ' ' << cnt[i];
  cout << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
