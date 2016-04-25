#include<iostream>
#include<queue>
#include<algorithm>

#define NORTH 1
#define EAST 2
#define SOUTH 4
#define WEST 8
#define SIZE 6

using namespace std;

class Point{
public:
  int r, c;

  Point(){}
  Point(int r, int c): r(r), c(c){}
};

Point bgn, end;
int wall[SIZE][SIZE];

bool isInside(int r, int c){
  return 0<=r && r<SIZE && 0<=c && c<SIZE;
}

bool read(){
  cin >> bgn.c >> bgn.r;
  if(bgn.r==0 && bgn.c==0) return false;  
  bgn.c--, bgn.r--;

  cin >> end.c >> end.r;
  end.c--, end.r--;

  for(int i=0;i<SIZE;i++)
    for(int j=0;j<SIZE;j++)
      wall[i][j] = 0;
  
  for(int i=0;i<3;i++){
    Point b, e;
    cin >> b.c >> b.r >> e.c >> e.r;
    
    if(b.r==e.r){
      for(int i=min(b.c,e.c);i<max(b.c,e.c);i++){
	wall[b.r][i] |= NORTH;
	if(isInside(b.r-1,i))
	   wall[b.r-1][i] |= SOUTH;
      }
    }
    else{
      for(int i=min(b.r,e.r);i<max(b.r,e.r);i++){
	wall[i][b.c] |= WEST;
	if(isInside(i,b.c-1))
	   wall[i][b.c-1] |= EAST;
      }
    }
  }
  
  return true;
}

void bfs(vector<int> &path){
  bool visited[SIZE][SIZE];
  int pi[SIZE][SIZE];
  const static int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
  queue<Point> Q;
  
  for(int i=0;i<SIZE;i++)
    for(int j=0;j<SIZE;j++)
      visited[i][j] = false;
  
  pi[bgn.r][bgn.c] = -1;
  visited[bgn.r][bgn.c] = true;
  Q.push(bgn);
  
  while(!Q.empty()){
    Point curr = Q.front();
    Q.pop();

    if(curr.r==end.r && curr.c==end.c) break;
    
    for(int i=0;i<4;i++){
      Point next = Point(curr.r+dr[i],curr.c+dc[i]);
      if(!isInside(next.r,next.c)) continue;
      if(visited[next.r][next.c]) continue;
      if((wall[curr.r][curr.c]&(1<<i))!=0) continue;
      
      visited[next.r][next.c] = true;
      pi[next.r][next.c] = i;

      Q.push(next);
    }
  }
  
  Point curr = end;
  while(pi[curr.r][curr.c]!=-1){
    path.push_back(pi[curr.r][curr.c]);
    
    int t = pi[curr.r][curr.c];
    curr.r -= dr[t];
    curr.c -= dc[t];
  }

  reverse(path.begin(),path.end());
}

void work(){
  vector<int> path;
  
  bfs(path);

  for(int i=0;i<path.size();i++){
    switch(path[i]){
    case 0: cout << 'N'; break;
    case 1: cout << 'E'; break;
    case 2: cout << 'S'; break;
    case 3: cout << 'W'; break;
    }
  }
  cout << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
