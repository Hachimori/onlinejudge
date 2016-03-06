#include<iostream>
using namespace std;
const int row = 9, col = 9;

char b[row][col];

void read(){
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cin >> b[i][j];
}

int dfs(int r, int c, bool &bt, bool &wt){
  static int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
  b[r][c] = '#';
  int ret = 1;
  for(int i=0;i<4;i++){
    int nr = r+dr[i], nc = c+dc[i];
    if(!(0<=nr && nr<row && 0<=nc && nc<col)) continue;
    if(b[nr][nc]=='.')
      ret += dfs(nr,nc,bt,wt);
    else if(b[nr][nc]=='X')
      bt = true;
    else if(b[nr][nc]=='O')
      wt = true;
  }
  return ret;
}

void work(){
  int black = 0, white = 0;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      if(b[i][j]=='X')
        black++;
      else if(b[i][j]=='O')
        white++;
      else if(b[i][j]=='.'){
        bool blackTouch = false, whiteTouch = false;
        int ret = dfs(i,j,blackTouch,whiteTouch);
        black += ( blackTouch && !whiteTouch ? ret : 0);
        white += (!blackTouch &&  whiteTouch ? ret : 0);
      }
  cout << "Black " << black << " White " << white << endl;
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
