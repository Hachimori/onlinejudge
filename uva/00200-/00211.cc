#include<iostream>
#include<cstdio>
using namespace std;
const int ROW = 7, COL = 8, PIECE = 7;

int piece[PIECE][PIECE], board[ROW][COL];

bool read(){
  for(int i=0;i<ROW;i++)
    for(int j=0;j<COL;j++)
      if(!(cin >> board[i][j]))
        return false;
  return true;
}


void rec(int r, int c, bool used[PIECE][PIECE], int cur[ROW][COL], int &cnt){
  if(r==ROW){
    cnt++;
    for(int i=0;i<ROW;i++){
      cout << ' ';
      for(int j=0;j<COL;j++)
        printf("%4d",cur[i][j]);
      cout << endl;
    }cout << endl;
    return;
  }
  if(c==COL){
    rec(r+1,0,used,cur,cnt);
    return;
  }
  if(cur[r][c]!=-1){
    rec(r,c+1,used,cur,cnt);
    return;
  }

  for(int i=0;i<PIECE;i++)
    for(int j=0;j<PIECE;j++){
      if(used[i][j] || board[r][c]!=i) continue;
      
      // vertical
      if(r+1<ROW && board[r+1][c]==j && cur[r][c]==-1 && cur[r+1][c]==-1){
        used[i][j] = used[j][i] = true;
        cur[r][c] = cur[r+1][c] = piece[i][j];
        rec(r,c+1,used,cur,cnt);
        used[i][j] = used[j][i] = false;
        cur[r][c] = cur[r+1][c] = -1;
      }

      // horizontal
      if(c+1<COL && board[r][c+1]==j && cur[r][c]==-1 && cur[r][c+1]==-1){
        used[i][j] = used[j][i] = true;
        cur[r][c] = cur[r][c+1] = piece[i][j];
        rec(r,c+1,used,cur,cnt);
        used[i][j] = used[j][i] = false;
        cur[r][c] = cur[r][c+1] = -1;
      }
    }
}


void work(int cases){
  cout << "Layout #" << cases << ":" << endl;
  cout << endl;
  for(int i=0;i<ROW;i++){
    cout << ' ';
    for(int j=0;j<COL;j++)
      printf("%4d",board[i][j]);
    cout << endl;
  }
  cout << endl;
  cout << "Maps resulting from layout #" << cases << " are:" << endl;
  cout << endl;

  int cur[ROW][COL], cnt = 0;
  bool used[PIECE][PIECE]={};
  memset(cur,-1,sizeof(cur));
  rec(0,0,used,cur,cnt);
  cout << "There are " << cnt << " solution(s) for layout #" << cases << "." << endl;
}


int main(){
  for(int i=0,id=1;i<PIECE;i++)
    for(int j=i;j<PIECE;j++)
      piece[i][j] = piece[j][i] = id++;

  for(int i=0;read();i++){
    if(i) cout << endl << endl << endl;
    work(i+1);
  }

  return 0;
}
