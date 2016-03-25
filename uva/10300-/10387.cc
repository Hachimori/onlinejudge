#include<iostream>
#include<cmath>
using namespace std;

int main(){
  const double PI = acos(-1);
  while(1){
    int x, y, time, xMul, yMul;
    cin >> x >> y >> time >> xMul >> yMul;
    if((x|y|time|xMul|yMul)==0) break;
    double xx = x*xMul, yy = y*yMul;
    double sec = 1.0*sqrt(xx*xx+yy*yy)/time;
    double arg = atan2(yy,xx);
    printf("%.2lf %.2lf\n",arg/PI*180,sec);
  }
  return 0;
}
