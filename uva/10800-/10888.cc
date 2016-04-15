// weighted maximum matching
//
// min cost max flow のアルゴリズムで解いた

#include<iostream>
#include<algorithm>
#include<queue>

#define INF 10000000
#define NODE 44

using namespace std;

class Point{
public:

  int r, c;

  Point(){}
  Point(int r, int c): r(r), c(c){}
};

int nNode, SRC, DST;
int cap[NODE][NODE], cost[NODE][NODE];

bool isInside(int row, int col, Point p){
  return 0<=p.r && p.r<row && 0<=p.c && p.c<col;
}

void bfs(int sr, int sc, int row, int col, 
	 int nBox, char b[][NODE], int id[][NODE]){

  const static int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
  int visited[NODE][NODE], bId = id[sr][sc];
  queue<Point> Q;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      visited[i][j] = INF;

  visited[sr][sc] = 0;
  Q.push(Point(sr,sc));
  
  while(!Q.empty()){
    Point curr = Q.front();
    Q.pop();
    
    if(b[curr.r][curr.c]=='X'){
      cap[bId][id[curr.r][curr.c]+nBox] = 1;
      cost[bId][id[curr.r][curr.c]+nBox] =  visited[curr.r][curr.c];
      cost[id[curr.r][curr.c]+nBox][bId] = -visited[curr.r][curr.c];
    }
    
    for(int i=0;i<4;i++){
      Point next = Point(curr.r+dr[i], curr.c+dc[i]);
      if(!isInside(row,col,next)) continue;
      if(b[next.r][next.c]=='#') continue;
      if(visited[next.r][next.c]!=INF) continue;
      
      visited[next.r][next.c] = visited[curr.r][curr.c]+1;

      Q.push(next);
    }
  }
}

void construct(int row, int col, int nBox, int nGoal, char b[][NODE], int id[][NODE]){
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      if(b[i][j]!='B') continue;
      bfs(i,j,row,col,nBox,b,id);
    }

  for(int i=0;i<nBox;i++){
    cost[SRC][i] = 0;
    cap[SRC][i] = 1;
  }

  for(int i=0;i<nGoal;i++){
    cost[i+nBox][DST] = 0;
    cap[i+nBox][DST] = 1;
  }
}

void read(){
  int row, col, id[NODE][NODE], nBox = 0, nGoal = 0;
  char board[NODE][NODE];
  
  cin >> row >> col;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      id[i][j] = -1;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      cin >> board[i][j];

      if(board[i][j]=='B')
	id[i][j] = nBox++;
      if(board[i][j]=='X')
	id[i][j] = nGoal++;
    }
  
  SRC = nBox+nGoal;
  DST = nBox+nGoal+1;
  nNode = nBox+nGoal+2;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++){
      cost[i][j] = 0;
      cap[i][j] = 0;
    }
  
  construct(row,col,nBox,nGoal,board,id);
}

bool dijkstra(int pi[], int pre[]){
  static int dist[NODE];
  static bool visited[NODE];
  
  fill(dist,dist+nNode,INF);
  fill(pi,pi+nNode,-1);
  fill(visited,visited+nNode,false);
  dist[SRC] = 0;
  
  for(int j=0;j<nNode;j++){
    int curr = -1, minV = INF;
    for(int i=0;i<nNode;i++)
      if(minV>dist[i] && !visited[i]){
	minV = dist[i];
	curr = i;
      }
    
    if(curr==-1) break;
    visited[curr] = true;
    
    for(int i=0;i<nNode;i++){
      if(cap[curr][i]==0) continue;
      if(dist[i]>dist[curr]+cost[curr][i]+pre[curr]-pre[i]){
	dist[i] = dist[curr]+cost[curr][i]+pre[curr]-pre[i];
	pi[i] = curr;
      }
    }
  }
  
  for(int i=0;i<nNode;i++)
    pre[i] += dist[i];

  return pi[DST]!=-1;
}

int minCostFlow(){
  int pi[NODE], pre[NODE], sum = 0;
  
  fill(pre,pre+nNode,0);
  
  while(dijkstra(pi,pre)){
    int flow = INF;
    
    for(int i=DST;pi[i]!=-1;i=pi[i])
      flow = min(flow,cap[pi[i]][i]);

    for(int i=DST;pi[i]!=-1;i=pi[i]){
      cap[pi[i]][i] -= flow;
      cap[i][pi[i]] += flow;
    }
    
    for(int i=DST;pi[i]!=-1;i=pi[i])
      sum += cost[pi[i]][i]*flow;
  }

  return sum;
}

void work(){
  cout << minCostFlow() << endl;
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
