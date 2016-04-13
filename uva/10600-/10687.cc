#include<iostream>
#include<utility>
#include<algorithm>
#define POINT 1005
#define x first
#define y second
using namespace std;
typedef pair<int,int> Point;

class Data{
public:
  int dist, id;
  Point p;

  Data(){}
  Data(int d, int i, Point p): dist(d), id(i), p(p){}

  bool operator< (const Data &d) const {
    if(dist!=d.dist) return dist<d.dist;
    return p<d.p;
  }
};

int nPt;
Point pt[POINT];

bool read(){
  cin >> nPt;
  if(nPt==0) return false;

  for(int i=0;i<nPt;i++)
    cin >> pt[i].x >> pt[i].y;
  
  return true;
}

int dist(Point a, Point b){
  int dx = abs(a.x-b.x), dy = abs(a.y-b.y);
  return dx*dx+dy*dy;
}

int dfs(int cur, bool visited[POINT], bool adj[POINT][POINT]){
  visited[cur] = true;
  for(int i=0;i<nPt;i++){
    if(visited[i] || !adj[cur][i]) continue;
    dfs(i,visited,adj);
  }
}

void work(){
  bool adj[POINT][POINT];

  for(int i=0;i<nPt;i++)
    for(int j=0;j<nPt;j++)
      adj[i][j] = false;

  for(int i=0;i<nPt;i++){
    Data data[POINT];
    
    for(int j=0,k=0;j<nPt;j++){
      if(i==j) continue;
      data[k++] = Data(dist(pt[i],pt[j]),j,pt[j]);
    }

    sort(data,data+nPt-1);

    adj[i][data[0].id] = adj[i][data[1].id] = true;    
  }

  bool visited[POINT];
  for(int i=0;i<nPt;i++)
    visited[i] = false;

  dfs(0,visited,adj);

  for(int i=0;i<nPt;i++)
    if(!visited[i]){
      cout << "There are stations that are unreachable." << endl;
      return;
    }
  cout << "All stations are reachable." << endl;
}

int main(){
  while(read())
    work();
  return 0;
}
