#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<algorithm>

#define MAX_NODE 751

using namespace std;

class Point{
public:

  int x,y;
  
  Point(){}
  
  double calcDistance(const Point &p){
    return sqrt( (double)((p.x-x)*(p.x-x) + (p.y-y)*(p.y-y)) );
  }
  
};

double adjList[MAX_NODE][MAX_NODE];
int nNode;

bool read(){
  
  Point pList[MAX_NODE];

  if(!(cin >> nNode)) return false;

  for(int i=0;i<nNode;i++)
    cin >> pList[i].x >> pList[i].y;
  
  for(int i=0;i<nNode;i++)
    for(int j=i;j<nNode;j++){
      adjList[i][j] = pList[i].calcDistance(pList[j]);
      adjList[j][i] = pList[i].calcDistance(pList[j]);
    }

  int nExist;
  cin >> nExist;
  for(int i=0;i<nExist;i++){
    int source, target;
    cin >> source >> target;
    adjList[source-1][target-1] = 0.0;
    adjList[target-1][source-1] = 0.0;
  }
  
  return true;
}

void mst(){

  bool visited[MAX_NODE];
  double total=0;
  double connected[MAX_NODE];

  for(int i=0;i<nNode;i++){
    visited[i] = false;
    connected[i] = INT_MAX;
  }

  int nConnected=0;
  connected[0] = 0;

  while(nConnected!=nNode){

    double minLeng=INT_MAX;
    int minPos;
    for(int i=0;i<nNode;i++)
      if(!visited[i] && minLeng>connected[i]){
	minLeng = connected[i];
	minPos = i;
      }
    
    total+=connected[minPos];
    visited[minPos] = true;

    for(int i=0;i<nNode;i++){
      if(minPos==i || visited[i]) continue;
      connected[i] = min(adjList[minPos][i],connected[i]);
    }
    nConnected++;
  }
  
  printf("%.2f\n",total);

}

void work(){
  
  mst();

}

int main(){

  while(read())
    work();

  return 0;
}
