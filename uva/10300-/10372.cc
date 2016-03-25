#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const int BUF = 105, ITER = 100;
const double PI = acos(-1.0), g = -9.8;


int nPt;
double x[BUF], y[BUF];

bool read(){
  if(!(cin >> nPt)) return false;
  
  double tx[BUF], ty[BUF];
  for(int i=0;i<nPt;i++)
    cin >> ty[i] >> tx[i];
  
  x[0] = y[0] = y[nPt] = 0;
  for(int i=1;i<nPt;i++){
    x[i] = x[i-1]+tx[i-1];
    y[i] = max(ty[i-1],ty[i]);
  }
  x[nPt++] = x[nPt-1]+tx[nPt-1];
  return true;
}

bool canFly(double arg){
  double speed = sqrt(-g*x[nPt-1]/(2*cos(arg)*sin(arg)));
  for(int i=0;i<nPt;i++){
    double t = x[i]/(cos(arg)*speed);
    double Y = sin(arg)*speed*t + 0.5*g*t*t;
    if(y[i]>Y+1e-8) return false;
  }
  return true;
}

void work(){
  double L = 0, R = PI/2;
  for(int i=0;i<ITER;i++){
    double mid = (L+R)/2;
    if(canFly(mid))
      R = mid;
    else
      L = mid;
  }
  
  double arg = (L+R)/2, speed = sqrt(-g*x[nPt-1]/(2*cos(arg)*sin(arg)));
  printf("%.2lf %.2lf\n",arg/PI*180,speed);
}

int main(){
  while(read()) work();
  return 0;
}
