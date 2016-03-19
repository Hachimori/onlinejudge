#include<iostream>
#include<cmath>
#include<queue>
#include<cfloat>
#include<algorithm>

#define INF 100000000
#define NODE 210

using namespace std;

class Point{
public:
  double x,y;

  Point(){}
  Point(double x, double y): x(x), y(y) {}
  
  double distance(Point p){
    return sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) );
  }
};

int nNode, nG, SRC, DST;
double timeLimit, speed;
int capacity[NODE][NODE];

bool read(){
  int nH;
  Point g[NODE], h[NODE];
  
  if(!(cin >> nG >> nH >> timeLimit >> speed)) return false;
  
  for(int i=0;i<nG;i++)
    cin >> g[i].x >> g[i].y;

  for(int i=0;i<nH;i++)
    cin >> h[i].x >> h[i].y;
  
  SRC = nG+nH;
  DST = nG+nH+1;
  nNode = nG+nH+2;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      capacity[i][j] = 0;
  
  for(int i=0;i<nG;i++)
    for(int j=0;j<nH;j++)
      if(g[i].distance(h[j])/speed<timeLimit)
	capacity[i][j+nG] = 1;

  for(int i=0;i<nG;i++)
    capacity[SRC][i] = 1;
  
  for(int i=0;i<nH;i++)
    capacity[i+nG][DST] = 1;

  return true;
}

bool addFlow(int pi[]){
  static int visited[NODE];  
  queue<int> Q;
  
  for(int i=0;i<nNode;i++)
    visited[i] = 0;
  visited[SRC] = INF;
  pi[SRC] = -1;
  
  Q.push(SRC);
  
  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();
    
    if(curr==DST) return true;

    for(int i=0;i<nNode;i++){
      int nextFlow = min(visited[curr],capacity[curr][i]);
      if(nextFlow==0) continue;
      
      if(visited[i]>=nextFlow) continue;
      visited[i] = nextFlow;
      pi[i] = curr;
      
      Q.push(i);
    }
  }

  return false;
}

int maximumFlow(){
  int pi[NODE], total=0;
  
  while(addFlow(pi)){
    int curr = DST, flow = INF;
    
    while(pi[curr]!=-1){
      flow = min(flow,capacity[pi[curr]][curr]);
      curr = pi[curr];
    }
    
    curr = DST;
    
    while(pi[curr]!=-1){
      capacity[pi[curr]][curr] -= flow;
      capacity[curr][pi[curr]] += flow;
      curr = pi[curr];
    }
    
    total += flow;
  }
  
  return total;
}
		 
void work(){
  cout << nG-maximumFlow() << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
