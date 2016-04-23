#include<iostream>
#include<vector>
#include<algorithm>
#define BUF 55
using namespace std;

class Data{
public:
  int cnt;
  char ch;

  Data(){}
  Data(int cnt, char ch): cnt(cnt), ch(ch){}

  bool operator< (const Data &d) const {
    if(cnt==d.cnt) return ch<d.ch;
    return cnt>d.cnt;
  }
};


int dr[]={0,1,0,-1}, dc[]={1,0,-1,0};
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

void dfs(int r, int c, bool visited[][BUF], int &cnt){
  visited[r][c] = true;
  cnt++;

  for(int i=0;i<4;i++){
    int nr = r+dr[i], nc = c+dc[i];
    if(!isInside(nr,nc) || visited[nr][nc] || b[r][c]!=b[nr][nc]) continue;
    dfs(nr,nc,visited,cnt);
  }
}

void work(int cases){
  vector<Data> ans;
  bool visited[BUF][BUF];
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      visited[i][j] = false;
  
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      if(visited[i][j] || b[i][j]=='.') continue;
      int cnt = 0;
      dfs(i,j,visited,cnt);
      ans.push_back(Data(cnt,b[i][j]));
    }
  }
  
  sort(ans.begin(),ans.end());

  cout << "Problem " << cases << ":" << endl;
  for(int i=0;i<ans.size();i++)
    cout << ans[i].ch << ' ' << ans[i].cnt << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
