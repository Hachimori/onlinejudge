#include<iostream>
#include<complex>
#include<vector>
#include<set>
#include<cstdio>
#define EPS  (1.0e-7)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define GE(x,y) (GT(x,y) || EQ(x,y))
#define LE(x,y) (LT(x,y) || EQ(x,y))
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
  if(LT(dot(d1,d2),0)) return -2;      // b - a - c
  if(LT(norm(d1),norm(d2))) return 2;  // a - b - c
  return 0;                            // a - c - b
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

bool isIntersect(Segment a, Segment b){
  return ccw(a.bgn,a.end,b.bgn)*ccw(a.bgn,a.end,b.end)<=0 &&
         ccw(b.bgn,b.end,a.bgn)*ccw(b.bgn,b.end,a.end)<=0;
}

bool isInside(vector<Segment> &pol, Point pt){
  int n = pol.size();
  //for(int i=0;i<pol.size();i++)
  //if(onSegment(Segment(poly[i],poly[(i+1)%n]),pt))
  //  return 0;
  double sum = 0;
  for(int i=0;i<pol.size();i++)
    sum += arg((pol[i].bgn-pt)/(pol[i].end-pt));
  return !EQ(sum,0);
}

vector<Segment> poly[2];

bool read(){
  poly[0] = poly[1] = vector<Segment>();
  for(int i=0;i<2;i++){
    int n;
    cin >> n;
    if(n<3) return false;
    vector<Point> pList;
    for(int j=0;j<n;j++){
      double x, y;
      cin >> x >> y;
      pList.push_back(Point(x,y));
    }
    for(int j=0;j<n;j++)
      poly[i].push_back(Segment(pList[j],pList[(j+1)%n]));
  }
  return true;
}

void work(){
  set<Point> ans;
  for(int i=0;i<poly[0].size();i++)
    for(int j=0;j<poly[1].size();j++)
      if(isIntersect(poly[0][i],poly[1][j]))
        ans.insert(calcIntersect(poly[0][i],poly[1][j]));
  
  for(int i=0;i<2;i++)
    for(int j=0;j<poly[i].size();j++)
      if(isInside(poly[!i],poly[i][j].bgn))
        ans.insert(poly[i][j].bgn);

  cout << ans.size() << endl;
  for(set<Point>::iterator i=ans.begin();i!=ans.end();i++)
    printf("%.2lf %.2lf\n",i->real(),i->imag());
}

int main(){
  while(read()) work();
  return 0;
}
