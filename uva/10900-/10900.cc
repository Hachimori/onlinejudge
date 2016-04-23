#include<iostream>
#include<cstdio>
using namespace std;

int n;
double t;

bool read(){
  cin >> n >> t;
  return n!=0;
}

double f(int n, double a){
  if(n==0) return a;
  double pre = f(n-1,a*2);
  
  if(t<a/pre+1.0e-9){
    double x = a/pre;
    return ((x-t)*a+(1-x*x)*pre/2)/(1-t);
  }
  else 
    return (1+t)*pre/2;
}

void work(){
  printf("%.3lf\n",f(n,1));
}

int main(){
  while(read())
    work();
  
  return 0;
}
