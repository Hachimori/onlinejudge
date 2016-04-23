#include<iostream>
#include<vector>
#include<complex>
#include<cstdio>
#define QUERY 100000
#define EPS  (1.0e-7)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define INF (1<<20)
using namespace std;
typedef complex<double> Point;
typedef vector<Point> Polygon;

const double PI = acos(-1.0);

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
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

bool isParallel(Segment a, Segment b){
  return EQ(cross(a.end-a.bgn,b.end-b.bgn),0);
}

bool isOnSegment(Segment s, Point p){
  return ccw(s.bgn,s.end,p)==0;
}

bool isIntersect(Segment a, Segment b){
  return !isParallel(a,b) && 
         ccw(a.bgn,a.end,b.bgn)*ccw(a.bgn,a.end,b.end)<=0 &&
         ccw(b.bgn,b.end,a.bgn)*ccw(b.bgn,b.end,a.end)<=0;
}

double calcArea(Polygon &poly){
  double sum = 0;

  for(int i=0;i<poly.size();i++)
    sum += (poly[i].imag()+poly[(i+1)%poly.size()].imag()) *
           (poly[i].real()-poly[(i+1)%poly.size()].real());
  
  return fabs(sum)/2;
}

int nQuery;
Polygon polygon;
Point query[QUERY];

bool read(){
  int nPt;
  if(!(cin >> nPt)) return false;
  
  polygon = Polygon(nPt);
  
  for(int i=0;i<nPt;i++){
    double x, y;
    cin >> x >> y;
    polygon[i] = Point(x,y);
  }
  
  cin >> nQuery;
  for(int i=0;i<nQuery;i++){
    double x, y;
    cin >> x >> y;
    query[i] = Point(x,y);
  }
  
  return true;
}

int getConcave(Polygon &poly){
  int n = poly.size();

  for(int i=0;i<n;i++){
    int prev = (i+n-1)%n, next = (i+1)%n;

    if(LT(arg((poly[prev]-poly[i])/(poly[next]-poly[i])),0) && 
       !EQ(fabs(arg((poly[prev]-poly[i])/(poly[next]-poly[i]))),PI) )
      return i;
  }
}

void calcCovered(Polygon &poly, Point pt, int concave){
  int n = poly.size();
  bool toCut = false;
  Polygon ret;
  Segment line = Segment(pt+(poly[concave]-pt)*0.000001,(poly[concave]-pt)*10000.0+pt);
  Point intersect = Point(INF,INF);

  if(EQ(abs(pt-poly[concave]),0)) return;
  
  pt += (poly[concave]-pt)*0.0001;
  
  for(int i=0;i<n;i++)
    if(isOnSegment(Segment(poly[i],poly[(i+1)%n]),pt)){
      pt -= poly[i];
      pt *= polar(1.0,PI/100000);
      pt += poly[i];
      break;
    }
  

  for(int i=0;i<n;i++)
    if(isIntersect(Segment(poly[i],poly[(i+1)%n]),line)){
      
      Point p = calcIntersect(Segment(poly[i],poly[(i+1)%n]),line);

      if(!EQ(abs(p-poly[concave]),0)){
	intersect = p;
	break;
      }
    }
  if(EQ(abs(intersect-Point(INF,INF)),0)) return;

  
  for(int i=0;i<n;i++){
    bool intersects = false;
    for(int j=0;j<n;j++){
      if(j==i || (j+1)%n==i) continue;
      
      if(isIntersect(Segment(poly[j],poly[(j+1)%n]),Segment(pt,poly[i]))){
	intersects = true;
	break;
      }
    }
    
    if(isOnSegment(Segment(poly[i],poly[(i+n-1)%n]),intersect))
      ret.push_back(intersect);

    if(!intersects){
      
      ret.push_back(poly[i]);
    }
  }
  
  poly = ret;
}

void work(int cases){
  cout << "Gallery #" << cases << endl;

  int idx = getConcave(polygon);

  for(int i=0;i<nQuery;i++){
    Polygon poly = polygon;
    
    calcCovered(poly,query[i],idx);
    printf("%.2lf\n",calcArea(poly));
  }
}

int main(){
  for(int i=0;read();i++)
    work(i+1);

  return 0;
}