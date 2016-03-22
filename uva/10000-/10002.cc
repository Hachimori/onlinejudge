// uva 10002
// convex gravity point
//
// 凸多角形以外のデータには試していない。
//
// http://www.saltspring.com/brochmann/math/centroid/centroid.html

#include<iostream>
#include<vector>
#include<complex>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define SIZE 105
#define EPS (1.0e-9)
#define EQ(x,y) (fabs(x-y)<EPS)
using namespace std;

typedef complex<double> Point;

int nPoint;
Point pt[SIZE];

bool read(){
  cin >> nPoint;
  if(nPoint<3) return false;
  
  for(int i=0;i<nPoint;i++){
    double x,y;
    cin >> x >> y;

    pt[i] = Point(x,y);
  }

  return true;
}

double cross(Point &a, Point &b, Point &o){
  return imag(conj(a-o)*(b-o));
}

int ccw(Point a, Point b, Point c){
  double ret = cross(b,c,a);
  
  if(EQ(ret,0)) return 0;
  return (ret>0 ? 1:-1);
}

bool cmp(const Point &a, const Point &b){
  if(EQ(a.real(),b.real())) return a.imag()<b.imag();
  return a.real()<b.real();
}

void pushPt(vector<Point> &ret, bool low){
  int bgn = (low ? 0 : nPoint-1);
  int end = (low ? nPoint : -1);
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
  sort(pt,pt+nPoint,cmp);
  vector<Point> ret;
  pushPt(ret,true);
  pushPt(ret,false);
  return ret;
}

Point calcCentroid(vector<Point> &poly){
  double sArea = 0;
  for(int i=0;i<poly.size();i++)
    sArea += (poly[i].real()-poly[(i+1)%poly.size()].real())*
             (poly[i].imag()+poly[(i+1)%poly.size()].imag());
  sArea = fabs(sArea/2);

  Point ret(0,0);
  for(int i=1;i<poly.size()-1;i++){
    double area = cross(poly[i],poly[i+1],poly[0])/2;
    Point centroid = (poly[i]+poly[i+1]+poly[0])/3.0;
    ret += centroid*area/sArea;
  }
  
  return ret;
}


void work(){
  vector<Point> polygon = calcConvex();
  Point ans = calcCentroid(polygon);
  
  if(-0.0005<ans.real() && ans.real()<=0) ans = Point(0,ans.imag());
  if(-0.0005<ans.imag() && ans.imag()<=0) ans = Point(ans.real(),0);
  printf("%.3lf %.3lf\n",ans.real(),ans.imag());
}

int main(){
  while(read())
    work();
  
  return 0;
}