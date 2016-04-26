#include<iostream>
#include<algorithm>
#include<complex>
#include<cstdio>
#define POINT 505
using namespace std;
typedef complex<double> Point;
const double PI = acos(-1.0);

int nPt;
double radius;
Point pt[POINT];

bool read(){
  cin >> nPt >> radius;
  if(nPt==0 && radius==0) return false;
  
  double theta[POINT];
  for(int i=0;i<nPt;i++)
    cin >> theta[i];
  sort(theta,theta+nPt);
  
  for(int i=0;i<nPt;i++)
    pt[i] = polar(radius,theta[i]*2*PI/360);

  return true;
}

double calcArea(){
  double sum = 0;

  for(int i=0;i<nPt;i++)
    sum += (pt[i].imag()+pt[(i+1)%nPt].imag())*
           (pt[i].real()-pt[(i+1)%nPt].real());

  return fabs(sum)/2;
}

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

double calc(Point a, Point b, Point c){
  return cross(b-a,c-a)/2;
}

void work(){
  double area = calcArea();
  
  double sum = 0;
  for(int i=1,toMul=nPt-2;i<nPt;i++,toMul-=2)
    for(int j=0;j+i<nPt;j++)
      sum += toMul*calc(Point(0,0),pt[j],pt[i+j]);

  cout << (long long)(sum+0.5) << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
