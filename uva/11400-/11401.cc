#include<iostream>
#include<cstdio>
using namespace std;
const int BUF = 1000005;

int main(){
  static long long tbl[BUF];
  tbl[3] = 0;
  for(int i=4;i<BUF;i+=2){
    tbl[i  ] = tbl[i-1]+(i-2)/2;
    tbl[i+1] = tbl[i  ]+(i-2)/2;    
  }

  for(int i=4;i<BUF;i++)
    tbl[i] += tbl[i-1];
  
  int n;
  while(scanf("%d",&n), n>=3) printf("%lld\n",tbl[n]);

  return 0;
}
