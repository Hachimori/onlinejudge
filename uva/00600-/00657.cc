#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int BUF = 55, dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};

int row, col;
char b[BUF][BUF];

bool read(){
  cin >> col >> row;
  if(row==0 && col==0) return false;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cin >> b[i][j];
  return true;
}


bool isInside(int r, int c){
  return 0<=r && r<row && 0<=c && c<col;
}


void recX(int r, int c, bool cnted[BUF][BUF]){
  cnted[r][c] = true;
  for(int i=0;i<4;i++){
    int nr = r + dr[i], nc = c + dc[i];
    if(isInside(nr,nc) && !cnted[nr][nc] && b[nr][nc]=='X')
      recX(nr,nc,cnted);
  }
}


void rec(int r, int c, int &cnt, bool visited[BUF][BUF], bool cnted[BUF][BUF]){
  if(b[r][c]=='X' && !cnted[r][c]){
    recX(r,c,cnted);
    cnt++;
  }
  visited[r][c] = true;
  for(int i=0;i<4;i++){
    int nr = r + dr[i], nc = c + dc[i];
    if(isInside(nr,nc) && !visited[nr][nc] && b[nr][nc]!='.')
      rec(nr,nc,cnt,visited,cnted);
  }
}


void work(int cases){
  bool visited[BUF][BUF]={}, cnted[BUF][BUF]={};
  vector<int> ans;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      if(!visited[i][j] && b[i][j]!='.'){
        int cnt = 0;
        rec(i,j,cnt,visited,cnted);
        ans.push_back(cnt);
      }

  sort(ans.begin(),ans.end());

  cout << "Throw " << cases << endl;
  for(int i=0;i<ans.size();i++){
    if(i) cout << ' ';
    cout << ans[i];
  }cout << endl;
  cout << endl;
}


int main(){
  for(int i=0;read();i++) work(i+1);
  return 0;
}
