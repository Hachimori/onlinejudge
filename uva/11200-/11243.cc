#include<iostream>
#include<algorithm>
#include<complex>
#include<cmath>
#include<cstdio>
#define POINT 35
#define INF (1<<30)
#define EPS (1.0e-8)
using namespace std;
typedef complex<double> Point;

const double PI = acos(-1.0);
int nPt;
Point pt[POINT];

void read(){
  cin >> nPt;

  for(int i=0;i<nPt;i++){
    double x, y;
    cin >> x >> y;
    pt[i] = Point(x,y);
  }
}

double get(double arg){
  static Point p[POINT];
  
  for(int i=0;i<nPt;i++) p[i] = pt[i]*polar(1.0,arg);
  
  double minX = INF, maxX = -INF, minY = INF, maxY = -INF;
  for(int i=0;i<nPt;i++){
    minX = min(minX,p[i].real());
    minY = min(minY,p[i].imag());
    maxX = max(maxX,p[i].real());
    maxY = max(maxY,p[i].imag());
  }

  double d = max(maxX-minX,maxY-minY);
  return d*d;
}

void work(){
  double L = 0, R = PI/2;
  
  while(R-L>EPS){
    double v1 = L+(R-L)/3;
    double v2 = L+2*(R-L)/3;
    
    if(get(v1)<get(v2))
      R = v2;
    else
      L = v1;
  }
  
  printf("%.2lf\n",get(L));
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
