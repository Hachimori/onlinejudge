#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cassert>

#define RANGE 2002
#define INF 2000000000
#define POINT 300000

using namespace std;

class Point{
public:
  int c, r;
  
  Point(){}
  Point(int c, int r): c(c), r(r){}
};

Point init[POINT];
int nInit;
bool goal[RANGE][RANGE];

bool read(){
  for(int i=0;i<RANGE;i++)
    fill(goal[i],goal[i]+RANGE,false);
  
  for(int i=0;i<2;i++){
    int nPoint;
    cin >> nPoint;
    if(nPoint==0) return false;
    if(i==0) nInit = nPoint;
    for(int j=0;j<nPoint;j++){
      int c, r;
      scanf("%d%d",&c,&r);
      goal[r][c] = true;
      if(i==0){ 
	init[j].c = c;
	init[j].r = r;
      }
    }
  }
  
  return true;
}

bool isInside(int &c, int &r){
  return 0<=c && c<RANGE && 0<=r && r<RANGE;
}

int bfs(){
  static const int dc[]={0,1,0,-1}, dr[]={1,0,-1,0};
  static int visited[RANGE][RANGE];
  queue<Point> Q;
  
  for(int i=0;i<RANGE;i++)
    fill(visited[i],visited[i]+RANGE,INF);
  for(int i=0;i<nInit;i++){
    Q.push(init[i]);
    visited[init[i].r][init[i].c] = 0;
  }
  
  while(!Q.empty()){
    Point curr = Q.front();
    Q.pop();
    
    for(int i=0;i<4;i++){
      Point next = Point(curr.c+dc[i],curr.r+dr[i]);
      if(!isInside(next.c,next.r)) continue;
      if(visited[next.r][next.c]!=INF) continue;
      if(goal[next.r][next.c]) return visited[curr.r][curr.c]+1;

      Q.push(next);
      visited[next.r][next.c] = visited[curr.r][curr.c]+1;
    }
  }
}

void work(){
  cout << bfs() << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
