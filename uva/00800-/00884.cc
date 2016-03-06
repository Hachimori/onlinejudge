#include<iostream>
using namespace std;
const int BUF = 1000005;

int nPrime, prime[BUF], ans[BUF];

void makePrime(){
  bool isPrime[BUF];
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

void makeTable(){
  memset(ans,0,sizeof(ans));
  for(int i=2;i<BUF;i++){
    int v = i;
    for(int j=0;prime[j]*prime[j]<=v;j++)
      if(v%prime[j]==0){
        int toAdd = 0;
        while(v%prime[j]==0){
          toAdd++;
          v /= prime[j];
        }
        ans[i] += toAdd;
      }
    if(v>1) ans[i]++;
    ans[i] += ans[i-1];
  }
}

int main(){
  makePrime();
  makeTable();
  int n;
  while(cin >> n) cout << ans[n] << endl;
  return 0;
}
