#include<iostream>
#include<queue>
#include<climits>

#define MAX_BUF 40000
#define MAX_SIZE 25

using namespace std;

class Node{
public:

  short cost, idx, pos;

  Node(){}
  Node(short c, short i, short p): cost(c), idx(i), pos(p){}

  bool operator< (const Node &d) const {
    return cost>d.cost;
  }
};

class Point{
public:

  int r, c;

  Point(){}
  Point(int r, int c): r(r), c(c) {}
};

int row, column, nNut;
Point pList[MAX_SIZE];
char board[MAX_SIZE][MAX_SIZE];

bool read(){
  
  if(!(cin >> row >> column)) return false;
  
  nNut = 0;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<column;j++){
      cin >> board[i][j];
      
      if(board[i][j]=='#') nNut++;
    }

  for(int i=0,idx=0;i<row;i++)
    for(int j=0;j<column;j++){
      
      
      if(board[i][j]=='#') pList[idx++] = Point(i,j);
      if(board[i][j]=='L') pList[nNut] = Point(i,j);
    }
  
  return true;
}

bool isInside(int r, int c){
  return 0<=r && r<row && 0<=c && c<column;
}

void bfs(int adjList[][MAX_SIZE], int start, int goal){
  
  static const int dr[8]={1,1,1,0,-1,-1,-1,0}, dc[8]={-1,0,1,1,1,0,-1,-1};
  queue<Point> Q;
  bool visited[MAX_SIZE][MAX_SIZE];
  int cost[MAX_SIZE][MAX_SIZE];
  
  for(int i=0;i<row;i++)
    for(int j=0;j<column;j++){
      cost[i][j] = INT_MAX;
      visited[i][j] = false;
    }

  cost[pList[start].r][pList[start].c] = 0;
  
  Q.push(pList[start]);
  
  
  while(!Q.empty()){
    
    Point curr = Q.front();
    Q.pop();
    
    if(visited[curr.r][curr.c]) continue;
    visited[curr.r][curr.c] = true;
    
    if(curr.r==pList[goal].r && curr.c==pList[goal].c){
      adjList[start][goal] = cost[pList[goal].r][pList[goal].c];
      break;
    }
    
    for(int i=0;i<8;i++){
      Point next = Point(curr.r+dr[i],curr.c+dc[i]);
      if(!isInside(next.r,next.c)) continue;
      
      if(cost[next.r][next.c]>cost[curr.r][curr.c]+1){
	cost[next.r][next.c]=cost[curr.r][curr.c]+1;
	Q.push(next);
      }
    }
  }
  
}

int cost[MAX_SIZE][MAX_BUF];

int dijkstra(int adjList[][MAX_SIZE]){
  
  int ans = INT_MAX, goal=0;
  queue<Node> Q;
  
  for(int i=0;i<nNut;i++)
    goal += 1<<i;
  
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_BUF;j++)
      cost[i][j] = INT_MAX;
  
  Q.push(Node(0,0,nNut));
  
  
  while(!Q.empty()){
    
    Node curr = Q.front();
    Q.pop();
    
    if(curr.idx==goal){
      if(ans > curr.cost+adjList[curr.pos][nNut])
	ans = curr.cost+adjList[curr.pos][nNut];
      continue;
    }
    
    if(cost[curr.pos][curr.idx]<=curr.cost) continue;
    cost[curr.pos][curr.idx] = curr.cost;
    
    for(int i=0;i<nNut;i++){
      Node next;
      
      next.cost = curr.cost+adjList[curr.pos][i];
      next.idx = curr.idx|(1<<i);
      next.pos = i;

      if(cost[i][next.idx]<=next.cost) continue;

      Q.push(next);
    }

  }  
  
  return ans;
}

void work(){
  /*
  for(int i=0;i<=nNut;i++){
    cout << pList[i].r << ' ' << pList[i].c << endl;
  }cout << endl;
  */

  int adjList[MAX_SIZE][MAX_SIZE];
  
  for(int i=0;i<=nNut;i++)
    for(int j=0;j<=nNut;j++){
      bfs(adjList,i,j);
      
      //cout << i << "->" << j << " " << adjList[i][j] << endl;
    }
  
  cout << dijkstra(adjList) << endl;

}

int main(){
  
  while(read())
    work();
  
  return 0;
}
