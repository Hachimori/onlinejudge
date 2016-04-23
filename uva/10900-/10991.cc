//Ро: Circular Sector

#include<iostream>
#include<cstdio>
#include<cmath>
#define PI acos(-1.0)
using namespace std;

double r1, r2, r3;

void read(){
  cin >> r1 >> r2 >> r3;
}

double triArea(double a, double b, double c){
  double s = (a+b+c)/2;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}

double sectorArea(double r, double theta){
  return r*r*PI*(theta/(2*PI));
}

void work(){
  double A = r1+r2, B = r1+r3, C = r2+r3;
  double tri = triArea(A,B,C);
  double sect1 = sectorArea(r1,acos((C*C-A*A-B*B)/(-2*A*B)));
  double sect2 = sectorArea(r2,acos((B*B-C*C-A*A)/(-2*C*A)));
  double sect3 = sectorArea(r3,acos((A*A-B*B-C*C)/(-2*B*C)));

  printf("%.6lf\n",tri-sect1-sect2-sect3);
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
