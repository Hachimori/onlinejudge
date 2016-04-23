#include<iostream>
#include<numeric>
#include<vector>
#define BUF 2000001
#define NUM_PRIME 200000
#define INF (1<<30)
using namespace std;

int nPrime, prime[NUM_PRIME];
int sum[BUF], phi[BUF];

void makePrime(){
  static bool isPrime[BUF];
  for(int i=0;i<BUF;i++)
    isPrime[i] = true;
  
  for(int i=2;i*i<BUF;i++)
    if(isPrime[i])
      for(int j=i*2;j<BUF;j+=i)
	isPrime[j] = false;

  nPrime = 0;
  for(int i=2;i<BUF;i++)
    if(isPrime[i])
      prime[nPrime++] = i;
}

void makePhi(){
  vector<int> num(BUF);

  for(int i=0;i<BUF;i++)
    phi[i] = num[i] = i;
  
  for(int i=0;i<nPrime;i++)
    for(int j=prime[i];j<BUF;j+=prime[i]){
      while(num[j]%prime[i]==0) num[j] /= prime[i];
      phi[j] -= phi[j]/prime[i];
    }

  for(int i=1;i<BUF;i++)
    if(num[i]!=1)
      phi[i] -= phi[i]/num[i];
}

void makeSum(){
  vector<int> nStep(BUF);
  
  nStep[0] = nStep[1] = 0;
  sum[0] = sum[1] = 0;
  
  for(int i=2;i<BUF;i++){
    nStep[i] = nStep[phi[i]]+1;
    sum[i] = sum[i-1]+nStep[i];    
  }
}

int bgn, end;

void read(){
  cin >> bgn >> end;
}

void work(){
  cout << sum[end]-sum[bgn-1] << endl;
}

int main(){
  makePrime();
  makePhi();
  makeSum();
  
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
