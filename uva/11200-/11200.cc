#include<iostream>
#include<queue>
#include<cstdio>
#define BUF 1505
#define r first
#define c second
using namespace std;
typedef pair<int,int> Point;

int row, col;
bool wall[BUF][BUF];

void read(){
  cin >> col >> row;

  for(int i=0;i<row*3;i++)
    for(int j=0;j<col*3;j++)
      wall[i][j] = false;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      char ch;
      scanf(" %c",&ch);
      
      if(ch=='\\')
        for(int k=0;k<3;k++)
          wall[i*3+k][j*3+k] = true;
      else
        for(int k=0;k<3;k++)
          wall[i*3+k][j*3+(2-k)] = true;
    }
      
  row *= 3;
  col *= 3;
}

bool isInside(Point &p){
  return 0<=p.r && p.r<row && 0<=p.c && p.c<col;
}

bool bfs(int c, bool visited[BUF][BUF]){
  static int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
  queue<Point> Q;

  visited[0][c] = true;
  Q.push(Point(0,c));
  
  while(!Q.empty()){
    Point curr = Q.front();
    Q.pop();
    
    for(int i=0;i<4;i++){
      Point next = Point(curr.r+dr[i],curr.c+dc[i]);

      if(next.r==row) return true;
      if(!isInside(next) || visited[next.r][next.c] || wall[next.r][next.c])
        continue;

      visited[next.r][next.c] = true;
      Q.push(next);
    }
  }
  
  return false;
}

void work(){
  static bool visited[BUF][BUF];
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      visited[i][j] = false;

  int cnt = 0;
  for(int i=0;i<col;i++)
    if(!visited[0][i] && !wall[0][i])
      cnt += bfs(i,visited);

  cout << cnt << endl;
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