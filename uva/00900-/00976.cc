#include<iostream>
#include<algorithm>
#define BUF 1005
#define BRIDGE 105
#define INF (1<<20)
using namespace std;

int row, col, bridge, space;
char b[BUF][BUF];

bool read(){
  if(!(cin >> row >> col)) return false;
  cin >> bridge >> space;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cin >> b[i][j];
  
  return true;
}

bool isInside(int r, int c){
  return 0<=r && r<row && 0<=c && c<col;
}

void dfs(int r, int c, int id[BUF][BUF]){
  static int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
  
  for(int i=0;i<4;i++){
    int nr = r+dr[i], nc = c+dc[i];
    if(!isInside(nr,nc) || id[nr][nc]!=-1 || b[nr][nc]=='.') continue;
    id[nr][nc] = id[r][c];
    dfs(nr,nc,id);
  }
}

void work(){
  static int id[BUF][BUF];
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      id[i][j] = -1;
  
  id[    0][0] = 0;
  id[row-1][0] = 1;
  
  dfs(    0,0,id);
  dfs(row-1,0,id);
  

  int cost[BUF];
  for(int c=0;c<col;c++){
    int last = 0;
    for(int r=0;r<row;r++)
      if(id[r][c]==0) last = r;
      else if(id[r][c]==1){
	cost[c] = r-last-1;
	break;
      }
  }

  static int dp[BUF][BRIDGE];
  for(int i=0;i<col;i++){
    for(int j=2;j<=bridge;j++)
      dp[i][j] = INF;
    dp[i][0] = 0;
    dp[i][1] = cost[i];
  }
    
  

  for(int c=0;c<col;c++)
    for(int b=2;b<=bridge;b++)
      for(int i=c-space-1;i>=0;i--)
	dp[c][b] = min(dp[c][b],dp[i][b-1]+cost[c]);

  int ans = INF;
  for(int c=0;c<col;c++)
    ans = min(ans,dp[c][bridge]);

  cout << ans << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
