#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

const double PI = acos(-1.0);

double calc(double w, double h){
  double r = min(w/2,h/(2+2*PI));
  double R = w/(2*PI);

  return max(R*R*PI*(h-2*R),r*r*PI*w);
}

int main(){
  while(true){
    int h, w;
    cin >> w >> h;
    if(h==0 && w==0) break;
    
    printf("%.3lf\n",calc(w,h));
  }
  
  return 0;
}
