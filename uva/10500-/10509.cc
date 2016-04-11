#include<iostream>
#include<cstdio>
using namespace std;

double val;

bool read(){
  cin >> val;
  return val>0.0;
}

void work(){
  int a;
  for(a=1;a*a*a<=val;a++);
  a--;
  printf("%.4lf\n",a+(val-a*a*a)/(3*a*a));
}

int main(){
  while(read()) work();
  return 0;
}
