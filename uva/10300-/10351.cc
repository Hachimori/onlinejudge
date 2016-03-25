#include<iostream>
#include<cmath>
#define sq(x) ((x)*(x))
using namespace std;

double w, h, d, wlim, hlim, dlim;

bool read(){
  return cin >> wlim >> hlim >> dlim >> w >> h >> d;
}

// calculate (x^2)/(a^2)+(y^2)/(b^2)=r
double f(double x, double a, double b, double r){
  if(r-(x*x)/(a*a)<0) return 0;
  return sqrt(r-(x*x)/(a*a))*b;
}

// integral (x^2)/(a^2)+(y^2)/(b^2)=r
double calc(double a, double b, double r){
  double bgn = 0, end = sqrt(r*a*a);
  double sum = 0, div = 800000, mesh = (end-bgn)/div;
  for(int i=0;i<div;i+=2)
    sum += mesh*(   f(bgn+mesh*i,a,b,r)
                 +4*f(bgn+mesh*(i+1),a,b,r)
                   +f(bgn+mesh*(i+2),a,b,r) );
  return sum*4/3;
}

void work(int cases){
  double a, b, c;
  a = w/2;
  b = h/2;
  c = d/2;
  cout << "Set #" << cases << endl;
  if(w>wlim) 
    printf("%.6lf\n",calc(b,c,1-sq(wlim-w/2)/sq(a)));
  else if(h>hlim) 
    printf("%.6lf\n",calc(a,c,1-sq(hlim-h/2)/sq(b)));
  else if(d>dlim) 
    printf("%.6lf\n",calc(a,b,1-sq(dlim-d/2)/sq(c)));
  else 
    printf("%.6lf\n",0.0);
  
}

int main(){
  for(int cases=1;read();cases++) work(cases);
  return 0;
}
