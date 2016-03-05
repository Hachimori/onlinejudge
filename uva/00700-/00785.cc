#include<iostream>
using namespace std;
const int BUF = 35;

int nRow;
string b[BUF];

bool read(){
  nRow = 0;
  while(1){
    if(getline(cin,b[nRow])==NULL) return false;
    if(b[nRow][0]=='_') break;
    nRow++;
  }
  return true;
}

void dfs(int r, int c){
  static int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
  for(int i=0;i<4;i++){
    int nr=r+dr[i], nc=c+dc[i];
    if(b[nr][nc]==' '){
      b[nr][nc] = b[r][c];
      dfs(nr,nc);
    }
  }
}

void work(){
  for(int i=0;i<nRow;i++)
    for(int j=0;j<b[i].size();j++)
      if(b[i][j]!=' ' && b[i][j]!='X')
        dfs(i,j);

  for(int i=0;i<=nRow;i++)
    cout << b[i] << endl;
}

int main(){
  while(read()) work();
  return 0;
}
