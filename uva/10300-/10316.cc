#include<iostream>
#include<cmath>
#include<cstdio>
#define LE(x,y) (x<=y+1e-7)
using namespace std;
const double PI = acos(-1.0);
const int BUF = 1005;

class Point{
public:
  double x,y,z;
  Point(){}
  Point(double lati, double logn){
    x = cos(logn/180*PI)*cos(lati/180*PI);
    y = sin(logn/180*PI)*cos(lati/180*PI);
    z = sin(lati/180*PI);
  }

  double dist(Point p){
    return sq(x-p.x)+sq(y-p.y)+sq(z-p.z);
  }
  
  double sq(double v){
    return v*v;
  }
};

int nPt;
double lati[BUF], logn[BUF];
Point pt[BUF];

bool read(){
  if(!(cin >> nPt)) return false;
  for(int i=0;i<nPt;i++){
    cin >> lati[i] >> logn[i];
    pt[i] = Point(lati[i],logn[i]);
  }
  return true;
}

void work(){
  int minPt;
  double minV = 1<<30;
  for(int i=0;i<nPt;i++){
    double maxV = 0;
    for(int j=0;j<nPt;j++)
      maxV = max(maxV,pt[i].dist(pt[j]));
    if(LE(maxV,minV)){
      minPt = i;
      minV = maxV;
    }
  }
  printf("%.2lf %.2lf\n",lati[minPt],logn[minPt]);
}

int main(){
  while(read()) work();
  return 0;
}
