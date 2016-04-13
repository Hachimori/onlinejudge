// 10610

#include<iostream>
#include<cmath>
#include<string>
#include<cstdio>
#include<climits>
#include<queue>

#define MAX_SIZE 1001

using namespace std;

class Point{
public:

  double x,y;

  Point(){}
  Point(double x, double y): x(x), y(y) {}

  double calcDistance( const Point &p){
    return sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) );
  }
  
};

int speed, minute;
int nPoint, minPointVisited;
Point goal;
Point pList[MAX_SIZE];
double adjList[MAX_SIZE][MAX_SIZE];

bool read(){
  cin >> speed >> minute;
  if(speed==0 && minute==0) return false;

  cin >> pList[0].x >> pList[0].y;
  cin >> goal.x >> goal.y;
  
  string str; getline(cin,str);

  for(int i=1;;i++){ 
    getline(cin,str);
    nPoint = i;
    if(str.empty()) break;

    sscanf(str.c_str(),"%lf %lf",&pList[i].x,&pList[i].y);
  }

  return true;
}

void bfs(){
  
  queue<int> Q;
  bool visited[MAX_SIZE];
  int nVisited[MAX_SIZE];
  
  for(int i=0;i<nPoint;i++){
    visited[i] = false;
    nVisited[i] = INT_MAX;
  }

  Q.push(0);
  nVisited[0] = 0;

  while(!Q.empty()){

    int curr= Q.front();
    Q.pop();

    if(visited[curr]) continue;
    visited[curr] = true;

    for(int i=0;i<nPoint;i++){
      if(visited[i]) continue;
      if(!(speed*minute*60>=adjList[curr][i])) continue;
      
      if(nVisited[i]>nVisited[curr]+1){
	Q.push(i);
	nVisited[i] = nVisited[curr]+1;
      }      
    }

    if(speed*minute*60>=pList[curr].calcDistance(goal)){
      minPointVisited = nVisited[curr]+1;
      return;
    }

  }


}

void work(){
  /*
  for(int i=0;i<nPoint;i++){
    cout << pList[i].x << ' ' << pList[i].y << endl;
  }
  */
  
  minPointVisited=INT_MAX;

  for(int i=0;i<nPoint;i++)
    for(int j=0;j<nPoint;j++)
      adjList[i][j] = pList[i].calcDistance(pList[j]);

  bfs();
 
  if(minPointVisited==INT_MAX){
    cout << "No." << endl;
  }
  else {
    cout << "Yes, visiting "<< minPointVisited-1 << " other holes." << endl;
  }
 
}

int main(){
  
  while(read())
    work();

  return 0;
}
