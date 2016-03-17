#include<iostream>
#include<queue>
#define cost first
#define node second
using namespace std;
const int BUF = 1005, INF = 1<<30;
typedef pair<int,int> Data;

int row, col, b[BUF][BUF];

void read(){
  cin >> row >> col;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cin >> b[i][j];
}

int rc2node(int r, int c){
  return r*col+c;
}

void node2rc(int node, int &r, int &c){
  r = node/col;
  c = node%col;
}

void work(){
  static int dr[]={-1,0,1,0},dc[]={0,1,0,-1};

  priority_queue<Data, vector<Data>, greater<Data> > Q; // (cost,node)
  static int cost[BUF][BUF];
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cost[i][j] = INF;
  cost[0][0] = b[0][0];
  Q.push(Data(0,rc2node(0,0)));
  while(!Q.empty()){
    Data data = Q.top();
    Q.pop();

    int r, c;
    node2rc(data.node,r,c);
    if(r==row-1 && c==col-1) break;
    if(cost[r][c]<data.cost) continue;

    for(int i=0;i<4;i++){
      int nr = r+dr[i], nc = c+dc[i];
      if(!(0<=nr && nr<row && 0<=nc && nc<col) ) continue;
      if(cost[nr][nc]>cost[r][c]+b[nr][nc]){
        cost[nr][nc] = cost[r][c]+b[nr][nc];
        Q.push(Data(cost[nr][nc],rc2node(nr,nc)));
      }
    }
  }
  cout  << cost[row-1][col-1] << endl;
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
