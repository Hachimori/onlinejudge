#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  double a, b, c;
  while(cin >> a >> b >> c){
    double s = (a+b+c)/2;
    double ans = a==0 || b==0 || c==0 ? 0 : sqrt((s-a)*(s-b)*(s-c)/s);
    printf("The radius of the round table is: %.3lf\n",ans);
  }
  return 0;
}
