#include<iostream>
#define BUF 40
using namespace std;

int col, row, v[BUF][BUF];

void read(){
  cin >> col >> row;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cin >> v[i][j];
}

void work(){
  int ans = 1;

  for(int c=0;c<col;c++){
    int cnt = 0;
    for(int r=0;r<row;r++)
      if(v[r][c]==1)
        cnt++;
    if(cnt>1) ans *= cnt;
  }

  cout << ans << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
