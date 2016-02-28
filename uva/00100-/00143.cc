#include<iostream>
#include<complex>
#include<cstdio>
#define EPS (1.0e-8)
using namespace std;
typedef complex<double> Point;

double dot(Point a, Point b){
  return real(conj(a)*b);
}

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

Point pt[3];

bool read(){
  for(int i=0;i<3;i++){
    double x, y;
    cin >> x >> y;
    pt[i] = Point(x,y);
  }

  return !(norm(pt[0]-pt[1])<EPS && norm(pt[1]-pt[2])<EPS && 
           norm(pt[2]-Point(0,0))<EPS);
}

bool onSegment(Point s1, Point s2, Point p){
  Point d1 = s2-s1, d2 = p-s1;
  return (fabs(cross(d1,d2))<EPS && dot(d1,d2)>-EPS && norm(d1)>norm(d2)-EPS); 
}

bool isInside(Point p){
  int sign = 0;
  for(int i=0;i<3;i++){
    Point &cur = pt[i], &nex = pt[(i+1)%3];
    double tmp =  cross(nex-cur,p-cur);
    if(tmp>EPS){
      if(sign==-1)
        return false;
      else
        sign = 1;
    }
    else if(tmp<-EPS){
      if(sign==1)
        return false;
      else
        sign = -1;
    }
  }
  
  return true;
}

void work(){
  int cnt = 0;

  if(fabs(cross(pt[1]-pt[0],pt[2]-pt[0])/2)<EPS)
    for(int x=1;x<=99;x++)
      for(int y=1;y<=99;y++)
        for(int i=0;i<3;i++){
          if(onSegment(pt[i],pt[(i+1)%3],Point(x,y))){
            cnt++;
            break;
          }
        }
  else
    for(int x=1;x<=99;x++)
      for(int y=1;y<=99;y++)
        cnt += isInside(Point(x,y));

  printf("%4d\n",cnt);
}

int main(){
  while(read())
    work();
  
  return 0;
}