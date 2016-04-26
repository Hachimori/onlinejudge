// “àSA“àÚ‰~‚Ì”¼Œa
// http://www.geisya.or.jp/~mwm48961/kou2/s1sc203.htm
// http://w3e.kanazawa-it.ac.jp/math/category/kika/heimenkika/naisinn.html
//
// ŠOÚ‰~‚Ì”¼Œa
// ƒ}ƒOƒƒEƒqƒ‹ p6

#include<iostream>
#include<cmath>
#include<cstdio>
#define PI acos(-1.0)
using namespace std;

double A, B, C;

bool read(){
  if(!(cin >> A >> B >> C)) return false;
  return true;
}

double area(double a, double b, double c){
  double s = (a+b+c)/2;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}

void work(){
  double r = area(A,B,C)/((A+B+C)/2);
  double R = A*B*C/(4*area(A,B,C));

  printf("%.4lf %.4lf %.4lf\n",R*R*PI-area(A,B,C),
	                       area(A,B,C)-r*r*PI,
	                       r*r*PI);
}

int main(){
  while(read())
    work();
  return 0;
}
