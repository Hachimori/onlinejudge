#include<iostream>
#include<cstdio>
using namespace std;

int N;

bool read(){
  scanf("%d",&N);
  return N!=0;
}

int eulerPhi(int n){
  int ret = n;
  for(int i=2;i*i<=n;i++)
    if(n%i==0){
      while(n%i==0) n /= i;
      ret -= ret/i;
    }
  if(n!=1) ret -= ret/n;
  return ret;
}

void work(){
  printf("%d\n",(N==1 ? 0 : eulerPhi(N)));
}

int main(){
  while(read())
    work();
  
  return 0;
}
