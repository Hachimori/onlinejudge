#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int PRIME = 5000001;

int nPrime, prime[PRIME], dp[PRIME]={};
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
}

int sumFactor(int v){
  int sum = 0;
  for(int i=0;i<nPrime && prime[i]*prime[i]<=v;i++) 
    if(v%prime[i]==0){
      while(v%prime[i]==0) v /= prime[i];
      sum += prime[i];
    }
  if(v>1) sum += v;
  return sum;
}

void makeTable(){
  for(int i=2;i<PRIME;i++)
    dp[i] = dp[i-1]+isPrime[sumFactor(i)];
}

int main(){
  makePrime();
  makeTable();
  int a, b;
  while(cin >> a >> b)
    cout << dp[b]-dp[a-1] << endl;
  return 0;
}
