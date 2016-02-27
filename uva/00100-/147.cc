#include<iostream>
#include<cstdio>
using namespace std;

long long tbl[2][30001];

void makeTbl(){
  int money[]={5,10,20,50,100,200,500,1000,2000,5000,10000};

  for(int i=0;i<30001;i++)
    tbl[0][i] = 0;
  tbl[0][0] = 1;

  for(int k=0;k<11;k++){
    for(int i=0;i<30001;i++)
      tbl[1][i] = tbl[0][i] + (i>=money[k] ? tbl[1][i-money[k]] : 0);

    for(int i=0;i<30001;i++)
      tbl[0][i] = tbl[1][i];
  }
}

int main(){
  makeTbl();

  double n;
  while(cin>>n,n>1e-8){
    int intN = (int)(n*100+1e-8);
    printf("%6.2lf%17lld\n",n,tbl[0][intN]);
  }
  
  return 0;
}