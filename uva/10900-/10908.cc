#include<iostream>
#include<algorithm>
#define BUF 105
#define QUERY 100000
using namespace std;

class Point{
public:
  int r, c;
};

int row, col, nQuery;
Point query[QUERY];
char b[BUF][BUF];

void read(){
  cin >> row >> col >> nQuery;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cin >> b[i][j];

  for(int i=0;i<nQuery;i++)
    cin >> query[i].r >> query[i].c;
}

void work(){
  int dp[BUF][BUF];
  for(int r=row-1;r>=0;r--)
    for(int c=col-1;c>=0;c--){
      if(r==row-1 || c==col-1)
	dp[r][c] = 1;
      else {
	if(b[r][c]==b[r+1][c] && b[r][c]==b[r][c+1] && b[r][c]==b[r+1][c+1])
	  dp[r][c] = min(dp[r+1][c],min(dp[r][c+1],dp[r+1][c+1]))+1;
	else
	  dp[r][c] = 1;
      }
    }

  cout << row << ' ' << col << ' ' << nQuery << endl;
  for(int i=0;i<nQuery;i++){
    Point pt = query[i];
    int curR = pt.r, curC = pt.c, cnt = 1;
    while(curR>=0 && curC>=0 && b[curR][curC]==b[pt.r][pt.c] && dp[curR][curC]>=cnt){
      curR--;
      curC--;
      cnt += 2;
    }
    cout << cnt-2 << endl;
  }
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