#include<iostream>
#include<cassert>

#define MAX_SIZE 110

using namespace std;

class Point{
public:

  double x,y;
  
  Point(){}
  Point(double x, double y): x(x), y(y) {}
  
  Point operator- (Point p){
    return Point(x-p.x,y-p.y);
  }

  double operator* (Point p){
    return x*p.y-y*p.x;
  }

};

int nPoint;
Point pList[MAX_SIZE];

bool read(){

  cin >> nPoint;
  if(nPoint==0) return false;

  nPoint*=2;

  for(int i=0;i<nPoint;i++)
    cin >> pList[i].x >> pList[i].y;
  
  return true;
}

void work(){
  
  for(double currY=500;currY>=0;currY--){
    for(double currX=-500;currX<=500;currX++){
     
      Point currPoint=Point(currX,currY);

      int nLeft=0, nRight=0;

      for(int i=0;i<nPoint;i++){
	if(currPoint*pList[i]<0) nRight++;
	else if(currPoint*pList[i]>0) nLeft++;
	else break;
      }

      if(nLeft==nPoint/2 && nRight==nPoint/2) {
	cout << -(int)currY << " " << (int)currX << endl;
	return;
      }

    }
  }

  assert(false);

}

int main(){

  while(read())
    work();

  return 0;
}
