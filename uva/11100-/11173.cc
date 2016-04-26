#include<iostream>
#include<cstdio>
using namespace std;

long long N, K;

void read(){
  scanf("%lld%lld",&N,&K);
}

void work(){
  long long sum = 0;
  for(long long i=0,p=4;i<N;i++,p<<=1){
    if((p>>2)<=K%p && K%p<=p-(p>>2)-1)
      sum += (p>>2);
  }
  
  printf("%lld\n",sum);
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
