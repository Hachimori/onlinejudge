#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;


int nMan, id;
double p;

void read(){
  cin >> nMan >> p >> id;
}


void work(){
  if(p==0)
    printf("0.0000\n");
  else if(p==1 && id==1)
    printf("1.0000\n");
  else if(p==1 && id!=1)
    printf("0.0000\n");
  else
    printf("%.4lf\n",pow(1-p,id-1)*p/(1-pow(1-p,nMan)));
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
