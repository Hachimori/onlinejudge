#include<iostream>
#include<complex>
#include<cmath>
#include<cstdio>
using namespace std;
typedef complex<double> Point;
const int NITER = 100;

double r;

void read(){
  cin >> r;
}

void work(){
  double L = 0, R = 10*r;
  for(int i=0;i<NITER;i++){
    double mid = (L+R)/2;
    Point a = Point(0,0);
    Point b = Point(2*mid-(2/sqrt(3)+sqrt(3))*r,r);
    if(norm(a-b)<4*r*r){
      L = mid;
      continue;
    }
    if(norm(a-b)>16*r*r){
      R = mid;
      continue;
    }
    double theta = acos(abs(a-b)/(4*r));
    Point c = (b-a)*polar(2*r/abs(a-b),theta)+a;
    if(c.imag()+r>mid*sqrt(3)/2)
      L = mid;
    else
      R = mid;
  }
  printf("%.12lf ",(L+R)/2);


  L = 0, R = 10*r;
  for(int i=0;i<NITER;i++){
    double mid = (L+R)/2;
    Point a = Point(0,0);
    Point b = Point(r,sqrt(3)*r);
    Point c = Point(2*mid-(2/sqrt(3)+sqrt(3))*r,r);
    if(norm(b-c)<4*r*r){
      L = mid;
      continue;
    }
    if(norm(b-c)>16*r*r){
      R = mid;
      continue;
    }
    double theta = acos(abs(c-b)/(4*r));
    Point d = (c-b)*polar(2*r/abs(c-b),theta)+b;
    if(d.imag()+r>mid*sqrt(3)/2)
      L = mid;
    else
      R = mid;
  }  
  printf("%.12lf\n",(L+R)/2);  
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
