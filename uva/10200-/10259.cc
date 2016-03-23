#include<iostream>
#include<vector>
#include<algorithm>
#define r first
#define c second
#define BUF 105
using namespace std;
typedef pair<int,int> Point;

int size, jump, b[BUF][BUF];

void read(){
  cin >> size >> jump;

  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      cin >> b[i][j];
}

bool isInside(int r, int c){
  return 0<=r && r<size && 0<=c && c<size;
}

void work(){
  vector< pair<int,Point> > sorted;

  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      sorted.push_back(make_pair(b[i][j],Point(i,j)));

  sort(sorted.begin(),sorted.end());

  int dp[BUF][BUF];
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      dp[i][j] = -1;
  dp[0][0] = b[0][0];
  
  for(int i=0;i<size*size;i++){
    Point pt = sorted[i].second;
    if(dp[pt.r][pt.c]==-1) continue;
    
    for(int dr=-jump;dr<=jump;dr++)
      for(int dc=-jump;dc<=jump;dc++){
        if(dr!=0 && dc!=0) continue;
        int nr = pt.r+dr, nc = pt.c+dc;
        if(!isInside(nr,nc) || b[nr][nc]<=b[pt.r][pt.c]) continue;
        dp[nr][nc] = max(dp[nr][nc],dp[pt.r][pt.c]+b[nr][nc]);
      }
  }
   
  int maxV = 0;
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      maxV = max(maxV,dp[i][j]);
  
  cout << maxV << endl;
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
