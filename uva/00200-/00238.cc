// BFS
// 
// 問題文に曖昧な点がある。
// 
// 1. Avoid any travel of more than 10 meters between adjacent grid points.
// とは、二点の"高さの差"が10より大きければ、その間を通過できないということ。
//
// 3. Always travel the shortest possible route. 
// とは、"ノードを辿った回数"を最小にしろ、ということ。
//
// Output a blank line between each output for query. 
// とあるが、異なるテストケース間に空行を入れる必要がある。

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define LIMIT 10
#define INF 10000000
#define MAX_QUEUE 10000
#define MAX_SIZE 23

using namespace std;

class Point{
public:
  int r, c;

  Point(){}
  Point(int r, int c): r(r), c(c){}
};

int row, column, nQuery;
int height[MAX_SIZE][MAX_SIZE];
vector<Point> adjList[MAX_SIZE][MAX_SIZE];
Point query[MAX_QUEUE][2];

bool read(){
  for(int i=0;i<row;i++)
    for(int j=0;j<column;j++)
      adjList[i][j].clear();
  
  if(!(cin >> row >> column)) return false;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<column;j++)
      cin >> height[i][j];
  
  while(true){
    int sr, sc, tr, tc;
    cin >> sr >> sc >> tr >> tc;
    if(sr==0 && sc==0 && tr==0 && tc==0) break;
    sr--, sc--, tr--, tc--;
    
    int dr, dc;
    if(sr!=tr){
      if(sr<tr)
	dr = 1;
      else
	dr = -1;
      dc = 0;
    }
    else if(sc!=tc){
      if(sc<tc)
	dc = 1;
      else
	dc = -1;
      dr = 0;
    }
    
    if(dr==0)
      for(int i=sc;i!=tc;i+=dc)
	adjList[sr][i].push_back(Point(sr,i+dc));
    else
      for(int i=sr;i!=tr;i+=dr)
	adjList[i][sc].push_back(Point(i+dr,sc));
  }
  
  nQuery = 0;
  while(true){
    cin >> query[nQuery][0].r >> query[nQuery][0].c
	>> query[nQuery][1].r >> query[nQuery][1].c;

    if(query[nQuery][0].r==0 && query[nQuery][0].c==0 &&
       query[nQuery][1].r==0 && query[nQuery][1].c==0 ) break;

    query[nQuery][0].r--;
    query[nQuery][0].c--;
    query[nQuery][1].r--;
    query[nQuery][1].c--;

    nQuery++;
  }
  
  return true;
}

void dijkstra(Point start, Point goal){
  double cost[MAX_SIZE][MAX_SIZE];
  bool visited[MAX_SIZE][MAX_SIZE];
  Point pi[MAX_SIZE][MAX_SIZE];

  if(start.r==goal.r && start.c==goal.c){
    cout << "To get from " << start.r+1 << '-' << start.c+1 << " to "
	 << goal.r+1 << '-' << goal.c+1 << ", stay put!" << endl;
    return;
  }

  for(int i=0;i<row;i++)
    for(int j=0;j<column;j++){
      cost[i][j] = INF;
      visited[i][j] = false;
      pi[i][j] = Point(-1,-1);
    }
  
  cost[start.r][start.c] = 0;

  for(int i=0;i<row*column;i++){
    double minVal = INF;
    Point minPos = Point(-1,-1);
    
    for(int j=0;j<row;j++)
      for(int k=0;k<column;k++)
	if(minVal>cost[j][k] && !visited[j][k]){
	  minVal = cost[j][k];
	  minPos = Point(j,k);
	}

    if(minPos.r==-1) break;
    visited[minPos.r][minPos.c] = true;

    for(int j=0;j<adjList[minPos.r][minPos.c].size();j++){
      Point next = adjList[minPos.r][minPos.c][j];
      int dh = height[minPos.r][minPos.c]-height[next.r][next.c];
      if(abs(dh)>LIMIT) continue;
      
      if(cost[next.r][next.c]>minVal+1){
	cost[next.r][next.c] = minVal+1;
	pi[next.r][next.c] = minPos;
      }
    }
  }
  
  if(pi[goal.r][goal.c].r==-1){
    cout << "There is no acceptable route from " 
	 << start.r+1 << '-' << start.c+1 << " to " 
	 << goal.r+1 << '-' << goal.c+1 << '.' << endl;
    return;
  }

  Point curr = goal;
  vector<Point> path;

  while(curr.r!=-1){
    path.push_back(curr);
    curr = pi[curr.r][curr.c];
  }

  reverse(path.begin(),path.end());

  for(int i=0;i<path.size();i++){
    if(i!=0) cout << " to ";
    cout << path[i].r+1 << '-' << path[i].c+1;
  }cout << endl;
}

void work(){
  for(int i=0;i<nQuery;i++){
    if(i!=0) cout << endl;
    dijkstra(query[i][0],query[i][1]);
  }
}

int main(){
  for(int i=0;read();i++){
    if(i!=0) cout << endl;
    work();
  }

  return 0;
}
