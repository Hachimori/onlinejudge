#include<iostream>
#include<cmath>
#include<cstdio>

#define PI 3.14159265358979323846

using namespace std;

double a;

bool read(){
  if(!(cin >> a)) return false;

  return true;
}

void work(){
  double areaStripe = a*a-a*a/2*(PI/3+sqrt(3.0)/2);
  double areaDot    = a*a-a*a*PI/4-2*areaStripe;
  double areaRemain = a*a-areaStripe*4-areaDot*4;
  
  printf("%.3f %.3f %.3f\n",areaRemain,areaDot*4,areaStripe*4);

}

int main(){
  
  while(read())
    work();
  
  return 0;
}
