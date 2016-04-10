#include<iostream>
#include<cstdio>
#include<cmath>

#define PI acos(-1.0)

using namespace std;

double radius, nDiv;

bool read(){
  if(!(cin >> radius >> nDiv)) return false;
  return true;
}

void work(){
  
  printf("%.3lf\n",nDiv*radius*radius*sin(2*PI/nDiv)/2);
  
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
