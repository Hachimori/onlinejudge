#include<iostream>
#include<cstdio>
using namespace std;

double a, b, c;

bool read(){
  return cin >> a >> b >> c;
}

void work(){
  double ans = 0;
  ans += a/(a+b)*(b/(a+b-c-1));
  ans += b/(a+b)*((b-1)/(a+b-c-1));
  printf("%.5lf\n",ans);
}

int main(){
  while(read()) work();
  return 0;
}
