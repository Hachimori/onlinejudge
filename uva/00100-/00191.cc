#include<iostream>
#include<complex>
#include<algorithm>
#include<vector>
#define EPS (1.0e-7)
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

Segment seg;
double xl, yt, xr, yb;
vector<Segment> rect;

void read(){
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  
  seg = Segment(Point(x1,y1),Point(x2,y2));
  
  cin >> xl >> yt >> xr >> yb;
  
  if(xl>xr) swap(xl,xr);
  if(yb>yt) swap(yb,yt);
  
  rect.clear();
  rect.push_back(Segment(Point(xl,yb),Point(xl,yt)));
  rect.push_back(Segment(Point(xl,yt),Point(xr,yt)));
  rect.push_back(Segment(Point(xr,yt),Point(xr,yb)));
  rect.push_back(Segment(Point(xr,yb),Point(xl,yb)));
}

double dot(Point a, Point b){
  return real(conj(b)*a);
}

double cross(Point a, Point b){
  return imag(conj(b)*a);
}

int ccw(Point a, Point b, Point c){
  Point d1 = b-a, d2 = c-a;
  if(GT(cross(d1,d2),0)) return 1;
  if(LT(cross(d1,d2),0)) return -1;
  if(LT(dot(d1,d2),0)) return -2;    
  if(LT(norm(d1),norm(d2))) return 2;
  return 0;
}

bool isIntersect(Segment a, Segment b){
  return ccw(a.bgn,a.end,b.bgn)*ccw(a.bgn,a.end,b.end)<=0 &&
         ccw(b.bgn,b.end,a.bgn)*ccw(b.bgn,b.end,a.end)<=0;
}

bool isInside(Point p){
  return (xl<=p.real() && p.real()<=xr && yb<=p.imag() && p.imag()<=yt);
}

void work(){
  for(int i=0;i<rect.size();i++)
    if(isIntersect(seg,rect[i])){
      cout << "T" << endl;
      return;
    }
  
  if(isInside(seg.bgn) || isInside(seg.end)) cout << "T" << endl;
  else cout << "F" << endl;
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
