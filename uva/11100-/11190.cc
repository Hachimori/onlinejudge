#include<iostream>
#include<cmath>
#include<cstdio>
#define EPS (1.0e-9)
#define RANGE 1005
using namespace std; 

class Data{
public:
  double v;
  long long p;

  Data(){}
  Data(double v, long long p): v(v), p(p){}
  
  Data operator+ (Data d){
    if(p<d.p)
      return Data(d.v+v*pow(0.1,1.0*d.p-p),d.p);
    else
      return Data(v+d.v*pow(0.1,1.0*p-d.p),p);
  }
};

int low, high, nPow;

bool read(){
  scanf("%d%d%d",&low,&high,&nPow);
  if(low==-1 && high==-1 && nPow==-1) return false;
  return true;
}

double power(double p, int n){
  if(n==0) return 1.0;
  if(n==1) return p;

  double ret = power(p,n/2);
  while(ret>10) ret /= 10;
  
  return (n%2 ? ret*ret*p : ret*ret);
}

void work(int cases){
  Data ans(0,0);

  for(int i=low;i<=high;i++){
    if(i==0) continue;

    double p = 1.0*i;
    while(p>10) p /= 10;

    double ret = power(p,nPow);
    while(ret>10) ret /= 10;

    long long nDigit = (long long)(floor(nPow*log10(1.0*i)));

    ans = ans+Data(ret,nDigit);

    while(ans.v>10){
      ans.v /= 10;
      ans.p += 1;
    }
  }


  printf("Case %.4d",cases);
  
  if(fabs(ans.v)<EPS)
    printf(": %.6lfe%.10lld\n",ans.v,1LL);
  else{
    printf(": %.6lfe%.10lld\n",ans.v/10,ans.p+1);
  }
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}