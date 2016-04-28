#include<iostream>
#define MOD 100000000
using namespace std;
typedef unsigned long long integer;

integer num;

bool read(){
  cin >> num;
  return num!=0;
}

integer mypow(integer n, int p){
  if(n==0) return 1;
  if(n==1) return p;
  
  integer t = mypow(n/2,p);

  return ((t*t%MOD)*(n%2==1?p:1))%MOD;
} 

void work(){
  integer term = (num+1)/2;

  integer L = 0, R = (1ULL<<32);
  while(L!=R){
    integer mid = (L+R)/2;
    if(2*mid*mid+2*mid>=term)
      R = mid;
    else
      (L==mid ? R : L) = mid;
  }

  integer n = L;
  integer sum = 0;
  /*
  n++;
  if(n>0){
    sum += 8;
    sum = (sum+MOD-n*mypow(n+2,2)%MOD)%MOD;
    sum = (sum+(n-1)*mypow(n+3,2)%MOD)%MOD;
    sum = (sum+MOD-mypow(n,2))%MOD;
    sum = (sum+2)%MOD;
  }n--;
  */
  {
    integer a = n, b = n+1, c = (2*n+1);
    
    if(a%3==0) a/=3;
    else if(b%3==0) b/=3;
    else if(c%3==0) c/=3;
    sum = (sum+4*a%MOD*b%MOD*c)%MOD;
    sum = (sum+MOD-n%MOD*(n+1)%MOD)%MOD;
  }
  
  //cout << n << ' ' << sum << endl;

  integer bgn = 2*n*n+2*n, end = 2*(n+1)*(n+1)+2*(n+1);
  
  term--; // make term 0-origin
  if(term<(bgn+end)/2){
    // add less than half
    sum = (sum+(term-bgn+1)%MOD*(1+n*2)%MOD)%MOD;
  }
  else{
    // add half and more
    sum = (sum+(end-bgn)/2%MOD*(1+n*2)%MOD)%MOD;
    sum = (sum+(term-(end+bgn)/2+1)%MOD*(2+n*2)%MOD)%MOD;
  }

  cout << sum << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
