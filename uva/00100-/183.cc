#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int BUF = 205;

int row, col;
bool bit;

bool readBoardData(){
  char ch;
  cin >> ch;
  if(ch=='#') return false;
  bit = ch=='B';
  cin >> row >> col;
  return true;
}

void b2d(int r1, int c1, int r2, int c2, bool b[BUF][BUF], string &ret){
  int mask = 0;
  for(int r=r1;r<r2;r++)
    for(int c=c1;c<c2;c++)
      mask |= (1<<b[r][c]);
  switch(mask){
  case 1:
    ret += '0';
    break;
  case 2:
    ret += '1';
    break;
  case 3:
    ret += 'D';
    int lenR = (r2-r1+1)/2, lenC = (c2-c1+1)/2;
    b2d(r1,c1,r1+lenR,c1+lenC,b,ret);
    if(c1+lenC!=c2) b2d(r1,c1+lenC,r1+lenR,c2,b,ret);
    if(r1+lenR!=r2) b2d(r1+lenR,c1,r2,c1+lenC,b,ret);
    if(c1+lenC!=c2 && r1+lenR!=r2) b2d(r1+lenR,c1+lenC,r2,c2,b,ret);
    break;
  }
}

void d2b(int r1, int c1, int r2, int c2, bool b[BUF][BUF]){
  char ch;
  cin >> ch;
  if(ch=='D'){
    int lenR = (r2-r1+1)/2, lenC = (c2-c1+1)/2;
    d2b(r1,c1,r1+lenR,c1+lenC,b);
    if(c1+lenC!=c2) d2b(r1,c1+lenC,r1+lenR,c2,b);
    if(r1+lenR!=r2) d2b(r1+lenR,c1,r2,c1+lenC,b);
    if(c1+lenC!=c2 && r1+lenR!=r2) d2b(r1+lenR,c1+lenC,r2,c2,b);
  }
  else{
    for(int r=r1;r<r2;r++)
      for(int c=c1;c<c2;c++)
        b[r][c] = ch-'0';
  }
}

void work(){
  bool board[BUF][BUF];
  if(bit){
    for(int i=0;i<row;i++)
      for(int j=0;j<col;j++){
        char ch;
        cin >> ch;
        board[i][j] = ch-'0';
      }
    string ans = "";
    b2d(0,0,row,col,board,ans);
    printf("D%4d%4d\n",row,col);
    for(int i=0;i<ans.size();i++){
      if(i%50==0 && i!=0) cout << endl;
      cout << ans[i];
    }
    cout << endl;
  }
  else{
    int idx = 0;
    d2b(0,0,row,col,board);
    printf("B%4d%4d\n",row,col);
    for(int i=0,cnt=0;i<row;i++)
      for(int j=0;j<col;j++,cnt++){
        if(cnt%50==0 && cnt!=0) cout << endl;
        cout << board[i][j];
      }
    cout << endl;
  }
}

int main(){
  while(readBoardData())
    work();
  return 0;
}
