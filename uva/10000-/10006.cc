#include<iostream>
using namespace std;

bool isPrime(int n){
  if(n==1) return false;
  for(int i=2;i*i<=n;i++)
    if(n%i==0)
      return false;
  return true;
}

int modPow(int p, int n, int mod){
  if(n==0) return 1;
  long long t = modPow(p,n/2,mod);
  return n&1 ? t*t%mod*p%mod : t*t%mod;
}

bool fermatPassed(int n){
  for(int i=2;i<n;i++)
    if(modPow(i,n,n)!=i)
      return false;
  return true;
}

int main(){
  int n;
  while(cin >> n, n){
    if(!isPrime(n) && fermatPassed(n))
      cout << "The number " << n << " is a Carmichael number." << endl;
    else
      cout << n << " is normal." << endl;    
  }
  return 0;
}
