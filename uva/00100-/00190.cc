// uva 190

#include<iostream>
#include<cstdio>
#include<complex>
#include<algorithm>
#include<cassert>

using namespace std;

#define PI acos(-1.0)
#define EPS (1.0e-9)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define LE(x,y) (LT(x,y) || EQ(x,y))

typedef complex<double> Point;

class Segment{
public:
  Point bgn, end;

  Segment(){}
  Segment(Point b, Point e): bgn(b),  end(e){}
};

class Circle{
public:
  Point c;
  double r;
  
  Circle(){}
  Circle(Point c, double r): c(c), r(r){}
};

Point pp1, pp2, pp3;

bool read(){
  double x1, x2, x3, y1, y2, y3;
  if(!(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) return false;

  pp1 = Point(x1,y1), pp2 = Point(x2,y2), pp3 = Point(x3,y3);
  
  return true;
}

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

Point rotate(Point p){
  return Point(-p.imag(),p.real());
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

Circle calcCircle(Point p1, Point p2, Point p3){
  assert(!EQ(cross(p2-p1,p3-p1),0));
  
  Point mid1 = (p1+p2)/2.0;
  Point mid2 = (p1+p3)/2.0;
  Segment s1 = Segment(mid1,mid1+rotate(p2-p1));
  Segment s2 = Segment(mid2,mid2+rotate(p3-p1));
  
  Point center = calcIntersect(s1,s2);
  
  return Circle(center,abs(p1-center));
}

void work(){
  Circle c = calcCircle(pp1,pp2,pp3);
  
  cout << "(x";
  if(LE(c.c.real(),0))
    printf(" + %.3lf",-c.c.real()+EPS);
  else
    printf(" - %.3lf",c.c.real()+EPS);
  
  cout << ")^2 + (y";
  if(LE(c.c.imag(),0))
    printf(" + %.3lf",-c.c.imag()+EPS);
  else
    printf(" - %.3lf",c.c.imag()+EPS);
  
  printf(")^2 = %.3lf^2\n",c.r+EPS);

  cout << "x^2 + y^2";
  if(LE(c.c.real(),0))
    printf(" + %.3lfx",-2*c.c.real()+EPS);
  else
    printf(" - %.3lfx",2*c.c.real()+EPS);

  if(EQ(c.c.imag(),0) || c.c.imag()<0)
    printf(" + %.3lfy",-2*c.c.imag()+EPS);
  else
    printf(" - %.3lfy",2*c.c.imag()+EPS);
  
  double toPrint = c.c.real()*c.c.real()+c.c.imag()*c.c.imag()-c.r*c.r;
  if(LE(toPrint,0))
    printf(" - %.3lf = 0\n",-toPrint+EPS);
  else
    printf(" + %.3lf = 0\n",toPrint+EPS);
}

int main(){
  while(read()){
    work();
    cout << endl;
  }

  return 0;
}
