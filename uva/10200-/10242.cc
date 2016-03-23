#include<iostream>
#include<complex>
#include<cstdio>
#define EPS 1e-7
using namespace std;
typedef complex<double> Point;

int main(){
  double x1, y1, x2, y2, x3, y3, x4, y4;
  while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4){
    Point vec1bgn = Point(x1,y1);
    Point vec1end = Point(x2,y2);
    Point vec2bgn = Point(x3,y3);
    Point vec2end = Point(x4,y4);

    if(abs(vec1bgn-vec2end)<EPS)
      swap(vec2bgn,vec2end);
    
    if(abs(vec1end-vec2bgn)<EPS)
      swap(vec1bgn,vec1end);

    if(abs(vec1end-vec2end)<EPS){
      swap(vec1bgn,vec1end);
      swap(vec2bgn,vec2end);
    }

    Point ans = vec1end+vec2end-vec2bgn;
    printf("%.3lf %.3lf\n",ans.real(),ans.imag());
  }
  return 0;
}
