#include<iostream>
#include<cmath>
#include<cfloat>
#include<cstdio>

#define PI (acos(0.0)*2)
#define MAX_SIZE 10000

using namespace std;

class Point{
public:

  double x,y;

  Point(){}
  Point(double x, double y): x(x), y(y) {}
  
  double distance(Point p){
    return sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) );
  }
  
  //自分を中心にして b を回転,縮小した値を返す
  Point rotate(double rad, double leng, Point b){    
    double dis=b.distance(Point(x,y));
    double dx=b.x-x, dy=b.y-y;
    
    double nextX = leng*(dx/dis*cos(rad)-dy/dis*sin(rad))+x;
    double nextY = leng*(dx/dis*sin(rad)+dy/dis*cos(rad))+y;

    return Point(nextX,nextY);
  }
  
  Point operator-(Point p){
    return Point(x-p.x,y-p.y);
  }
  
  double operator*(Point p){
    return x*p.x+y*p.y;
  }
  
};

class Segment{
public:

  Point begin, end;

  Segment(){}
  Segment(Point b, Point e): begin(b), end(e) {}
};

int nPoint;
double toCut;
Point pList[MAX_SIZE];
Segment sList[MAX_SIZE];

bool read(){
  cin >> toCut >> nPoint;

  if(toCut==0 && nPoint==0) return false;

  for(int i=0;i<nPoint;i++)
    cin >> pList[i].x >> pList[i].y;
  
  for(int i=0;i<nPoint;i++)
    sList[i] = Segment(pList[i],pList[(i+1)%nPoint]);
  
  return true;
}

void work(){
  
  double toRotateRad[MAX_SIZE];
  double toMove[MAX_SIZE];
  Point rotateList[MAX_SIZE];
  
  
  for(int i=0;i<nPoint;i++){    
    double disA = pList[(i+nPoint-1)%nPoint].distance(pList[i]);
    double disB = pList[(i+1)%nPoint].distance(pList[i]);
    
    Point movedP1 = pList[(i+nPoint-1)%nPoint]-pList[i];
    Point movedP2 = pList[(i+1)%nPoint]-pList[i];
    
    toRotateRad[i] = acos(movedP1*movedP2/(disA*disB))/2;   
  }

  for(int i=0;i<nPoint;i++){
    toMove[i] = toCut/sin(toRotateRad[i]);
    //cout << toMove[i] << endl;
  }

  for(int i=0;i<nPoint;i++){
    rotateList[i] = pList[i].rotate(-toRotateRad[i],toMove[i],pList[(i+1)%nPoint]);
    //cout << rotateList[i].x << ' '<< rotateList[i].y << endl;
  }//cout << endl;
  
  double sum=0;
  for(int i=0;i<nPoint;i++)
    sum+=(rotateList[i].y+rotateList[(i+1)%nPoint].y)*(rotateList[i].x-rotateList[(i+1)%nPoint].x)/2;
  
  printf("%.3lf\n",fabs(sum));
  
}

int main(){

  while(read())
    work();

  return 0;
}
