#include<iostream>
#include<complex>
#include<vector>
#define POLYGON 25
#define QUERY 10000
#define EPS (1.0e-9)
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

bool onSegment(Segment s, Point p){
  return ccw(s.bgn,s.end,p)==0;
}

int isInside(Polygon &poly, Point pt){
  int n = poly.size();
  double sum = 0;
  
  for(int i=0;i<n;i++)
    sum += arg((poly[i]-pt)/(poly[(i+1)%n]-pt));

  return (EQ(sum,0) ? -1 : 1);
}

int nQuery, nPolygon;
Point query[QUERY][2];
Polygon polygon[POLYGON];

void read(){
  cin >> nPolygon;
  
  for(int i=0;i<nPolygon;i++) polygon[i].clear();
  
  for(int i=0;i<nPolygon;i++){
    int nPt;
    cin >> nPt;
    for(int j=0;j<nPt;j++){
      int x, y;
      cin >> x >> y;
      polygon[i].push_back(Point(x,y));
    }
  }

  cin >> nQuery;
  for(int i=0;i<nQuery;i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    query[i][0] = Point(x1,y1),  query[i][1] = Point(x2,y2);
  }
}

void work(int cases){
  cout << "Case " << cases << ":" << endl;

  for(int i=0;i<nQuery;i++){
    int cnt = 0;
    for(int j=0;j<nPolygon;j++)
      if(isInside(polygon[j],query[i][0])!=isInside(polygon[j],query[i][1]))
	cnt++;
    cout << cnt << endl;
  }
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  
  return 0;
}
