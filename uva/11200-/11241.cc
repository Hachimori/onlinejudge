#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;


double getH(double d, double t){
  double e = 6.11*exp(5417.7530*(1/273.16-1/(d+273.16)));
  return 0.5555*(e-10.0)+t;
}

double getD(double h, double t){
  double e = (h-t)/0.5555+10.0;
  return 1.0/(1.0/273.16-log(e/6.11)/5417.7530)-273.16;
}

double getT(double d, double h){
  double e = 6.11*exp(5417.7530*(1/273.16-1/(d+273.16)));
  return h-0.5555*(e-10.0);
}

int main(){
  while(true){
    char ch1, ch2;
    double a, b;
    cin >> ch1; if(ch1=='E') break;

    cin >> a >> ch2 >> b;

    if(ch1>ch2){
      swap(ch1,ch2);
      swap(a,b);
    }
    double d, h, t;

    if(ch1=='D' && ch2=='T'){
      d = a, h = getH(a,b), t = b;
    }
    if(ch1=='D' && ch2=='H'){
      d = a, h = b, t = getT(a,b);
    }
    if(ch1=='H' && ch2=='T'){
      d = getD(a,b), h = a, t = b;
    }

    printf("T %.1lf D %.1lf H %.1lf\n",t,d,h);
  }
  
  return 0;
}
