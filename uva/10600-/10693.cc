#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
  double L, f;
  while(cin >> L >> f, !(L==0 && f==0)){
    double v = sqrt(2*f*L);
    double volume = (v*60*60/(L*2));
    printf("%.8lf %.8lf\n",v,volume);
  }
  return 0;
}
