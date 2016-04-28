#include<iostream>
#include<complex>
#include<vector>
#include<cstdio>
#define EPS (1.0e-10)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define LT(x,y) ((x)<=(y)-EPS)
using namespace std;
typedef complex<double> Point;
typedef vector<Point> Polygon;

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
  if(GT(cross(d1,d2),0)) return  1;
  if(LT(cross(d1,d2),0)) return -1;
  if(LT(dot(d1,d2),0)) return -2;
  if(LT(norm(d1),norm(d2))) return 2;
  return 0;
}

Point rotate(Point p, Point o){
  p -= o;
  return Point(-p.imag(),p.real())+o;
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);

  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

void cutPolygon(Segment l, Polygon &p){
  int n = p.size();
  Polygon next;

  for(int i=0;i<n;i++){
    if(ccw(l.bgn,l.end,p[i])>=0)
      next.push_back(p[i]);
    if(ccw(l.bgn,l.end,p[i])*ccw(l.bgn,l.end,p[(i+1)%n])<0)
      next.push_back(calcIntersect(l,Segment(p[i],p[(i+1)%n])));    
  }

  p = next;
};

int nPt;
Polygon polygon;

bool read(){
  cin >> nPt;
  if(nPt==0) return false;

  polygon.clear();

  for(int i=0;i<nPt;i++){
    double x, y; 
    cin >> x >> y;
    polygon.push_back(Point(x,y));
  }
  
  return true;
}

Polygon cutWhole(Polygon &p, double toCut){
  Polygon ret = p;
  
  for(int i=0;i<nPt;i++){
    Point vec = rotate(p[(i+1)%nPt],p[i])-p[i];
    Point bgn = p[i]+vec*toCut/abs(vec), end = bgn+p[(i+1)%nPt]-p[i];
    cutPolygon(Segment(bgn,end),ret);
  }

  return ret;
}

void work(){
  double L = 0, R = 1001;

  while(R-L>EPS){
    double mid = (L+R)/2;
    
    Polygon poly =  cutWhole(polygon,mid);

    if(poly.size()<3)
      R = mid;
    else
      L = mid;
  }

  printf("%.3lf\n",L);
}

int main(){
  while(read())
    work();
  
  return 0;
}
