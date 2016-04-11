#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

double x, y, c;

bool read(){
  return cin >> x >> y >> c;
}


void work(){
  double L = 0, R = min(x,y);
  for(int i=0;i<1000;i++){
    double mid = (L+R)/2;
    double h1 = sqrt(x*x-mid*mid), h2 = sqrt(y*y-mid*mid);
    double hx = h1*h2/(h1+h2);
    if(hx<c)
      R = mid;
    else
      L = mid;
  }
  printf("%.3lf\n",(L+R)/2);
}

int main(){
  while(read()) work();
  return 0;
}
