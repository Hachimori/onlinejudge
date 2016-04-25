#include<iostream>
#include<vector>
#include<algorithm>
#include<complex>
#include<cmath>
#include<cstdio>
#define POINT 105
#define EPS (1.0e-9)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
using namespace std;
typedef complex<double> Point;

namespace std {
  bool operator< (const Point& a, const Point& b) {
    if(EQ(a.real(),b.real())) return LT(a.imag(),b.imag());
    return LT(a.real(),b.real());
  }
}

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

int ccw(Point &a, Point &b, Point &c){
  double ret = cross(b-a,c-a);

  if(EQ(ret,0)) return 0;
  return (ret>0 ? 1:-1);
}

int nPt;
double init;
Point pt[POINT];

void pushPt(vector<Point> &ret, bool low){
  int bgn = (low ? 0 : nPt-1);
  int end = (low ? nPt : -1);
  int d = (low ? 1 : -1);
  
  ret.push_back(pt[bgn]);
  int m = ret.size();
  
  for(int i=bgn+d;i!=end;i+=d){
    for(int k;(k=ret.size())>m && 
	  ccw(ret[k-2],ret[k-1],pt[i])<=0;) 
      ret.pop_back();
    ret.push_back(pt[i]);
  }
  ret.pop_back();
}

vector<Point> calcConvex(){
  sort(pt,pt+nPt);
  vector<Point> ret;
  pushPt(ret,true);
  pushPt(ret,false);
  return ret;
}

void read(){
  cin >> init >> nPt;
  
  for(int i=0;i<nPt;i++){
    double x, y;
    cin >> x >> y;
    pt[i] = Point(x,y);
  }
}

void work(){
  vector<Point> convex = calcConvex();

  double sum = 0;
  for(int i=0;i<convex.size();i++)
    sum += abs(convex[i]-convex[(i+1)%convex.size()]);
  
  printf("%.5lf\n",max(sum,init));
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
