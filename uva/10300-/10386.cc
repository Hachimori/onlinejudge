#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double PI = acos(-1.0);
const int ITER = 1000;

double r;

bool read(){
  return cin >> r;
}

double f1(double arg){
  return 8*r*cos(arg)+2*r*sqrt(3.0);
}

double f2(double arg){
  return 4*r*cos(PI/3-arg)+2*r+2*r*sqrt(3.0);
}

double f3(double arg){
  return 4*r*cos(PI/3-arg)+4*r+2*r*sqrt(3.0);
}

void work(){
  double L = 0, R = PI/3;
  for(int i=0;i<ITER;i++){
    double mid = (L+R)/2;
    if(f1(mid)<f2(mid))
      R = mid;
    else
      L = mid;
  }
  printf("%.10lf",f1((L+R)/2));

  L = 0, R = PI/3;
  for(int i=0;i<ITER;i++){
    double mid = (L+R)/2;
    if(f1(mid)<f3(mid))
      R = mid;
    else
      L = mid;
  }
  printf(" %.10lf\n",f1((L+R)/2));
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    if(!read()) break;
    work();
  }
  return 0;
}
