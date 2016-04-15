#include<iostream>
using namespace std;
const int PRIME = 10001, INF = 1<<30;

int n, nPrime, prime[PRIME];

void makePrime(){
  bool isPrime[PRIME];
  for(int i=0;i<PRIME;i++) isPrime[i] = true;
  
  for(int i=2;i*i<PRIME;i++)
    if(isPrime[i])
      for(int j=i*2;j<PRIME;j+=i)
        isPrime[j] = false;

  nPrime = 0;
  for(int i=2;i<PRIME;i++)
    if(isPrime[i])
      prime[nPrime++] = i;
}


void read(){
  cin >> n;
}


void work(){
  int maxV = -INF, maxPrime;
  for(int i=0;i<nPrime && prime[i]<=n;i++){
    int p = n/prime[i];
    if(maxV<n-p*prime[i]){
      maxV = n-p*prime[i];
      maxPrime = prime[i];
    }
  }
  cout << maxPrime << endl;
}


int main(){
  makePrime();
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
