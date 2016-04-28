#include<iostream>
using namespace std;

int p, a;

bool read(){
  cin >> p >> a;
  return p>0 && a>0;
}

bool isPrime(int n){
  for(int i=2;i*i<=n;i++)
    if(n%i==0)
      return false;
  return true;
}

int modPow(int v, int n){
  if(n==0) return 1;
  long long t = modPow(v,n/2);
  return n&1 ? v*t%p*t%p : t*t%p;
}

void work(){
  cout << (!isPrime(p) && modPow(a,p)==a%p ? "yes" : "no") << endl;
}

int main(){
  while(read()) work();
  return 0;
}
