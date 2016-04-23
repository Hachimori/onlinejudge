#include<iostream>
#include<cmath>
#define NODE 210
#define SRC 0
#define DST 1
#define EPS (1.0e-8)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define LE(x,y) (LT(x,y) || EQ(x,y))
using namespace std;

class Circle{
public:
  int x, y, r;

  Circle(){}
  Circle(int x, int y, int r): x(x), y(y), r(r){}
  
  double dist(Circle &c) {
    return sqrt(1.0*(x-c.x)*(x-c.x)+(y-c.y)*(y-c.y))-r-c.r;
  }
};

int limit, speed, nNode;
Circle circle[NODE];

bool read(){
  if(!(cin >> limit >> speed)) return false;

  for(int i=0;i<2;i++)
    cin >> circle[i].x >> circle[i].y >> circle[i].r;
  
  cin >> nNode;
  for(int i=2;i<nNode+2;i++)
    cin >> circle[i].x >> circle[i].y >> circle[i].r;

  nNode += 2;
  
  return true;
}

bool dfs(int curr, bool visited[], bool adj[][NODE]){
  if(curr==DST) return true;
  visited[curr] = true;

  for(int i=0;i<nNode;i++){
    if(!adj[curr][i]) continue;
    if(visited[i]) continue;
    if(dfs(i,visited,adj)) return true;
  }
  
  return false;
}

void work(){
  bool adj[NODE][NODE];
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adj[i][j] = false;
  
  for(int i=0;i<nNode;i++)
    for(int j=i+1;j<nNode;j++)
      if(LE(circle[i].dist(circle[j])/speed,limit))
	adj[i][j] = adj[j][i] = true;
      else
	adj[i][j] = adj[j][i] = false;

  bool visited[NODE];
  for(int i=0;i<nNode;i++)
    visited[i] = false;
  
  if(dfs(SRC,visited,adj))
    cout << "Larry and Ryan will escape!" << endl;
  else
    cout << "Larry and Ryan will be eaten to death." << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
