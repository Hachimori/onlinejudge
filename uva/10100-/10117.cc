#include<iostream>
#include<vector>
#include<complex>
#include<cstdio>
#define POINT 25
#define EPS  (1.0e-7)
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

Point rotate(Point p){
  return Point(-p.imag(),p.real());
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

void cutPolygon(Segment &l, Polygon &p){
  int n = p.size();
  Polygon next;
  
  for(int i=0;i<n;i++){
    if(ccw(l.bgn,l.end,p[i])!=-1)
      next.push_back(p[i]);

    if(ccw(l.bgn,l.end,p[i])*ccw(l.bgn,l.end,p[(i+1)%n])==-1)
      next.push_back(calcIntersect(l,Segment(p[i],p[(i+1)%n])));
  } 
  
  p = next;
}

double calcArea(Polygon &poly){
  double sum = 0;

  for(int i=0;i<poly.size();i++)
    sum += (poly[i].imag()+poly[(i+1)%poly.size()].imag())*
           (poly[i].real()-poly[(i+1)%poly.size()].real());
  
  return fabs(sum)/2;
}

int nPt, nAct;
double height;
Polygon polygon;

bool read(){
  cin >> nPt >> nAct >> height;
  if(nPt==0 && nAct==0 && height==0) return false;
  
  polygon.clear();
  
  for(int i=0;i<nPt;i++){
    double x, y;
    cin >> x >> y;
    
    polygon.push_back(Point(x,y));
  }
  
  nAct = min(nAct,nPt);
  
  return true;
}

Segment move(Segment seg){
  Segment ret;
  ret.bgn = seg.bgn+height*rotate(seg.end-seg.bgn)/abs(seg.end-seg.bgn);
  ret.end = seg.end+height*rotate(seg.end-seg.bgn)/abs(seg.end-seg.bgn);
  
  return ret;
}

double calc(int nCut, int toCut[]){
  Polygon curr = polygon;
  
  for(int i=0;i<nCut;i++){
    int a = toCut[i], b = (toCut[i]+1)%polygon.size();
    Segment line = move(Segment(polygon[a],polygon[b]));
    
    cutPolygon(line,curr);
  }
  
  return calcArea(polygon)-calcArea(curr);
}

void rec(int idx, int nCut, int toCut[], double &ans){
  if(nCut==nAct){ 
    ans = max(ans,calc(nCut,toCut));
    return;
  }
  if(idx==nPt) return;
  
  rec(idx+1,nCut,toCut,ans);
  toCut[nCut] = idx;
  rec(idx+1,nCut+1,toCut,ans);
}

void work(){
  int toCut[POINT];
  double ans = 0;
  
  rec(0,0,toCut,ans);

  printf("%.2lf\n",ans);
}

int main(){
  while(read())
    work();

  return 0;
}
