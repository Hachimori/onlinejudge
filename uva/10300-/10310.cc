#include<iostream>
#include<cstdio>
#include<cmath>

#define MAX_SIZE 1005

using namespace std;

class Point{
public:

  double x,y;

  Point(){}
  Point(double x, double y): x(x), y(y){}

  double distance(Point p){
    return sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) );
  }
  
};

int nHole;
Point gHole, dHole;
Point holeList[MAX_SIZE];

bool read(){
  
  if(!(cin >> nHole)) return false;

  cin >> gHole.x >> gHole.y >> dHole.x >> dHole.y;

  for(int i=0;i<nHole;i++)
    cin >> holeList[i].x >> holeList[i].y;  

  return true;
}

void work(){

  for(int i=0;i<nHole;i++){
    
    if(gHole.distance(holeList[i])*2<=dHole.distance(holeList[i])){
      printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",holeList[i].x,holeList[i].y);
      return;
    }
      
    
  }

  cout << "The gopher cannot escape." << endl;
}

int main(){

  while(read())
    work();

  return 0;
}
