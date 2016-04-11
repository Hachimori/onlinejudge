#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double PI = acos(-1.0);
const int BUF = 100;

double f(double r){
  return r*r*PI;
}

bool valid(double a){
  return fabs(a-int(a+0.5))<1e-6;
}

void ans(double a, double b){
  if(a<0 || b<0)
    cout << "Impossible." << endl;
  else
    printf("%.4lf\n",f(a+b)-f(a)-f(b));
}

int main(){
  int cases;
  cin >> cases;
  char buf[BUF];
  gets(buf);
  for(int i=0;i<cases;i++){
    gets(buf);
    int a, b;
    int ret = sscanf(buf,"%d%d",&a,&b);
    if(ret==1)
      ans(a*0.25,a*0.25);
    else
      ans(a,b);
  }
  return 0;
}
