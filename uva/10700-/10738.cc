#include<iostream>
using namespace std;
const int BUF = 1000005;

int mu(int n){
  bool isSquareFree = true;
  int nPrimeFactor = 0;
  for(int i=2;i*i<=n;i++)
    if(n%i==0){
      int cnt = 0;
      while(n%i==0){
        n /= i;
        cnt++;
      }
      if(cnt>=2) isSquareFree = false; 
      nPrimeFactor++;
    }
  if(n>1) nPrimeFactor++;
  return !isSquareFree ? 0 : nPrimeFactor%2==0 ? 1 : -1;
}

int main(){
  static int tbl[BUF];
  tbl[0] = 0;
  tbl[1] = 1;
  for(int i=2;i<BUF;i++)
    tbl[i] = mu(i)+tbl[i-1];

  int n;
  while(cin >> n, n)
    printf("%8d%8d%8d\n",n,tbl[n]-tbl[n-1],tbl[n]);

  return 0;
}
