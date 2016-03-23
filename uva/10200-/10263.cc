#include<iostream>
#include<complex>
#include<algorithm>
#include<cstdio>
#define POINT 10000
#define INF 100000000
#define EPS (1.0e-8)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define LE(x,y) (LT(x,y) || EQ(x,y))
using namespace std;

const double PI = acos(-1.0);
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

int ccw(Point a, Point b, Point p){
  double ret = cross(b-a,p-a);
  
  if(EQ(ret,0)) return 0;
  return (ret>0 ? 1:-1);
}

Point rotate(Point p){
  return Point(-p.imag(),p.real());
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

bool onSegment(Segment s, Point p){
  return LE(abs(p-s.bgn)+abs(s.end-p),abs(s.end-s.bgn));
}

bool isIntersect(Segment a, Segment b){
  Point a1, a2, b1, b2;
  a1 = a.bgn, a2 = a.end;
  b1 = b.bgn, b2 = b.end;
  
  if(0==ccw(a1,a2,b1)*ccw(a1,a2,b2) && 0==ccw(b1,b2,a1)*ccw(b1,b2,a2))
    return onSegment(a,b1) || onSegment(a,b2) || 
           onSegment(b,a1) || onSegment(b,a2);
  
  return 0>ccw(a1,a2,b1)*ccw(a1,a2,b2) && 0>ccw(b1,b2,a1)*ccw(b1,b2,a2);
}

double calcDist(Segment s, Point p, Point &ret){
  Point pt = calcIntersect(s,Segment(p,p+rotate(s.end-s.bgn)));
  
  if(onSegment(s,pt)){
    ret = pt;
    return abs(pt-p);
  }
  else {
    if(abs(s.bgn-p)<abs(s.end-p)) {
      ret = s.bgn;
      return abs(s.bgn-p);
    }
    else{
      ret = s.end;
      return abs(s.end-p);
    }
  }
}

int nPt;
Point pt[POINT];

bool read(){
  double x, y;
  if(!(cin >> x >> y)) return false;
  
  pt[0] = Point(x,y);

  cin >> nPt; nPt+=2;
  
  for(int i=1;i<nPt;i++){
    cin >> x >> y;
    pt[i] = Point(x,y);
  }
  
  return true;
}

void work(){
  double minV = INF;
  Point ans;

  for(int i=1;i<nPt-1;i++){
    Point rp;
    double rd;

    rd = calcDist(Segment(pt[i],pt[i+1]),pt[0],rp);

    if(minV>rd){
      minV = rd;
      ans = rp;
    }
  }
  printf("%.4lf\n%.4lf\n",ans.real(),ans.imag());
}

int main(){
  while(read())
    work();
  
  return 0;
}
