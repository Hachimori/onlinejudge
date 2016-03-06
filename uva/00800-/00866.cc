#include<iostream>
#include<complex>
#include<set>
#define BUF 1005
#define EPS  (1.0e-7)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define LT(x,y) ((x)<=(y)-EPS)
using namespace std;
typedef complex<double> Point;

namespace std {
  bool operator< (const Point& a, const Point& b) {
    if(EQ(a.real(),b.real())) return LT(a.imag(),b.imag());
    return LT(a.real(),b.real());
  }
}

class Segment{
public:
  Point bgn, end;
  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
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

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}
bool isIntersect(Segment a, Segment b){
  return ccw(a.bgn,a.end,b.bgn)*ccw(a.bgn,a.end,b.end)<=0 &&
         ccw(b.bgn,b.end,a.bgn)*ccw(b.bgn,b.end,a.end)<=0;
}

int nSeg;
Segment seg[BUF];

void read(){
  cin >> nSeg;
  for(int i=0;i<nSeg;i++){
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    seg[i] = Segment(Point(x1,y1),Point(x2,y2));
  }
}

void work(){
  int cnt = nSeg;
  set<Point> S;
  for(int i=0;i<nSeg;i++)
    for(int j=i+1;j<nSeg;j++)
      if(isIntersect(seg[i],seg[j])){
        cnt += 1+!S.count(calcIntersect(seg[i],seg[j]));
        S.insert(calcIntersect(seg[i],seg[j]));
      }
  cout << cnt << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
