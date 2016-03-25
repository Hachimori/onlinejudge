#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

double a, b, c;

double area(double A, double B, double C){
  double s = (A+B+C)/2;	
  return sqrt(s*(s-A)*(s-B)*(s-C));
}

void work(){
  double A = -a*a*4/9+b*b*8/9+c*c*8/9;
  double B =  a*a*8/9-b*b*4/9+c*c*8/9;
  double C =  a*a*8/9+b*b*8/9-c*c*4/9;
  if(A<=0 || B<=0 || C<=0){
    cout << "-1.000" << endl;
    return;
  }

  A = sqrt(A);
  B = sqrt(B);
  C = sqrt(C);
  if(A+B+C<=2*max(A,max(B,C))){
    cout << "-1.000" << endl;
    return;
  }

  printf("%.3lf\n",area(A,B,C));
}

int main(){
  while(cin >> a >> b >> c)
    work();

  return 0;
}
