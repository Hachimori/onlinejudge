#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const int ITER = 100;
const double PI = acos(-1.0);

double calc(double D, double d){
  double ret = 0;

  double r = d/2, R = D/2;
  double h = (D-d)/2, H = (R*h)/(R-r);
  
  ret += 2*(R*R*PI*H/3-r*r*PI*(H-h)/3);
  ret += r*r*PI*d;
  return ret;
}

int main(){
  double D, V;
  while(cin >> D >> V,!(D==0&&V==0)){
    double volume = D*D*PI/4*D-V;
    if(volume==0){
      printf("%.3lf\n",D);
    }
    else{
      double L = 0, R = D;
      for(int i=0;i<ITER;i++){
        double mid = (L+R)/2;
        if(calc(D,mid)<volume)
          L = mid;
        else
          R = mid;
      }
      printf("%.3lf\n",(L+R)/2);
    }
  }
  return 0;
}
