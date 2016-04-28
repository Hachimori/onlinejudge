#include<iostream>
#include<cstdio>
#include<cmath>
#define EPS (1.0e-9)
using namespace std;

int main(){
  for(int a=1;a*4<=2000;a++)
    for(int b=a;a+b*3<=2000;b++)
      for(int c=b;a+b+c*2<=2000;c++){
        
        double d = 1000000.0*(a+b+c)/(1.0*a*b*c-1000000);
        if(d<c-EPS) continue;
        
        if(fabs(d-(int)(d+0.5))<EPS && a+b+c+d<=2000+EPS)
          printf("%.2lf %.2lf %.2lf %.2lf\n",a/100.0,b/100.0,c/100.0,d/100);
      }
  
  return 0;
}
