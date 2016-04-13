#include<iostream>
#include<cstdio>
#define BUF 35
using namespace std;
typedef long long integer;

int num, nDiv;

void read(){
  cin >> num >> nDiv;
}

integer gcd(integer a, integer b){
  return b==0 ? a : gcd(b,a%b);
}

void rec(int sum, int nTook, int last, integer mul, int took[BUF]){
  if(sum==num && nTook==nDiv){
    for(int i=0;i<nDiv;i++){
      if(i) printf(" ");
      printf("%d",took[i]);
    }
    printf("\n");
    return;
  }
  if(nTook==nDiv) return;

  for(int i=last;i<=num-sum;i++){
    if(gcd(mul,i)!=1) continue;
    took[nTook] = i;
    rec(sum+i,nTook+1,i,mul*i,took);
  }
}

void work(int cases){
  cout << "Case " << cases << ":" << endl;

  int took[BUF];
  rec(0,0,1,1,took);
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  
  return 0;
}
