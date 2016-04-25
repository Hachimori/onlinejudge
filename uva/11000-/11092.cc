#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

class Point{
public:
  double x, y;
  
  Point(){}
  Point(double x, double y): x(x), y(y){}

  double dist(Point &p){
    return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
  }
};

int A, B;
double dx = 0.5, dy = sqrt(3.0)/2;

bool read(){
  return cin >> A >> B;
}

int funcR(int n){
  return 3*n*n-2*n;
}

int funcRU(int n){
  return 3*n*n-n;
}

int funcLU(int n){
  return 3*n*n;
}

int funcL(int n){
  return 3*n*n+n;
}

int funcLD(int n){
  return 3*n*n+2*n;
}

int funcRD(int n){
  return 3*n*n+3*n+1;
}

Point convert(int num){
  if(num==0) return Point(0,0);

  for(int i=1;;i++){
    if(funcR(i)<=num && num<funcRU(i)){
      int mov = num-funcR(i);
      return Point(i-mov*dx,mov*dy);
    }
    if(funcRU(i)<=num && num<funcLU(i)){
      int mov = num-funcRU(i);
      return Point(i*dx-mov,i*dy);
    }
    if(funcLU(i)<=num && num<funcL(i)){
      int mov = num-funcLU(i);
      return Point((-i-mov)*dx,(i-mov)*dy);
    }
    if(funcL(i)<=num && num<funcLD(i)){
      int mov = num-funcL(i);
      return Point(-i+mov*dx,-mov*dy);
    }
    if(funcLD(i)<=num && num<funcRD(i)){
      int mov = num-funcLD(i);
      return Point(-i*dx+mov,-i*dy);
    }
    if(funcRD(i)<=num && num<funcR(i+1)){
      int mov = num-funcRD(i);
      return Point((i+mov)*dx+1,(-i+mov)*dy);
    }
  }
}

void work(){
  Point ptA = convert(A), ptB = convert(B);

  printf("%.3lf %.3lf\n",fabs(1.0*A-B),ptA.dist(ptB));
}

int main(){
  while(read())
    work();
  
  return 0;
}
