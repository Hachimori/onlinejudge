#include<iostream>
#define BUF 105
using namespace std;

int row, col;
bool wall[BUF][BUF];

bool read(){
  cin >> row >> col;
  if(row==0 && col==0) return false;
  row++, col++;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      wall[i][j] = false;

  int nWall;
  cin >> nWall;
  
  for(int i=0;i<nWall;i++){
    int r, c;
    cin >> r >> c;
    wall[r][c] = true;
  }

  return true;
}

void work(){
  int cnt[BUF][BUF];
    
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cnt[i][j] = 0;
  cnt[0][0] = 1;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      if(j+1<col && !wall[i][j+1]) cnt[i][j+1] += cnt[i][j];
      if(i+1<row && !wall[i+1][j]) cnt[i+1][j] += cnt[i][j];
    }
  
  if(cnt[row-1][col-1]==0)
    cout << "There is no path." << endl;
  else if(cnt[row-1][col-1]==1)
    cout << "There is one path from Little Red Riding Hood's house to her grandmother's house." << endl;
  else
    cout << "There are " << cnt[row-1][col-1] << " paths from Little Red Riding Hood's house to her grandmother's house." << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
