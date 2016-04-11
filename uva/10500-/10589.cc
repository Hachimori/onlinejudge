#include<iostream>
#include<cstdio>
#define LE(x,y) ((x)<=(y))
using namespace std;
const int BUF = 1000005;

int nPt;
double x[BUF], y[BUF], a;

bool read(){
  cin >> nPt >> a;
  if(nPt==0) return false;
  for(int i=0;i<nPt;i++)
    scanf("%lf%lf",&x[i],&y[i]);
  return true;
}

void work(){
  int cnt = 0;
  for(int i=0;i<nPt;i++){
    double xx = x[i], yy = y[i];
    cnt += xx*xx+yy*yy<=a*a && (xx-a)*(xx-a)+yy*yy<=a*a &&
           xx*xx+(yy-a)*(yy-a)<=a*a && (xx-a)*(xx-a)+(yy-a)*(yy-a)<=a*a;
  }
  printf("%.5lf\n",cnt*a*a/nPt);
}

int main(){
  while(read()) work();
  return 0;
}
