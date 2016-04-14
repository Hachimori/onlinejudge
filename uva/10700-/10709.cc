#include<iostream>
#include<string>
#include<algorithm>
#include<complex>
#include<cstdio>
#define EPS (1.0e-8)
#define PI acos(-1.0)
#define LINE 0
#define SEGMENT 1
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define LT(x,y) ((x)<=(y)-EPS)
using namespace std;
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

Point rotate(Point p){
  return Point(-p.imag(),p.real());
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

bool isParallel(Segment a, Segment b){
  return EQ(cross(a.end-a.bgn,b.end-b.bgn),0);
}

bool onSegment(Segment s, Point p){
  return ccw(s.bgn,s.end,p)==0;
}

bool isIntersect(Segment a, Segment b){
  return ccw(a.bgn,a.end,b.bgn)*ccw(a.bgn,a.end,b.end)<=0 &&
         ccw(b.bgn,b.end,a.bgn)*ccw(b.bgn,b.end,a.end)<=0;
}

double calcDist(Segment s, Point p){
  Point pt = calcIntersect(s,Segment(p,p+rotate(s.end-s.bgn)));
  
  return onSegment(s,pt) ? abs(pt-p) : min(abs(s.bgn-p),abs(s.end-p));
}

double compute(Segment a, Segment b){
  double ret = calcDist(a,b.bgn);
  ret = min(ret,calcDist(a,b.end));
  ret = min(ret,calcDist(b,a.bgn));
  ret = min(ret,calcDist(b,a.end));
  return ret;
}

double p2lDist(Segment s, Point p){
  Point ret = calcIntersect(s,Segment(p,p+rotate(s.end-s.bgn)));
  return abs(ret-p);
}

int id[2];
Segment seg[2];

bool read(){
  for(int i=0;i<2;i++){
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    seg[i].bgn = Point(x1,y1);
    seg[i].end = Point(x2,y2);
    
    string s; cin >> s;
    if(s=="END") return false;
    id[i] = (s=="LS");
  }
  
  if(id[0]>id[1]){
    swap(id[0],id[1]);
    swap(seg[0],seg[1]);
  }
  
  return true;
}

void work(){
  if(id[0]==LINE && id[1]==LINE)
    if(isParallel(seg[0],seg[1]))
      printf("%.5lf \n",p2lDist(seg[0],seg[1].bgn));
    else
      cout << "0.00000 " << endl;
  
  if(id[0]==SEGMENT && id[1]==SEGMENT)
    if(isIntersect(seg[0],seg[1]))
      cout << "0.00000 " << endl;
    else
      printf("%.5lf \n",compute(seg[0],seg[1]));
  
  if(id[0]==LINE && id[1]==SEGMENT)
    if(ccw(seg[0].bgn,seg[0].end,seg[1].bgn)*
       ccw(seg[0].bgn,seg[0].end,seg[1].end)<=0)
      cout << "0.00000 " << endl;
    else
      printf("%.5lf \n",min(p2lDist(seg[0],seg[1].bgn),
			    p2lDist(seg[0],seg[1].end)));
}

int main(){
  while(read())
    work();
  
  return 0;
}
