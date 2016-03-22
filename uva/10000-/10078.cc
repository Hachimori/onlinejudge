#include<iostream>
#include<cmath>

#define MAX_SIZE 55

using namespace std;

class Point{
public:

  double x,y;
  
  Point(){}
  Point(double x, double y): x(x), y(y){}

  Point operator- ( Point p ){
    return Point(x-p.x,y-p.y);
  }

  double operator* (Point p){
    return x*p.y-y*p.x;
  }

};

class Segment{
public:

  Point begin, end;

  Segment(){}
  Segment(Point b, Point e): begin(b), end(e) {}

};

int nSegment;
Segment sList[MAX_SIZE];

bool read(){

  Point pList[MAX_SIZE];

  cin >> nSegment;

  for(int i=0;i<nSegment;i++)
    cin >> pList[i].x >> pList[i].y;

  for(int i=0;i<nSegment;i++)
    sList[i] = Segment(pList[i],pList[(i+1)%nSegment]);
  
}

double side(Segment s, Point p){
  
  return (s.end-s.begin)*(p-s.begin);
  
}

void work(){
  
  for(int i=0;i<nSegment;i++){
    
    if(0>side(sList[i],sList[(i+1)%nSegment].end)*
	 side(sList[(i+1)%nSegment],sList[(i+2)%nSegment].end)){
      cout << "Yes" << endl;
      return;
    }

  }

  cout << "No" << endl;

}

int main(){

  while(read())
    work();

  return 0;
}
