#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double PI = acos(-1);

double r, n;

bool read(){
  cin >> r >> n;
  return !(r==0 && n==0);
}

void work(int cases){
  cout << "Case " << cases << ":" << endl;
  for(int i=1;i<=10;i++)
    printf("%.5lf\n",(acos((n/i)/(2*PI*r))-n/r)/PI*180);
  
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  return 0;
}
