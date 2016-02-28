#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
const int BUF = 35;

class Data{
public:
  int dr, dc, r, c;
  Data(){}
  Data(int dr, int dc, int r, int c): dr(dr), dc(dc), r(r), c(c){}
};

int row, col, initR, initC, goalR, goalC;
bool wall[BUF][BUF];

void read(){
  memset(wall,0,sizeof(wall));
  cin >> col >> row;
  cin >> initC >> initR >> goalC >> goalR;
  int nWall;
  cin >> nWall;
  for(int i=0;i<nWall;i++){
    int c1, r1, c2, r2;
    cin >> c1 >> c2 >> r1 >> r2;
    for(int i=r1;i<=r2;i++)
      for(int j=c1;j<=c2;j++)
        wall[i][j] = true;
  }
}


void work(){
#define access(x) (cost[x.dr+BUF][x.dc+BUF][x.r][x.c])
  queue<Data> Q;
  static int cost[BUF*2][BUF*2][BUF][BUF];

  memset(cost,-1,sizeof(cost));

  Q.push(Data(0,0,initR,initC));
  access(Data(0,0,initR,initC)) = 0;

  while(!Q.empty()){
    Data cur = Q.front();
    Q.pop();

    if(cur.r==goalR && cur.c==goalC){
      cout << "Optimal solution takes " << access(cur) << " hops." << endl;
      return;
    }

    for(int addR=-1;addR<=1;addR++)
      for(int addC=-1;addC<=1;addC++){
        Data nex = Data(cur.dr+addR,cur.dc+addC,cur.r+cur.dr+addR,cur.c+cur.dc+addC);
        if(abs(cur.dr+addR)==4 || abs(cur.dc+addC)==4) continue;
        if(!(0<=nex.r && nex.r<row && 0<=nex.c && nex.c<col)) continue;
        if(wall[nex.r][nex.c]) continue;
        if(access(nex)==-1){
          access(nex) = access(cur)+1;
          Q.push(nex);
        }
      }
  }

  cout << "No solution." << endl;
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
