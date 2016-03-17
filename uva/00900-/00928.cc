#include<iostream>
#include<string>
#include<queue>
#define r first
#define c second
using namespace std;
const int BUF = 305;
typedef pair<int,int> Point;

class Data{
public:
  int mov, r, c;
  Data(){}
  Data(int m, int r, int c): mov(m), r(r), c(c){}
};

int row, col;
Point init, goal;
bool wall[BUF][BUF];


void read(){
  cin >> row >> col;
  for(int i=0;i<row;i++){
    string s;
    cin >> s;
    for(int j=0;j<col;j++){
      wall[i][j] = s[j]=='#';
      if(s[j]=='S') init = Point(i,j);
      if(s[j]=='E') goal = Point(i,j);
    }
  }
}


bool isInside(int r, int c){
  return 0<=r && r<row && 0<=c && c<col;
}


void work(){
  static int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
  static int cost[3][BUF][BUF];
  memset(cost,-1,sizeof(cost));
  
  cost[0][init.r][init.c] = 0;

  queue<Data> Q;
  Q.push(Data(0,init.r,init.c));

  while(!Q.empty()){
    Data cur = Q.front();
    Q.pop();

    if(Point(cur.r,cur.c)==goal){
      cout << cost[cur.mov][cur.r][cur.c] << endl;
      return;
    }

    for(int dir=0;dir<4;dir++){
      bool ok = true;
      for(int toMov=1;toMov<=cur.mov+1;toMov++){
        int nr = cur.r+toMov*dr[dir], nc = cur.c+toMov*dc[dir];
        if(!isInside(nr,nc) || wall[nr][nc]) ok = false;
      }
      if(!ok) continue;

      Data nex = Data((cur.mov+1)%3,cur.r+(cur.mov+1)*dr[dir],cur.c+(cur.mov+1)*dc[dir]);
      if(cost[nex.mov][nex.r][nex.c]==-1){
        cost[nex.mov][nex.r][nex.c] = cost[cur.mov][cur.r][cur.c]+1;
        Q.push(nex);
      }
    }
  }

  cout << "NO" << endl;
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
