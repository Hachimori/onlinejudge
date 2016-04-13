#include<iostream>
using namespace std;
const int PRIME = 34000;

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
  int L, R;
  while(cin >> L >> R,L|R){
    if(L>R) swap(L,R);
    for(int i=0;i+2<nPrime;){
      if(prime[i+1]-prime[i]==prime[i+2]-prime[i+1]){
        int idx = i;
        while(idx+1<nPrime && prime[idx+1]-prime[idx]==prime[i+1]-prime[i]) idx++;
        if(prime[idx]>R || prime[i]<L){
          i = idx;
          continue;
        }
        for(int j=i;j<=idx;j++){
          if(j!=i) cout << ' ';
          cout << prime[j];
        }cout << endl;
        i = idx;
      }
      else{
        i++;
      }
    }
  }
  return 0;
}
