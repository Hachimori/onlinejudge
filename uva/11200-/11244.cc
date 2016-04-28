#include<iostream>
#define BUF 105
using namespace std;

int row, col;
char b[BUF][BUF];

bool read(){
  cin >> row >> col;
  if(row==0 && col==0) return false;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cin >> b[i][j];
  
  return true;
}

bool isInside(int r, int c){
  return 0<=r && r<row && 0<=c && c<col;
}

void dfs(int r, int c, bool visited[BUF][BUF], int &cnt){
  const static int dr[]={-1,-1,-1,0,1,1,1,0};
  const static int dc[]={-1,0,1,1,1,0,-1,-1};

  visited[r][c] = true;
  cnt++;

  for(int i=0;i<8;i++){
    int nr=r+dr[i], nc=c+dc[i];
    if(!isInside(nr,nc) || b[nr][nc]!='*' || visited[nr][nc]) continue;
    dfs(nr,nc,visited,cnt);
  }
}

void work(){
  bool visited[BUF][BUF];
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      visited[i][j] = false;

  int ans = 0;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      if(visited[i][j] || b[i][j]!='*') continue;
      int cnt = 0;
      dfs(i,j,visited,cnt);
      if(cnt==1) ans++;
    }

  cout << ans << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
