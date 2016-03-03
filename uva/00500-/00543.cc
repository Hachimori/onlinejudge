#include<iostream>
using namespace std;
const int PRIME = 1000005;

int n, nPrime, prime[PRIME];
bool isPrime[PRIME];

void makePrime(){
  for(int i=0;i<PRIME;i++) isPrime[i] = true;
  for(int i=2;i*i<PRIME;i++)
    if(isPrime[i])
      for(int j=i*2;j<PRIME;j+=i)
        isPrime[j] = false;
  nPrime = 0;
  for(int i=2;i<PRIME;i++)
    if(isPrime[i])
      prime[nPrime++] = i;
  isPrime[0] = isPrime[1] = false;
}

bool read(){
  cin >> n;
  return n;
}

void work(){
  for(int i=0;prime[i]*2<=n;i++)
    if(isPrime[n-prime[i]]){
      cout << n << " = " << prime[i] << " + " << n-prime[i] << endl;
      return;
    }
}

int main(){
  makePrime();
  while(read()) work();
  return 0;
}
