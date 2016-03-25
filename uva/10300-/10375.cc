#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int NPRIME = 1000;

int a, b, c, d;

bool read(){
  return cin >> a >> b >> c >> d;
}

void work(){
  long double ans = 1;
  
  b = min(b,a-b);
  for(int i=1;i<=b;i++){
    ans *= a-i+1;
    ans /= i;
  }

  d = min(d,c-d);
  for(int i=1;i<=d;i++){
    ans /= c-i+1;
    ans *= i;
  }

  printf("%.5Lf\n",ans);
}

int main(){
  while(read())
    work();
  
  return 0;
}
