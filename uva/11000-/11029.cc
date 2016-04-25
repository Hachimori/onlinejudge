#include<iostream>
#include<string>
#include<cstdio>
#define MOD 1000
#define EPS (1.0e-8)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define GE(x,y) (GT(x,y) || EQ(x,y))
using namespace std;
typedef long long ll;

ll mul, nPow;

void read(){
  cin >> mul >> nPow;
}

double getHead(double p, ll n){
  while(GE(p,10)) p /= 10;
  if(n==0) return 1;
  double t = getHead(p,n/2);
  while(GE(t,10)) t /= 10;
  return (n%2==0 ? t*t : t*t*p);
}

ll getTail(ll p, ll n){
  if(n==0) return 1;
  ll t = getTail(p,n/2)%MOD;
  return (n%2==0 ? t*t : t*t*p)%MOD;
}

void work(){
  double head = getHead(mul,nPow);
  while(GE(head,10)) head /= 10;

  ll tail = getTail(mul,nPow);

  printf("%d...%.3lld\n",(int)(head*100),tail);
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
