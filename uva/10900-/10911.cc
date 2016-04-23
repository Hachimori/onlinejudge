#include<iostream>
#include<queue>
#include<map>
#include<complex>
#include<cmath>
#include<cstdio>
#define NODE 20
#define BUF (1<<NODE)
#define INF (1<<30)
using namespace std;
typedef complex<double> Point;

int nNode;
double adj[NODE][NODE];

bool read(){
  cin >> nNode;
  if(nNode==0) return false;
  nNode *= 2;
  
  Point pt[NODE];
  for(int i=0;i<nNode;i++){
    char dummy[1000];
    double x, y;
    cin >> dummy >> x >> y;
    pt[i] = Point(x,y);
  }
  
  for(int i=0;i<nNode;i++){
    for(int j=i+1;j<nNode;j++)
      adj[i][j] = adj[j][i] = abs(pt[i]-pt[j]);
    adj[i][i] = 0;
  }
  
  return true;
}

double calc(){
  static double cost[BUF];
  queue<int> Q;
  
  for(int i=0;i<(1<<nNode);i++) cost[i] = INF;
  cost[0] = 0;
  Q.push(0);

  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();
    
    for(int i=0;i<nNode;i++)
      if((curr&(1<<i))==0)
	for(int j=i+1;j<nNode;j++) {
	  if(curr&(1<<j)) continue;
	  int next = curr|(1<<i)|(1<<j);
	  if(cost[next]==INF) Q.push(next);
	  cost[next] = min(cost[next],cost[curr]+adj[i][j]);
	}
  }

  return cost[(1<<nNode)-1];
}

void work(int cases){
  printf("Case %d: %.2lf\n",cases,calc());
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
