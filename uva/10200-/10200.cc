#include<iostream>
#include<numeric>
using namespace std;
const int BUF = 10001;

int f(int a){
  return a*a+a+41;
}

bool chkPrime(int n){
  for(int i=2;i*i<=n;i++)
    if(n%i==0)
      return false;
  return true;
}

int main(){
  bool isPrime[BUF];
  for(int i=0;i<BUF;i++) isPrime[i] = chkPrime(f(i));

  int a, b;
  while(cin >> a >> b)
    printf("%.2lf\n",100.0*accumulate(isPrime+a,isPrime+b+1,0)/(b-a+1)+1e-6);
  
  return 0;
}
