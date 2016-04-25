// Memorize
//
// 
// ある頂点にどのくらいのコストで辿り着いたかという状態を記憶しておく。
// 同じ頂点に同じコストで辿り着いたとき,処理を省く。

#include<iostream>
#include<cstdlib>
#include<queue>
#include<set>

#define WALL 100000
#define MAX_BUF 200
#define SHIFT 100
#define MAX_SIZE 100

using namespace std;

class Data{
public:

  int r,c, cost;
  
  Data(){}
  Data(int r, int c, int cost): r(r), c(c), cost(cost){}
};


int size;
int board[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][MAX_BUF];

bool read(){
  cin >> size;
  if(size==0) return false;
  
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++)
      board[i][j] = WALL;
    for(int j=size-i-1;j<size;j++)
      cin >> board[i][j];
  }
  
  for(int i=0;i<size-1;i++){
    for(int j=0;j<size;j++)
      board[i+size][j] = WALL;
    for(int j=0;j<size-i-1;j++)
      cin >> board[i+size][j];
  }
  
  return true;
}

bool isInside(int r, int c){
  return 0<=r && r<size*2-1 && 0<=c && c<size;
}

bool isInsideBuf(int cost){
  return 0<=cost && cost<MAX_BUF;
}

bool &access(int i, int j, int k){
  return visited[i][j][k+SHIFT];
}

void bfs(){
  static const int dr[2]={-1,-1}, dc[2]={0,1};
  queue<Data> Q;
    
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++)
      for(int k=0;k<MAX_BUF;k++)
	visited[i][j][k] = false;

  //cost[size*2-2][0].insert(board[size*2-2][0]);
  Q.push(Data(size*2-2,0,board[size*2-2][0]));
  Q.push(Data(size*2-2,0,-board[size*2-2][0]));
  
  while(!Q.empty()){
    Data curr = Q.front();
    Q.pop();

    if(access(curr.r,curr.c,curr.cost))
      continue;
    access(curr.r,curr.c,curr.cost) = true;
    
    for(int i=0;i<2;i++){
      Data next = curr;
      
      next.r += dr[i];
      next.c += dc[i];
    
      if(!isInside(next.r,next.c)) continue;
      if(board[next.r][next.c]==WALL) continue;

      next.cost = curr.cost + board[next.r][next.c];

      if(!isInsideBuf(next.cost)) continue;

      if(!access(next.r,next.c,next.cost))
	Q.push(next);

      next.cost = curr.cost - board[next.r][next.c];
      if(!access(next.r,next.c,next.cost))
	Q.push(next);
    }
  }
  
  int score = WALL;
  for(int i=0;i<MAX_BUF;i++){
    if(access(0,size-1,i) && abs(score)>abs(i-SHIFT))
      score = i;
  }
  cout << score << endl;
}

void work(){
  bfs();
}

int main(){
  while(read())
    work();
  
  return 0;
}
