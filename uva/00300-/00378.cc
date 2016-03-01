#include<iostream>
#include<complex>
#include<cstdio>
#include<cfloat>

#define EPS FLT_EPSILON

using namespace std;

typedef complex<double> Point;

class Segment{
public:

  Point bgn, end;
  
  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

Segment s1, s2;

void read(){
  double x1,y1,x2,y2,x3,y3,x4,y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  
  s1 = Segment(Point(x1,y1),Point(x2,y2));
  s2 = Segment(Point(x3,y3),Point(x4,y4));
}

double cross(Point a, Point b){
  return imag(conj(b)*a);
}

double cross(Point a, Point b, Point o){
  return imag(conj(b-o)*(a-o));
}

bool isParallel(Segment a, Segment b){
  double dx1, dy1, dx2, dy2;
  
  dx1 = a.end.real()-a.bgn.real();
  dx2 = b.end.real()-b.bgn.real();
  dy1 = a.end.imag()-a.bgn.imag();
  dy2 = b.end.imag()-b.bgn.imag();

  return (fabs(dx1*dy2-dx2*dy1)<EPS);
}

bool isOnline(Segment a, Segment b){
  double dx1, dy1, dx2, dy2;
  
  dx1 = a.bgn.real()-a.end.real();
  dx2 = b.bgn.real()-a.bgn.real();
  dy1 = a.bgn.imag()-a.end.imag();
  dy2 = b.bgn.imag()-a.bgn.imag();
  
  return fabs(dy1*dx2-dx1*dy2)<FLT_EPSILON;  
}

Point calcIntersect(Segment a, Segment b){
  double cross1 = cross(a.bgn,a.end);
  double cross2 = cross(b.bgn,b.end);

  a.bgn -= a.end;
  b.bgn -= b.end;

  double toDiv = cross(a.bgn,b.bgn);
  
  double x = (cross1*b.bgn.real()-cross2*a.bgn.real())/toDiv;
  double y = (cross1*b.bgn.imag()-cross2*a.bgn.imag())/toDiv;

  return Point(x,y);
}

void makeLong(Segment &s){
  double dx = s.end.real()-s.bgn.real(), dy = s.end.imag()-s.bgn.imag();
  
  s.bgn -= Point(dx*1000,dy*1000);
  s.end += Point(dx*1000,dy*1000);
}

void work(){
  makeLong(s1);
  makeLong(s2);

  if(isParallel(s1,s2)){
    if(isOnline(s1,s2))
      cout << "LINE" << endl;
    else
      cout << "NONE" << endl;
    
    return;
  }

  Point p = calcIntersect(s1,s2);
  printf("POINT %.2lf %.2lf\n",p.real(),p.imag());
}

int main(){
  cout << "INTERSECTING LINES OUTPUT" << endl;
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  cout << "END OF OUTPUT" << endl;
  return 0;
}
