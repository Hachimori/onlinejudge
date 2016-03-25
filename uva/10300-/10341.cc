#include<iostream>
#include<cmath>
#include<cstdio>
#define NDIV 1000
using namespace std;

double p,q,r,s,t,u;

bool read(){
  return cin >> p >> q >> r >> s >> t >> u;
}

double f(double x){
  return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

double rec(double L, double R, int step){
  if(step==2) return (L+R)/2;

  double val[NDIV+1];
  for(int i=0;i<=NDIV;i++)
    val[i] = f(L+(R-L)*i/NDIV);

  for(int i=0;i<NDIV;i++)
    if((val[i]<=0 && 0<=val[i+1]) || (val[i]>=0 && 0>=val[i+1]))
      return rec(L+(R-L)*i/NDIV,L+(R-L)*(i+1)/NDIV,step+1);

  return -1;
}

void work(){
  double ans = rec(0,1,0);
  if(ans<0)
    cout << "No solution" << endl;
  else
    printf("%.4lf\n",ans);
}

int main(){
  while(read()) work();
  return 0;
}
