#include<iostream>
#include<cstdio>
#include<cassert>
#define BUF 1100000
using namespace std;

bool isCompositePrime[BUF], isM[BUF];

void makeTable(){
  for(int i=0;i<BUF;i++)
    isM[i] = false;

  for(int i=2;i*i<BUF;i++)
    if(!isM[i])
      for(int j=i*2;j<BUF;j+=i)
	isM[j] = true;
  
  static int nM = 0, M[BUF];
  for(int i=0;i<BUF;i++)
    if(isM[i])
      M[nM++] = i;

  for(int i=0;i<BUF;i++)
    isCompositePrime[i] = true;
  isCompositePrime[0] = isCompositePrime[1] = false;
  isCompositePrime[2] = isCompositePrime[3] = false;
  
  for(int i=0;M[i]*2<BUF;i++)
    if(isCompositePrime[M[i]])
      for(int j=M[i]*2;j<BUF;j+=M[i])
	isCompositePrime[j] = false;
}

bool work(){
  int nQuery;
  if(scanf("%d",&nQuery)==EOF) return false;
  
  int ans = 0;
  for(int i=0;i<nQuery;i++){
    int num;
    if(scanf("%d",&num)==EOF) return false;

    ans += (isCompositePrime[num] && isM[num]);
  }
  
  printf("%d\n",ans);

  return true;
}

int main(){
  makeTable();
  
  while(work());

  return 0;
}
