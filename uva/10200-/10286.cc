#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double PI = acos(-1.0);

int main(){
  double v;
  while(cin >> v)
    printf("%.10f\n",v*sin(PI*108/180)/sin(PI*63/180));
  return 0;
}
