#include<iostream>
#include<cstdio>
#include<cmath>
#include<complex>
using namespace std;
typedef complex<double> Point;
const double PI = acos(-1.0);

class Circle{
public:
  Point c;
  double r;
  Circle(){}
  Circle(Point c, double r): c(c), r(r){}
};

double cross(Point a, Point b){
  return imag(conj(a)*b); 
}

Circle calcCircle(Point a, Point b, Point c){
  b -= a;
  c -= a;
  Point x =  Point(b.real(),c.real());
  Point y =  Point(b.imag(),c.imag());
  Point p =  Point(norm(b),norm(c))/2.0;
  Point center = Point(cross(p,y),cross(x,p))/cross(x,y)+a;
  return Circle(center,abs(a-center));
}


Point A, B, C;

bool read(){
  double x1, y1, x2, y2, x3, y3;
  if(!(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) return false;
  A = Point(x1,y1);
  B = Point(x2,y2);
  C = Point(x3,y3);
  return true;
}


void work(){
  double ans = calcCircle(A,B,C).r*2*PI;
  printf("%.2lf\n",ans);
}


int main(){
  while(read()) work();
  return 0;
}
