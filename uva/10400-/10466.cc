#include<iostream>
#include<complex>
#include<cstdio>
using namespace std;
typedef complex<double> Point;
const int BUF = 55;
const double PI = acos(-1.0);

int nBall, timePass, dist[BUF], rotTime[BUF];

bool read(){
  if(!(cin >> nBall >> timePass)) return false;
  for(int i=0;i<nBall;i++)
    cin >> dist[i] >> rotTime[i];
  return true;
}

void work(){
  Point pt[BUF];
  pt[0] = Point(0,0);
  for(int i=0;i<nBall;i++){
    double theta = 2*PI*timePass/rotTime[i];
    pt[i+1] = (Point(dist[i],0))*polar(1.0,theta)+pt[i];
  }
  for(int i=0;i<nBall;i++){
    if(i) cout << ' ';
    printf("%.4lf",abs(pt[i+1]));
  }cout << endl;
}

int main(){
  while(read())
    work();
}
