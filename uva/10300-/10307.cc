#include<iostream>
#include<string>
#include<queue>
#include<numeric>
#include<cctype>
#define r first
#define c second
using namespace std;
const int BUF = 105, INF = 1<<20;
typedef pair<int,int> Pos;


int row, col, id[BUF][BUF], nNode;
string b[BUF];

void read(){
  cin >> col >> row;
  getline(cin,b[0]);
  for(int i=0;i<row;i++)
    getline(cin,b[i]);

  nNode = 0;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      id[i][j] = isalpha(b[i][j]) ? nNode++ : -1;
}

void bfs(int initR, int initC, int adj[BUF][BUF]){
  int cost[BUF][BUF];
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cost[i][j] = INF;

  queue<Pos> Q;
  Q.push(Pos(initR,initC));
  cost[initR][initC] = 0;

  while(!Q.empty()){
    Pos curr = Q.front();
    Q.pop();
    static int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
    for(int i=0;i<4;i++){
      Pos next = Pos(curr.r+dr[i],curr.c+dc[i]);
      if(b[next.r][next.c]=='#') continue;
      if(cost[next.r][next.c]==INF){
        cost[next.r][next.c] = cost[curr.r][curr.c]+1;
        Q.push(next);
      }
    }
  }

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      if(id[i][j]>=0)
        adj[id[initR][initC]][id[i][j]] = adj[id[i][j]][id[initR][initC]] = cost[i][j];
}

int prim(int adj[BUF][BUF]){
  bool visited[BUF];
  int cost[BUF];

  for(int i=0;i<nNode;i++){
    visited[i] = false;
    cost[i] = INF;
  }
  
  cost[0] = 0;

  for(int k=0;k<nNode;k++){
    int minV = INF, minP;
    for(int i=0;i<nNode;i++)
      if(minV>cost[i] && !visited[i]){
        minV = cost[i];
        minP = i;
      }
    visited[minP] = true;
    for(int i=0;i<nNode;i++)
      if(cost[i]>adj[minP][i] && !visited[i])
        cost[i] = adj[minP][i];
  }

  return accumulate(cost,cost+nNode,0);
}

void work(){
  int adj[BUF][BUF];
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      if(id[i][j]>=0)
        bfs(i,j,adj);

  cout << prim(adj) << endl;
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
