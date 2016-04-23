#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

class Point{
public:
  int x, y;

  Point(){}
  Point(int x, int y): x(x), y(y){}

  double dist(const Point &p){
    return sqrt(1.0*(x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
  }
};

int src, dst;

bool read(){
  cin >> src >> dst;
  return !(src==-1 && dst==-1);
}

int funcU(int n){
  return 2*n*n-n;
}
int funcR(int n){
  return 2*n*n;
}
int funcD(int n){
  return 2*n*n+n;
}
int funcL(int n){
  return 2*n*n+2*n;
}

Point convert(int num){
  if(num==0) return Point(0,0);
  
  for(int i=1;;i++){
    if(funcU(i)<=num && num<funcR(i)){
      int nMov = num-funcU(i);
      return Point(0+nMov,i-nMov);
    }
    if(funcR(i)<=num && num<funcD(i)){
      int nMov = num-funcR(i);
      return Point(i-nMov,-nMov);
    }
    if(funcD(i)<=num && num<funcL(i)){
      int nMov = num-funcD(i);
      return Point(-nMov,-i+nMov);
    }
    if(funcL(i)<=num && num<funcU(i+1)){
      int nMov = num-funcL(i);
      if(nMov==0) return Point(-i,0);
      nMov--;
      return Point(-i+nMov,1+nMov);
    }
  }
}

void work(){
  Point p1 = convert(src), p2 = convert(dst);
  printf("%.2lf\n",p1.dist(p2));
}

int main(){
  while(read())
    work();
  
  return 0;
}
