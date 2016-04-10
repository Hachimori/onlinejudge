#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double PI = acos(-1);

int n;
double area;

bool read(){
  scanf("%d%lf",&n,&area);
  return n>=3;
}

void work(int cases){
  double theta = 2*PI/n;
  double outerCircleR = sqrt(2*area/(n*sin(theta)));
  double sideOfPolygon = sqrt(2*outerCircleR*outerCircleR*(1-cos(theta)));
  double innerCircleR = area*2/(sideOfPolygon*n);
  printf("Case %d: %.5lf %.5lf\n",
         cases,
         outerCircleR*outerCircleR*PI-area,
         area-innerCircleR*innerCircleR*PI);
}

int main(){
  for(int i=0;read();i++) work(i+1);
  return 0;
}
