#include<iostream>
using namespace std;
const int PRIME = 1000001;

int nPrime, prime[PRIME];

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

int main(){
  makePrime();

  static int tbl[PRIME];
  memset(tbl,0,sizeof(tbl));
  for(int i=0;i<nPrime;i++)
    tbl[prime[i]]++;

  for(int i=1;i<PRIME;i++)
    tbl[i] += tbl[i-1];

  int n, cases = 1;
  while(cin >> n,n){
    long long ans  = 0;
    for(int i=0;i<nPrime && prime[i]*2<n;i++)
      ans += tbl[n-prime[i]]-tbl[prime[i]];
    cout << "Case " << cases++ << ": " << ans << endl;
  }

  return 0;
}
