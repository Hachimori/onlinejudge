#include<iostream>
#include<complex>
#include<vector>
#define EPS  (1.0e-7)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define LE(x,y) (LT(x,y) || EQ(x,y))
using namespace std;
typedef complex<int> Point;
class Segment{
public:
  Point bgn, end;

  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};
typedef vector<Segment> Polygon;


int nPoint;
Point point;
Polygon polygon;

bool read(){
  cin >> nPoint;
  if(nPoint==0) return false;
  
  polygon.clear();

  int x, y;
  Point pts[10000];
  
  for(int i=0;i<nPoint;i++){
    cin >> x >> y;
    pts[i] = Point(x,y);
  }
  
  for(int i=0;i<nPoint;i++)
    polygon.push_back(Segment(pts[i],pts[(i+1)%nPoint]));

  cin >> x >> y;
  point = Point(x,y);
  
  return true;
}

int cross(Point a, Point b){
  return imag(conj(a)*b);
}

int dot(Point a, Point b){
  return real(conj(a)*b);
}

int ccw(Point a, Point b, Point p){
  int ret = cross(b-a,p-a);
  
  if(ret==0) return 0;
  return (ret>0 ? 1:-1);
}

bool onSegment(Segment s, Point c){
  Point a = s.bgn, b = s.end;
  return EQ( cross(b-a, c-a), 0.0 ) &&
         (dot(b-a, c-a) > -EPS) &&
         (dot(a-b, c-b) > -EPS);
}

bool isHit(Segment s, Point p){
  return LE(s.bgn.imag(),p.imag()) && LT(p.imag(),s.end.imag()) &&
          ccw(s.bgn,s.end,p)==1;
}

int isInside(Polygon &poly, Point pt){
  for(int i=0;i<poly.size();i++)
    if(onSegment(poly[i],pt))
      return 0;

  for(int i=0;i<poly.size();i++)
    if(poly[i].end.imag()<poly[i].bgn.imag())
      swap(poly[i].end,poly[i].bgn);
  
  int cnt = 0;
  for(int i=0;i<poly.size();i++){
    if(EQ(poly[i].bgn.imag(),poly[i].end.imag())) continue;
    if(isHit(poly[i],pt))
      cnt++;
  }  

  return (cnt%2==1 ? 1 : -1);
}

void work(){
  cout << (isInside(polygon,point)==1 ? 'T' : 'F') << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
