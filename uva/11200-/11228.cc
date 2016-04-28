#include<iostream>
#include<complex>
#define INF (1<<30)
#define BUF 1005
#define EPS 1.0e-9
#define LE(x,y) ((x)<=(y)+EPS)
using namespace std;
typedef complex<double> Point;

int nNode, allow;
Point pt[BUF];

void read(){
  cin >> nNode >> allow;

  for(int i=0;i<nNode;i++){
    double x, y; cin >> x >> y;
    pt[i] = Point(x,y);
  }
}

void dfs(int curr, bool visited[BUF]){
  visited[curr] = true;
  for(int i=0;i<nNode;i++){
    if(visited[i] || !LE(norm(pt[i]-pt[curr]),allow*allow)) continue;
    dfs(i,visited);
  }
}

void prim(double &road, double &rail){
  bool visited[BUF];
  double cost[BUF];

  for(int i=0;i<nNode;i++){
    cost[i] = INF;
    visited[i] = false;
  }
  cost[0] = 0;
  
  for(int k=0;k<nNode;k++){
    int minP = -1;
    double minV = INF;
    for(int i=0;i<nNode;i++)
      if(minV>cost[i] && !visited[i]){
        minV = cost[i];
        minP = i;
      }

    if(minP==-1) break;
    (LE(minV,allow*allow)?road:rail) += sqrt(minV);
    visited[minP] = true;

    for(int i=0;i<nNode;i++)
      if(cost[i]>norm(pt[i]-pt[minP]) && !visited[i])
        cost[i] = norm(pt[i]-pt[minP]);
  }
}

void work(int cases){
  double road = 0, rail = 0;
  prim(road,rail);
  
  int cnt = 0;
  bool visited[BUF];
  for(int i=0;i<nNode;i++) visited[i] = false;

  for(int i=0;i<nNode;i++)
    if(!visited[i]){
      dfs(i,visited);
      cnt++;
    }
  
  cout << "Case #" << cases << ": " 
       << cnt << ' ' << (int)(road+0.5) << ' ' << (int)(rail+0.5) << endl;

}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  
  return 0;
}
