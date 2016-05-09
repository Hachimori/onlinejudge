#include<iostream>
using namespace std;
const int BUF = 10000005;

int nPrime, prime[BUF];

void makePrime(){
  static bool isPrime[BUF];
  for(int i=0;i<BUF;i++) isPrime[i] = true;

  for(int i=2;i*i<BUF;i++)
    if(isPrime[i])
      for(int j=i*2;j<BUF;j+=i)
        isPrime[j] = false;
  
  nPrime = 0;
  for(int i=2;i<BUF;i++)
    if(isPrime[i])
      prime[nPrime++] = i;
}


long long n;

bool read(){
  cin >> n;
  n = llabs(n);
  return n!=0;
}


void work(){
  long long ans = -1, cnt = 0;
  for(int i=0;i<nPrime && 1LL*prime[i]*prime[i]<=n;i++)
    if(n%prime[i]==0){
      ans = prime[i];
      cnt++;
      while(n%prime[i]==0) n /= prime[i];
    }
  
  if(n>1){ ans = n; cnt++; }
  cout << (cnt<=1 ? -1 : ans) << endl;
}


int main(){
  makePrime();
  while(read()) work();
  return 0;
}
