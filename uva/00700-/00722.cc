#include<iostream>
#include<string>
#define BUF 105
using namespace std;

int row, col, sr, sc;
string b[BUF];

void read(){
  cin >> sr >> sc;
  sr--, sc--;

  row = col = 0;
  getline(cin,b[0]);
  
  while(true){
    if(getline(cin,b[row])==NULL) break;
    if(b[row].size()==0) break;

    col = b[row].size();
    row++;
  }
}

bool isInside(int r, int c){
  return 0<=r && r<row && 0<=c && c<col;
}

void dfs(int r, int c, bool visited[BUF][BUF], int &cnt){
  static int dr[]={-1,0,1,0};
  static int dc[]={0,1,0,-1};
  
  visited[r][c] = true;
  cnt++;
  
  for(int i=0;i<4;i++){
    int nr = r+dr[i], nc = c+dc[i];
    if(!isInside(nr,nc) || visited[nr][nc] || b[nr][nc]=='1') continue;
    dfs(nr,nc,visited,cnt);
  }
}

void work(){
  int cnt = 0;

  if(isInside(sr,sc) && b[sr][sc]=='0'){
    bool visited[BUF][BUF];
    for(int i=0;i<row;i++)
      for(int j=0;j<col;j++) 
	visited[i][j] = false;

    dfs(sr,sc,visited,cnt);
  }

  cout << cnt << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  
  return 0;
}
