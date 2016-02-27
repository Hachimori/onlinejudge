#include<iostream>
#include<vector>
#include<complex>
#include<cstdio>
#define EPS (1.0e-7)
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
  if(GT(cross(d1,d2),0)) return 1;
  if(LT(cross(d1,d2),0)) return -1;
  if(LT(dot(d1,d2),0)) return -2;    
  if(LT(norm(d1),norm(d2))) return 2;
  return 0;                          
}

Point calcIntersect(Segment a, Segment b){
  Point d1, d2;
  d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

void cutPolygon(Segment &l, Polygon &p){
  int n = p.size();
  Polygon next;
  
  for(int i=0;i<n;i++){
    if(ccw(l.bgn,l.end,p[i])!=1)
      next.push_back(p[i]);
    if(ccw(l.bgn,l.end,p[i])*ccw(l.bgn,l.end,p[(i+1)%n])==-1)
      next.push_back(calcIntersect(l,Segment(p[i],p[(i+1)%n])));
  } 

  p = next;
}

double calcArea(Polygon &p){
  double sum = 0;

  for(int i=0;i<p.size();i++)
    sum += (p[i].imag()+p[(i+1)%p.size()].imag())*
           (p[i].real()-p[(i+1)%p.size()].real());
  
  return fabs(sum)/2.0;
}

Polygon polygon[2];

bool read(){
  int nPt[2];
  
  for(int i=0;i<2;i++)
    polygon[i].clear();
    
  for(int i=0;i<2;i++){
    cin >> nPt[i];
    if(nPt[i]==0) return false;

    for(int j=0;j<nPt[i];j++){
      double x, y;
      cin >> x >> y;
      polygon[i].push_back(Point(x,y));
    }
  }
  
  return true;
}

void work(){
  Polygon curr = polygon[0];
  
  for(int i=0;i<polygon[1].size();i++){
    Segment line = Segment(polygon[1][i],polygon[1][(i+1)%polygon[1].size()]);
    cutPolygon(line,curr);
  }

  printf("%8.2lf",calcArea(polygon[0])+calcArea(polygon[1])-2*calcArea(curr));
}

int main(){
  while(read())
    work();
  cout << endl;

  return 0;
}
