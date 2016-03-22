#include<iostream>
#include<complex>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cassert>
#define EPS  (1.0e-8)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define LE(x,y) (EQ(x,y) || LT(x,y))
using namespace std;
typedef complex<double> Point;

class Segment{
public:
  Point bgn, end;
  
  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

class Circle{
public:
  Point p;
  double r;
  
  Circle(){}
  Circle(Point p, double r): p(p), r(r){}
};

double dot(Point a, Point b){
  return real(conj(a)*b);
}

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

Point rotate(Point p){
  return Point(-p.imag(),p.real());
}

vector<Point> calcTangent(Circle c, Point p){
  if(LT(abs(c.p-p),c.r)) return vector<Point>();
  if(EQ(abs(c.p-p),c.r)) return vector<Point>(1,p);
  
  vector<Point> ret;
  double theta = asin(c.r/abs(p-c.p));
  
  ret.push_back(p+(c.p-p)*polar(cos(theta), theta));
  ret.push_back(p+(c.p-p)*polar(cos(theta),-theta));
  
  return ret;
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

double p2sDist(Segment s, Point p){
  Point ret = calcIntersect(s,Segment(p,p+rotate(s.end-s.bgn)));
  return abs(ret-p);
}

Circle tree;
Point pos;

void read(){
  double y, x, r;
  cin >> y >> x >> r;
  
  tree = Circle(Point(x,y),r);
  
  cin >> y >> x;
  pos = Point(x,y);
}

bool isValid(vector<Point> tangent){
  if(!(LT(                         0,arg(pos/tangent[0])) && LT(arg(pos/tangent[0]),arg(tangent[1]/tangent[0]))) && 
     !(LT(arg(tangent[1]/tangent[0]),arg(pos/tangent[0])) && LT(arg(pos/tangent[0]),                         0)) )     
    return false;
  
  return LT(abs(tangent[0]),abs(Point(0,0)-pos));
}

void work(){
  assert(!EQ(abs(tree.p-       pos),tree.r));
  assert(!EQ(abs(tree.p-Point(0,0)),tree.r));

  vector<Point> tangent = calcTangent(tree,Point(0,0));

  if(!isValid(tangent)){
    cout << "0.000" << endl;
    return;
  }
  
  double ans = p2sDist(Segment(Point(0,0),tangent[0]),pos);
  ans = min(ans,p2sDist(Segment(Point(0,0),tangent[1]),pos));
  ans = min(ans,abs(pos-tree.p)-tree.r);

  printf("%.3lf\n",ans);
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
