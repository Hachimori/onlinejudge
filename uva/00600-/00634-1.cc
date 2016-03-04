#include<iostream>
#include<complex>
#include<vector>
#define EPS  (1.0e-7)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define LE(x,y) (LT(x,y) || EQ(x,y))
using namespace std;
typedef complex<double> Point;
typedef vector<Point> Polygon;

class Segment{
public:
  Point bgn, end;

  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

int nPoint;
Point point;
Polygon polygon;

bool read(){
  cin >> nPoint;
  if(nPoint==0) return false;
  
  polygon.clear();

  double x, y;
  for(int i=0;i<nPoint;i++){
    cin >> x >> y;
    polygon.push_back(Point(x,y));
  }
  
  cin >> x >> y;
  point = Point(x,y);
  
  return true;
}

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

int ccw(Point a, Point b, Point p){
  double ret = cross(b-a,p-a);
  
  if(EQ(ret,0)) return 0;
  return (ret>0 ? 1:-1);
}

bool onSegment(Segment s, Point p){
  return LE(abs(p-s.bgn)+abs(s.end-p),abs(s.end-s.bgn));
}

int isInside(Polygon &poly, Point pt){
  int n = poly.size();
  double sum = 0;
  
  for(int i=0;i<poly.size();i++)
    if(onSegment(Segment(poly[i],poly[(i+1)%n]),pt))
      return 0;
      
  for(int i=0;i<poly.size();i++)
    sum += arg((poly[i]-pt)/(poly[(i+1)%n]-pt));

  return (EQ(sum,0) ? -1 : 1);
}

void work(){
  cout << (isInside(polygon,point)==1 ? 'T' : 'F') << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
