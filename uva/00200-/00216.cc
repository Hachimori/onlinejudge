#include<iostream>
#include<cmath>
#include<climits>
#include<cstdio>

#define MAX_NODE 9

using namespace std;

class Point{
public:

  int x,y;

  Point(){}
  Point(int x, int y): x(x), y(y){}

  double calcDis(const Point &p){
    return sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) );
  }
};

int nNode, startPos, minPi[MAX_NODE];
Point pointList[MAX_NODE];
double adjList[MAX_NODE][MAX_NODE];
double minDis;

bool read(){

  cin >> nNode;
  if(nNode==0) return false;

  for(int i=0;i<nNode;i++)
    cin >> pointList[i].x >> pointList[i].y;

  for(int i=0;i<nNode;i++){
    for(int j=0;j<nNode;j++){
      adjList[i][j] = pointList[i].calcDis(pointList[j])+16;

      //cout << adjList[i][j] << ' ';
    }//cout << endl;
    //cout << endl;
  }

  return true;

}

void dfs(int start, int curr, int nVisited, double currDis, bool visited[MAX_NODE], int pi[MAX_NODE]){
  /*
    for(int i=0;i<nNode;i++)
    cout << pi[i] << ' ';
  cout << endl;
  */

  if(nVisited==nNode-1){
    
    pi[curr] = -1;
    
    if(minDis>currDis){
      for(int i=0;i<nNode;i++)
	minPi[i] = pi[i];
      minDis = currDis;
      startPos = start;
    }

    return;
  }


  for(int i=0;i<nNode;i++){
    if(visited[i]) continue;
    
    visited[i] = true;
    pi[curr] = i;

    dfs(start,i,nVisited+1,currDis+adjList[curr][i],visited,pi);
    
    visited[i] = false;
    
  }

}

void work(int cases){
  
  bool visited[MAX_NODE];
  int pi[MAX_NODE];


  minDis = INT_MAX;
  for(int i=0;i<nNode;i++)
    visited[i] = false;
  
  
  for(int i=0;i<nNode;i++){
    visited[i] = true;
    dfs(i,i,0,0,visited,pi);
    visited[i] =false;
  }

  /*
  for(int i=0;i<nNode;i++)
    cout << minPi[i] << ' ';
  cout << endl;
  */       
  cout << "**********************************************************" << endl;
  cout << "Network #" << cases << endl;
  
  for(int i=startPos;minPi[i]!=-1;i=minPi[i]){
    printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",
	   pointList[i].x,pointList[i].y,pointList[minPi[i]].x,pointList[minPi[i]].y,
	   pointList[i].calcDis(pointList[minPi[i]])+16);

  }
  printf("Number of feet of cable required is %.2f.\n",minDis);
  
}

int main(){
  
  for(int i=1;read();i++)
    work(i);

  return 0;
}
