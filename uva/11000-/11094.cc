#include<iostream>
#include<algorithm>
#define BUF 30 
using namespace std;

int row, col, sRow, sCol;
bool isLand[BUF][BUF];

bool read(){
  if(!(cin >> row >> col)) return false;

  char b[BUF][BUF];
  for(int r=0;r<row;r++){
    for(int c=0;c<col;c++){
      char ch;
      cin >> b[r][c];
    }
  }
  
  cin >> sRow >> sCol;
  
  for(int r=0;r<row;r++)
    for(int c=0;c<col;c++)
      isLand[r][c] = b[r][c]==b[sRow][sCol];
  
  return true;
}

bool isInside(int r, int c){
  return 0<=r && r<row && 0<=c && c<col;
}

void dfs(int r, int c, int &area, bool isLand[][BUF]){
  const static int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};

  isLand[r][c] = false;
  area++;
  
  for(int i=0;i<4;i++){
    int nr = r+dr[i], nc = (col+c+dc[i])%col;
    if(!isInside(nr,nc)) continue;
    if(!isLand[nr][nc]) continue;
    dfs(nr,nc,area,isLand);
  }
}

void work(){
  int area = 0;
  if(isLand[sRow][sCol])
    dfs(sRow,sCol,area,isLand);

  int maxArea = 0;
  
  for(int r=0;r<row;r++)
    for(int c=0;c<col;c++){
      area = 0;
      if(!isLand[r][c]) continue;
      dfs(r,c,area,isLand);
      maxArea = max(maxArea,area);
    }
  
  cout << maxArea << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
