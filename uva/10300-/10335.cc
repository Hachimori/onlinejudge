// uva 10335

#include<iostream>
#include<complex>
#include<cstdio>
#define EPS  (1.0e-7)
#define GT(x,y) ((x)>=(y)+EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define EQ(x,y) (fabs((x)-(y))<EPS)
using namespace std;
const int BUF = 15;
const double PI = acos(-1.0);
typedef complex<double> Point; 

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

bool eq(Point a, Point b){
  return fabs(a.real()-b.real())<0.005 &&
         fabs(a.imag()-b.imag())<0.005;
}

Point rotate(Point p){
  return Point(-p.imag(),p.real());
}

bool isIntersect(Segment a, Segment b){ // a is line
  return ccw(a.bgn,a.end,b.bgn)*ccw(a.bgn,a.end,b.end)<=0;
}

bool isParallel(Segment a, Segment b){
  return EQ(cross(a.end-a.bgn,b.end-b.bgn),0);
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

void reflect(Point &p, Point &v, Point xp, Segment seg){
  v = v*polar(1.0,2*arg((seg.end-seg.bgn)/v));
  p = xp;
}

int nSeg, nIter;
Point initPos;
double initAngle;
Segment seg[BUF];

bool read(){
  cin >> nSeg >> nIter;
  if(!(nSeg|nIter)) return false;

  double initX, initY, angle;
  cin >> initX >> initY >> angle;
  initPos = Point(initX,initY);
  initAngle = angle/180*PI;

  Point pt[BUF];
  for(int i=0;i<nSeg;i++){
    double x, y;
    cin >> x >> y;
    pt[i] = Point(x,y);
  }

  for(int i=0;i<nSeg;i++)
    seg[i] = Segment(pt[i],pt[(i+1)%nSeg]);

  return true;
}

void work(){
  double angle = initAngle;
  Point pt = initPos;
  
  for(int it=0;it<nIter+1;it++){
    Point vec = polar(1.0,angle);
    for(int i=0;i<nSeg;i++){
      Segment s = Segment(pt,pt+vec);
      if(isIntersect(s,seg[i]) && !isParallel(s,seg[i])){
        Point xp = calcIntersect(s,seg[i]);
        if(norm(pt-xp)<EPS) continue;
        if(eq(xp,seg[i].bgn) || eq(xp,seg[i].end)){
          cout << "lost forever..." << endl;
          return;
        }
        reflect(pt,vec,xp,seg[i]);
        angle = arg(vec);
        break;
      }
    }
  }

  printf("%.2lf %.2lf\n",pt.real(),pt.imag());
}

int main(){
  while(read()) work();
  return 0;
}
