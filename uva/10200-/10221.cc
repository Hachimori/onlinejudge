#include<iostream>
#include<cstdio>
#include<complex>
using namespace std;
typedef complex<double> Point;
const double PI = acos(-1.0);

string s;
double r, angle;

bool read(){
  return cin >> r >> angle >> s;
}

void work(){
  r += 6440;
  angle = s=="deg" ? angle*PI/180 : angle*PI/180/60;
  angle = angle>PI ? 2*PI-angle: angle;

  Point pt[2];
  pt[0] = Point(r,0);
  pt[1] = polar(r,angle);

  printf("%.6lf %.6lf\n",r*angle,abs(pt[0]-pt[1]));
}

int main(){
  while(read()) work();
  return 0;
}
