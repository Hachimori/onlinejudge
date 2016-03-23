#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int ITER = 100;
const double PI = acos(-1.0);


double radius;
int N;

bool read(){
  if(!(cin >> radius >> N)) return false;
  return true;
}

double sectorArea(double r){
  double theta = PI-2*PI/N;
  return r*r*theta/2;
}

double circleArea(double r){
  return r*r*PI;
}

double triArea(double r){
  double side = sqrt(2*r*r/(1-cos(2*PI/N)));
  return side*side*sin(2*PI/N)/2;
}

double f(double r){
  return r+sqrt(2*r*r/(1-cos(2*PI/N)));
}


void work(){
  if(N==1){
    printf("%.10lf %.10lf %.10lf\n",radius,0.0,0.0);
    return;
  }
  if(N==2){
    printf("%.10lf %.10lf %.10lf\n",radius/2,0.0,
                                    circleArea(radius)-circleArea(radius/2)*2);
    return;
  }

  double L = 0, R = radius;
  for(int loop=0;loop<ITER;loop++){
    double mid = (L+R)/2;
    if(f(mid)<radius)
      L = mid;
    else
      R = mid;
  }

  double r = (L+R)/2;
  double I = (triArea(r)-sectorArea(r))*N;
  double E = circleArea(radius)-circleArea(r)*N-I;
  printf("%.10lf %.10lf %.10lf\n",r,I,E);
}


int main(){
  while(read()) work();
  return 0;
}
