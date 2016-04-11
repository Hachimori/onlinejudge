// 6 7 2 3 6 8 # # # # # 
// # 1 8 0 7 1 # # # # # 
// # # 2 6 5 7 # # # # # 
// # # # 3 1 0 # # # # # 
// # # # # 7 6 # # # # # 
// # # # # # 8 # # # # # 
// # # # # # 8 8 # # # # 
// # # # # # 6 5 3 # # # 
// # # # # # 9 5 9 5 # # 
// # # # # # 6 4 4 1 3 # 
// # # # # # 2 6 9 4 3 8 

#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#include<sstream>
#define BUF 60
#define SUM 505
#define LEFT 1
#define RIGHT 2
#define LR 3
#define INF 100000
using namespace std;

int row, col, reqSum, b[BUF][BUF];

bool read(){
  int sz;
  cin >> sz >> reqSum;
  if(sz==0  && reqSum==0) return false;
  row = col = sz*2-1;
  
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      b[i][j] = INF;
  
  for(int i=0;i<row;i++){
    int nGet = (i<row/2 ? sz-i : i-sz+2);
    int bgn = (i<row/2 ? i : sz-1);
    for(int j=bgn;j<bgn+nGet;j++)
      cin >> b[i][j];
  }
  
  return true;
}

void dp(int r, int c, int sum, long long cnt[][BUF][SUM]){
  if(sum-b[r][c]<0) return;
  if(r==0){
    cnt[r][c][sum] = (sum==b[r][c] ? 1 : 0);
    return;
  }
  if(cnt[r][c][sum]!=-1) return;
  
  dp(r-1,c-1,sum-b[r][c],cnt);
  
  dp(r-1,c,sum-b[r][c],cnt);
  
  cnt[r][c][sum] = 0;
  if(cnt[r-1][c-1][sum-b[r][c]]>=0)
    cnt[r][c][sum] += cnt[r-1][c-1][sum-b[r][c]];
  if(cnt[r-1][c][sum-b[r][c]]>=0)
    cnt[r][c][sum] += cnt[r-1][c][sum-b[r][c]];
}

bool findPath(int r, int c, int sum, vector<int> &curPath, bool visited[][BUF][SUM]){
  if(sum>reqSum) return false;
  if(visited[r][c][sum]) return false;
  visited[r][c][sum] = true;
  
  if(r==row-1) return sum==reqSum;
  curPath.push_back(LEFT);
  if(findPath(r+1,c,sum+b[r+1][c],curPath,visited)) return true;
  curPath.pop_back();
  curPath.push_back(RIGHT);
  if(findPath(r+1,c+1,sum+b[r+1][c+1],curPath,visited)) return true;
  curPath.pop_back();
  return false;
}
 
void work(){
  static long long cnt[BUF][BUF][SUM];
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      for(int k=0;k<=reqSum;k++)
	cnt[i][j][k] = -1;
  
  for(int c=0;c<col;c++)
    dp(row-1,c,reqSum,cnt);
  
  static bool visited[BUF][BUF][SUM];
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      for(int k=0;k<=reqSum;k++)
	visited[i][j][k] = false;
  
  int leftMostC = INF;
  vector<int> path(1,INF);
  
  for(int c=0;c<col;c++){
    vector<int> curPath;
    if(findPath(0,c,b[0][c],curPath,visited)){
      leftMostC = c;
      path = curPath;
      break;
    }
  }
  
  if(leftMostC==INF)
    cout << 0 << endl << endl;
  else{
   long long ans = 0;
   for(int i=0;i<col;i++)
     if(cnt[row-1][i][reqSum]!=-1)
	ans += cnt[row-1][i][reqSum];
   
   cout << ans << endl;
   cout << leftMostC << ' ';
    stringstream out;
    for(int i=0;i<path.size();i++)
      cout << (path[i]==LEFT ? 'L' : 'R');
    cout << endl;
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}
