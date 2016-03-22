// uva 10180
//
// 点から円への接線を引く。
// 点は円の中に入っていてはいけない。
// 点が円周上にあればその点を返す。

#include<iostream>
#include<complex>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define INF (1<<30)
#define EPS (1.0e-7)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define LE(x,y) (LT(x,y) || EQ(x,y))
using namespace std;
typedef complex<double> Point;
const double PI = acos(-1.0);

class Segment{
public:
  Point bgn, end;
  
  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

class Circle{
public:
  Point p;
  double r;
  
  Circle(){}
  Circle(Point p, double r): p(p), r(r){}
};

double dot(Point a, Point b){
  return real(conj(a)*b);
}

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

int ccw(Point a, Point b, Point c){
  Point d1 = b-a, d2 = c-a;
  if(GT(cross(d1,d2),0)) return 1;
  if(LT(cross(d1,d2),0)) return -1;
  if(LT(dot(d1,d2),0)) return -2;    
  if(LT(norm(d1),norm(d2))) return 2;
  return 0;                          
}

Point rotate(Point p){
  return Point(-p.imag(),p.real());
}

bool onSegment(Segment s, Point p){
  return ccw(s.bgn,s.end,p)==0;
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

double p2sDist(Segment s, Point p){
  Point pt = calcIntersect(s,Segment(p,p+rotate(s.end-s.bgn)));
  
  return onSegment(s,pt) ? abs(pt-p) : min(abs(s.bgn-p),abs(s.end-p));
}

vector<Point> calcTangent(Circle c, Point p){
  if(LT(abs(c.p-p),c.r)) return vector<Point>();
  if(EQ(abs(c.p-p),c.r)) return vector<Point>(1,p);
  
  vector<Point> ret;
  double theta = asin(c.r/abs(p-c.p));
  
  ret.push_back(p+(c.p-p)*polar(cos(theta), theta));
  ret.push_back(p+(c.p-p)*polar(cos(theta),-theta));
  
  return ret;
}

Point a, b;
Circle circle;

void read(){
  double x1, y1, x2, y2, r;
  cin >> x1 >> y1 >> x2 >> y2 >> r;
  
  a = Point(x1,y1);
  b = Point(x2,y2);
  circle = Circle(Point(0,0),r);
}

void work(){
  if(EQ(abs(a-b),0) || LE(circle.r,p2sDist(Segment(a,b),circle.p)))
    printf("%.3lf\n",abs(a-b));
  else{
    vector<Point> as = calcTangent(circle,a), bs = calcTangent(circle,b);
    
    double minV = INF;
    for(int i=0;i<as.size();i++)
      for(int j=0;j<bs.size();j++){
	double theta = acos(dot(as[i],bs[j])/(abs(as[i])*abs(bs[j])));
	minV = min(minV,abs(a-as[i])+abs(b-bs[j])+circle.r*theta);
      }

    printf("%.3lf\n",minV);
  }
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
