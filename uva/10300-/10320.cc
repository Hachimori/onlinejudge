#include<iostream>
#include<complex>
#include<cmath>
#include<cstdio>
using namespace std;
typedef complex<double> Point;
const double PI = acos(-1.0);

class Circle{
public:
  double r;
  Point p;
  Circle(){}
  Circle(double r, Point p): r(r), p(p){}
};

double R, H, W;

bool read(){
  return cin >> H >> W >> R;
}

Point circleCalcIntersect(Circle a, Circle b){
  double d = abs(a.p-b.p);
  if(a.r+b.r<d) return Point(-1,-1);
  double angle = acos((b.r*b.r-a.r*a.r-d*d)/(-2*a.r*d));
  Point aa = (b.p-a.p)*polar(a.r/d, angle)+a.p;
  Point bb = (b.p-a.p)*polar(a.r/d,-angle)+a.p;
  return aa.imag()>bb.imag() ? aa : bb;
}

void work(){
  H = min(H,R);
  W = min(W,R);
  if(H>W) swap(H,W);
  double ans = R*R*PI*3/4;

  if(H+W>=R){
    ans += (R-H)*(R-H)*PI/4 + (R-W)*(R-W)*PI/4;
  }
  else{
    Circle a = Circle(R-H,Point(0,H));
    Circle b = Circle(R-W,Point(W,0));
    Point xp = circleCalcIntersect(a,b);
    double theta;
    theta = arg((Point(0,R)-Point(0,H))/(xp-Point(0,H)));
    ans += (R-H)*(R-H)*theta/2;
    theta = -arg((Point(R,0)-Point(W,0))/(xp-Point(W,0)));
    ans += (R-W)*(R-W)*theta/2;
    double polyArea = 0;
    polyArea += (xp.imag()+0)*(xp.real()-W);
    polyArea += (H+xp.imag())*(0-xp.real());
    polyArea += (H+H)*(W-0);
    polyArea += (0+H)*(W-W);
    ans += fabs(polyArea/2);
  }
  printf("%.10lf\n",ans);
}

int main(){
  while(read()) work();
  return 0;
}
