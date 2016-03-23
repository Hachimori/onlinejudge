#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double PI = acos(-1.0);
const int ITER = 100;

double side;

bool read(){
  return cin >> side;
}


double getBfunc(double r){
  double e = 2*r/sqrt(3.0);
  return 2*(e+r);
}

double getB(){
  double L = 0, R = side;
  for(int loop=0;loop<ITER;loop++){
    double mid = (L+R)/2;
    if(getBfunc(mid)<side*2)
      L = mid;
    else
      R = mid;
  }
  return (L+R)/2;
}


double getDfunc(double r){
  double x1 = r/sqrt(3.0), y1 = -r;
  double x2 = side+side/4-r*sqrt(3.0)/2, y2 = -side*sqrt(3.0)/4-r/2;
  return hypot(x1-x2,y1-y2)>2*r;
}

double getD(){
  double L = 0, R = side;
  for(int loop=0;loop<ITER;loop++){
    double mid = (L+R)/2;
    if(getDfunc(mid))
      L = mid;
    else
      R = mid;
  }
  return (L+R)/2;
}


void work(){
  double a,b,c,d;
  a = side*sqrt(3.0)/2;
  b = getB();
  c = a/2;
  d = getD();
  printf("%.10lf %.10lf %.10lf %.10lf\n",a,b,c,d);
}


int main(){
  while(read()) work();
  return 0;
}
