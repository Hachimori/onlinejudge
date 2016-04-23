#include<iostream>
#include<queue>
#define INF 100000000
#define BUF 205
using namespace std;

class Pos{
public:
  int r, c;
  
  Pos(){}
  Pos(int r, int c): r(r), c(c){}
};

int row, col;
bool wall[BUF][BUF];

bool read(){
  cin >> row >> col;
  if(row==0 && col==0) return false;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      wall[i][j] = false;
  
  int nWall;
  cin >> nWall;
  
  for(int i=0;i<nWall;i++){
    int r, c;
    cin >> r >> c;
    wall[r-1][c-1] = true;
  }
  
  int nJig;
  cin >> nJig;
  
  for(int i=0;i<nJig;i++){
    int r, c, l;
    cin >> r >> c >> l;
    r--, c--;

    for(int rr=0;rr<row;rr++)
      for(int cc=0;cc<col;cc++)
	if((rr-r)*(rr-r)+(cc-c)*(cc-c)<=l*l)
	  wall[rr][cc] = true;
  }

  return true;
}

bool isInside(Pos p){
  return 0<=p.r && p.r<row && 0<=p.c && p.c<col;
}

int bfs(){
  const static int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
  int cost[BUF][BUF];
  queue<Pos> Q;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cost[i][j] = INF;
  cost[0][0] = 0;
  Q.push(Pos(0,0));
  
  while(!Q.empty()){
    Pos curr = Q.front();
    Q.pop();

    for(int i=0;i<4;i++){
      Pos next = Pos(dr[i]+curr.r,dc[i]+curr.c);
      if(!isInside(next)) continue;
      if(wall[next.r][next.c]) continue;
      
      if(cost[next.r][next.c]>cost[curr.r][curr.c]+1){
	cost[next.r][next.c] = cost[curr.r][curr.c]+1;
	Q.push(next);
      }
    }
  }
  
  return cost[row-1][col-1];
}

void work(){
  int ans;
  if((ans=bfs())==INF) cout << "Impossible." << endl;
  else  cout << ans << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
