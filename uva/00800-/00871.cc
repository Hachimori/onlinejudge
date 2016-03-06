#include<iostream>
using namespace std;
const int BUF = 30;

int row, col;
string b[BUF];

void read(){
  row = 0;
  while(1){
    if(getline(cin,b[row])==NULL) break;
    if(b[row].empty()) break;
    row++;
  }
  col = b[0].size();
}

int dfs(int r, int c){
  static int dr[]={-1,-1,-1,0,1,1,1,0},dc[]={-1,0,1,1,1,0,-1,-1};
  b[r][c] = '0';
  int ret = 1;
  for(int i=0;i<8;i++){
    int nr=r+dr[i], nc=c+dc[i];
    if(0<=nr && nr<row && 0<=nc && nc<col && b[nr][nc]=='1')
      ret += dfs(nr,nc);
  }
  return ret;
}

void work(){
  int maxV = 0;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      if(b[i][j]=='1')
        maxV = max(maxV,dfs(i,j));
  cout << maxV << endl;
}

int main(){
  int cases;
  cin >> cases;
  string dummy; getline(cin,dummy); getline(cin,dummy);
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
