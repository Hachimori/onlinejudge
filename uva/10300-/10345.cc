#include<iostream>
#include<complex>
#include<cmath>
using namespace std;
typedef complex<double> Point;

class Segment{
public:
  Point bgn, end;
  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

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

Point calcCircle(Point a, Point b, Point c){
  Point mid1 = (a+b)/2.0;
  Point mid2 = (a+c)/2.0;
  Segment s1 = Segment(mid1,mid1+rotate(b-a));
  Segment s2 = Segment(mid2,mid2+rotate(c-a));
  return calcIntersect(s1,s2);
}

double a;

void read(){
  cin >> a;
}

double dist(double x1, double y1, double x2, double y2){
  return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void work(){
  double ans[6];
  ans[0] = a/sqrt(2.0);
  ans[1] = sqrt(5.0)*a/2;
  
  double L = 0, R = a;
  for(int i=0;i<1000;i++){
    double mid = (L+R)/2;
    if(dist(0,0,a,mid)<dist(a/2,2*a,a,mid))
      L = mid;
    else
      R = mid;
  }
  ans[2] = sqrt(dist(0,0,a,(L+R)/2));

  ans[3] = sqrt(2.0)*a;
  ans[4] = sqrt(10.0)*a/2;
  
  L = 0, R = a/2;
  for(int i=0;i<1000;i++){
    double mid = (L+R)/2;

    Point center1 = calcCircle(Point(0,0),Point(a,-a),Point(mid,-3*a));
    Point center2 = calcCircle(Point(0,0),Point(a,-a),Point(a*(-1-2/sqrt(2.0))+mid,a*(-2-1/sqrt(2.0))+mid));

    if(center1.real()>center2.real())
      L = mid;
    else
      R = mid;
  }

  ans[5] = abs(calcCircle(Point(0,0),Point(a,-a),Point((L+R)/2,-3*a)));
  for(int i=0;i<6;i++){
    if(i) cout << ' ';
    printf("%.11lf",ans[i]);
  }
  cout << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
