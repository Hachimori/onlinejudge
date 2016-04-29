#include<iostream>
#include<queue>
#define r first
#define c second 
using namespace std;
typedef pair<int,int> Point;
const int BUF = 105;

int row, col, initR, initC, goalR, goalC;
char b[BUF][BUF];

void read(){
  cin >> row >> col;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      cin >> b[i][j];
      if(b[i][j]=='A') initR = i, initC = j;
      if(b[i][j]=='B') goalR = i, goalC = j;
    }
}

bool isInside(Point p){
  return 0<=p.r && p.r<row && 0<=p.c && p.c<col;
}

void work(){
  int zdr[]={-2,-2,-1,1,2,2,1,-1},zdc[]={-1,1,2,2,1,-1,-2,-2};
  int kdr[]={-1,-1,-1,0,1,1,1,0},kdc[]={-1,0,1,1,1,0,-1,-1};
  queue<Point> Q;
  int visited[BUF][BUF];

  memset(visited,-1,sizeof(visited));
  Q.push(Point(initR,initC));
  visited[initR][initC] = 0;

  while(!Q.empty()){
    Point cur = Q.front();
    Q.pop();
    for(int i=0;i<8;i++){
      Point nex = Point(cur.r+kdr[i],cur.c+kdc[i]);
      if(!isInside(nex)) continue;
      if(nex==Point(goalR,goalC)){
        cout << "Minimal possible length of a trip is " << visited[cur.r][cur.c]+1 << endl;
        return;
      }
      for(int r=0;r<row;r++)
        for(int c=0;c<col;c++)
          if(b[r][c]=='Z')
            for(int j=0;j<8;j++){
              Point nexZ = Point(r+zdr[j],c+zdc[j]);
              if(nexZ==nex) goto _fail;
            }
      if(b[nex.r][nex.c]=='.' && visited[nex.r][nex.c]==-1){
        visited[nex.r][nex.c] = visited[cur.r][cur.c]+1;
        Q.push(nex);
      }
    _fail:;
    }
  }
  cout << "King Peter, you can't go now!" << endl;
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
