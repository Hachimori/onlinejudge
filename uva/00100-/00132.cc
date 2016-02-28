#include<iostream>
#include<string>
#include<cmath>
#include<cfloat>
#include<algorithm>
#include<climits>

#define MAX_SIZE 2000

using namespace std;

class Point{
public:

  double x,y;

  Point(){}
  Point(double x, double y): x(x), y(y) {}
  
  Point operator- (Point p) {
    return Point(x-p.x,y-p.y);
  }
  
  double distance(Point p){
    return sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) );
  }

  Point rotate(double rad){
    double X=x, Y=y;

    return Point(X*cos(rad)-Y*sin(rad),Y*cos(rad)+X*sin(rad));
  }
  
};

string name;
int nPoint;
Point center;
Point pList[MAX_SIZE];

bool read(){
  
  nPoint=0;


  cin >> name;
  if(name=="#") return false;

  cin >> center.x >> center.y;

  while(true){
    cin >> pList[nPoint].x >> pList[nPoint].y;
    if(pList[nPoint].x==0 && pList[nPoint].y==0) break;

    nPoint++;
  }

  return true;
}

void work(){
  
  int minPoint=INT_MAX;
  
  for(int i=0;i<nPoint;i++){
    
    Point movedCenter;
    Point movedList[MAX_SIZE];
    
    for(int j=0;j<nPoint;j++)
      if(j==i) continue;
      else 
	movedList[j] = pList[j]-pList[i];

    movedList[i] = Point(0,0);
    movedCenter = center-pList[i];
    
    for(int j=i+1;j<nPoint;j++){      

      Point rotateCenter;
      Point rotateList[MAX_SIZE];

      double dis = movedList[i].distance(movedList[j]);
      double rad = acos(1.0-Point(dis,0).distance(movedList[j])*Point(dis,0).distance(movedList[j])/(2*dis*dis));
      
      if(movedList[j].y>0) rad*=(-1);
      
      for(int k=0;k<nPoint;k++)
	rotateList[k] = movedList[k].rotate(rad);
      rotateCenter= movedCenter.rotate(rad);
      /*
      if(i==3 && j==5){
	cout << rad << endl;
	for(int k=0;k<nPoint;k++)
	  cout << movedList[k].x << ' ' << movedList[k].y << endl;
	cout << endl;
	for(int k=0;k<nPoint;k++)
	  cout << rotateList[k].x << ' ' << rotateList[k].y << endl;
	cout << endl;
	cout << movedCenter.x <<  ' ' << movedCenter.y << endl;
      cout << rotateCenter.x << ' ' << rotateCenter.y << endl;
      }
      */
      if(rotateList[j].x<rotateCenter.x) continue;
      
      bool upperExist=false, lowerExist=false;
      for(int k=0;k<nPoint;k++)
	if(rotateList[k].y<-FLT_EPSILON)
	  lowerExist=true;
	else if(rotateList[k].y>FLT_EPSILON)
	  upperExist=true;
      
      if(upperExist && lowerExist) continue;
      
      if(lowerExist)
	for(int k=0;k<nPoint;k++)
	  rotateList[k].y*=(-1);
      
      int maxVal=0;
      for(int k=0;k<nPoint;k++)
	if(fabs(rotateList[k].y)<FLT_EPSILON)
	  maxVal = max(maxVal,k+1);
      
      minPoint = min(minPoint,maxVal);
    }

  }
  
  cout << name << ' ' << minPoint << endl;
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
