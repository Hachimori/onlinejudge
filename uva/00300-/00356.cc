#include<iostream>
#include<cmath>

using namespace std;

class Point{
public:

  int x,y;

  Point(){}
  Point(int x, int y): x(x), y(y){}
  
  double calcDis(Point p){
    return sqrt( (double)((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y)) );
  }

};

int nGrid;

bool read(){
  if(!(cin >> nGrid)) return false;
  return true;
}

void work(){
  
  Point center=Point(0,0);
  int nFrame=0, nContain=0;
  
  for(int currY=nGrid;currY>-nGrid;currY--){
    for(int currX=-nGrid;currX<nGrid;currX++){
      
      int nPointContain=0;

      if(Point(currY,currX).calcDis(center)<nGrid-0.5) nPointContain++;
      if(Point(currY-1,currX).calcDis(center)<nGrid-0.5) nPointContain++;
      if(Point(currY,currX+1).calcDis(center)<nGrid-0.5) nPointContain++;
      if(Point(currY-1,currX+1).calcDis(center)<nGrid-0.5) nPointContain++;

      if(nPointContain==4) nContain++;
      else if(nPointContain>0) nFrame++;
    }
  }

  
  cout << "In the case n = " << nGrid << ", " << nFrame 
       << " cells contain segments of the circle." << endl 
       << "There are " << nContain 
       << " cells completely contained in the circle." << endl ;
  
}

int main(){

  for(int i=0;read();i++){
    if(i!=0) cout << endl;
    work();
  }

  return 0;
}
