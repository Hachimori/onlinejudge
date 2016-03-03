#include<iostream>
#include<cstdio>
#include<cmath>

#define PI 3.14159265358979323846

using namespace std;

double hour, minute;

class Point{
public:

  double x, y;

  Point(){}
  Point(double x, double y): x(x), y(y) {}

  double operator* ( Point p ){
    return x*p.x+y*p.y;
  }

};

bool read(){

  char c;
  cin >> hour >> c >> minute;

  if(hour==0 && minute==0) return false;
  
  
  return true;
}

void work(){
  
  Point p1,p2;

  p1 = Point(sin(minute*2*PI/60),cos(minute*2*PI/60));
  p2 = Point(sin(hour*2*PI/12+minute*5*2*PI/60/60),cos(hour*2*PI/12+minute*5*2*PI/60/60));
  
  printf("%.3lf\n",acos(p1*p2)/PI*180);
}

int main(){

  while(read())
    work();

  return 0;
}
