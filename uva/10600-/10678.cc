#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double PI = acos(-1.0);

double dist, len;

void read(){
  cin >> dist >> len;
}

void work(){
  double a = len/2, b = sqrt((len/2)*(len/2)-(dist/2)*(dist/2));
  printf("%.3lf\n",PI*a*b);
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
