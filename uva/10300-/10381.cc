// toAdd[r][c]には(r,c)の隣にブロックがあったときの、(r,c)からゴールまでの
// 最短距離の最大値を保存する。
//
// あとは、スタート地点からdijkstraをするときにtoAddを利用してゴールまでの
// 最短距離の上限を求める。
//
// (r,c)からゴールまでの最短距離は、スタート地点から(r,c)までの距離+toAdd[r][c]
//
// 求めるのは上限なので、(r,c)と隣接するグリッド(nr,nc)を計算するときは
// cost[nr,nc] = max((r,c)からゴールまでの最短距離,スタート地点から(nr,nc)までの距離+toAdd[nr][nc])

#include<iostream>
#include<algorithm>
#include<queue>
#include<cassert>
#define BUF 45
#define INF 2000000000
using namespace std;

class Point{
public:
  int r, c;

  Point(){}
  Point(int r, int c): r(r), c(c){}

  bool operator== (const Point &pt) const {
    return r==pt.r && c==pt.c;
  }
};

int row, col;
Point src, dst;
int dr[]={1,0,-1,0}, dc[]={0,1,0,-1};
char b[BUF][BUF];

void read(){
  cin >> row >> col;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      cin >> b[i][j];
      
      if(b[i][j]=='E') src = Point(i,j);
      if(b[i][j]=='X') dst = Point(i,j);
    }
}

bool isInside(Point p){
  return 0<=p.r && p.r<row && 0<=p.c && p.c<col;
}

int bfs(Point init){
  queue<Point> Q;
  static int cost[BUF][BUF];
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cost[i][j] = INF;
  cost[init.r][init.c] = 0;
  
  Q.push(init);
  
  while(!Q.empty()){
    Point curr = Q.front();
    Q.pop();
    
    if(curr==dst) return cost[curr.r][curr.c];
    
    for(int i=0;i<4;i++){
      Point next = Point(curr.r+dr[i],curr.c+dc[i]);
      if(!isInside(next) || b[next.r][next.c]=='#') continue;
      if(cost[next.r][next.c]==INF){
	cost[next.r][next.c] = cost[curr.r][curr.c]+1;
	Q.push(next);
      }
    }
  }
  
  return INF;
}

int dijkstra(int toAdd[][BUF]){
  int cost[BUF][BUF], dist[BUF][BUF];
  bool visited[BUF][BUF];
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      cost[i][j] = INF;
      visited[i][j] = false;
    }

  cost[src.r][src.c] = toAdd[src.r][src.c];
  dist[src.r][src.c] = 0;

  while(true){
    Point minP;
    int minC = INF, minD = INF;
    for(int r=0;r<row;r++)
      for(int c=0;c<col;c++){
	if(!visited[r][c] && (minC>cost[r][c] || (minC==cost[r][c] && minD>dist[r][c]))){
	  minC = cost[r][c];
	  minD = dist[r][c];
	  minP = Point(r,c);
	}
      }
    if(minP==dst) return cost[dst.r][dst.c];
    visited[minP.r][minP.c] = true;

    for(int i=0;i<4;i++){
      Point next = Point(minP.r+dr[i],minP.c+dc[i]);
      if(!isInside(next) || b[next.r][next.c]=='#') continue;
      
      if(cost[next.r][next.c]>max(cost[minP.r][minP.c],dist[minP.r][minP.c]+toAdd[next.r][next.c]+1)){
	cost[next.r][next.c] = max(cost[minP.r][minP.c],dist[minP.r][minP.c]+toAdd[next.r][next.c]+1);
	dist[next.r][next.c] = dist[minP.r][minP.c]+1;
      }
    }
  }
}

void work(){
  int toAdd[BUF][BUF];

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
	toAdd[i][j] = 0;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      if(b[i][j]!='.' && b[i][j]!='E') continue;
      for(int k=0;k<4;k++){
	if(Point(i+dr[k],j+dc[k])==dst){
	  toAdd[i][j] = 1;
	  break;
	}
	if(!isInside(Point(i+dr[k],j+dc[k]))) continue;
	if(b[i+dr[k]][j+dc[k]]!='.') continue;
	
	b[i+dr[k]][j+dc[k]] = '#';
	
	toAdd[i][j] >?= bfs(Point(i,j));
	
	b[i+dr[k]][j+dc[k]] = '.';
      }
    }
  
  cout << dijkstra(toAdd) << endl;
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

