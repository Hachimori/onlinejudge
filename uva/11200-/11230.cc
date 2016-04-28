#include<iostream>
#define BUF 105
using namespace std;

int row, col, szR, szC, b[BUF][BUF];

bool read(){
  cin >> row >> col >> szR >> szC;
  if((row|col|szR|szC)==0) return false;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      char ch; cin >> ch;
      b[i][j] = ch=='1';
    }
  
  return true;
}

void work(){
  int cur[BUF][BUF], cnt = 0;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cur[i][j] = 0;

  for(int r=0;r+szR<=row;r++)
    for(int c=0;c+szC<=col;c++)
      if(cur[r][c]!=b[r][c]){
        for(int rr=0;rr<szR;rr++)
          for(int cc=0;cc<szC;cc++)
            cur[r+rr][c+cc] = !cur[r+rr][c+cc];
        cnt++;
      }

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      if(cur[i][j]!=b[i][j]){
        cout << -1 << endl;
        return;
      }
  cout << cnt << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
