#include<iostream>
#include<algorithm>
#define BUF 3000001
#define PRIME 10000
using namespace std;

int n, table[BUF];

void makeTable(){
  bool isPrime[PRIME];
  static int nPrime, prime[PRIME], num[BUF];

  for(int i=0;i<PRIME;i++) isPrime[i] = true;

  for(int i=2;i*i<PRIME;i++)
    if(isPrime[i])
      for(int j=i*2;j<PRIME;j+=i)
        isPrime[j] = false;

  nPrime = 0;
  for(int i=2;i<PRIME;i++)
    if(isPrime[i])
      prime[nPrime++] = i;

  for(int i=0;i<BUF;i++) table[i] = 0, num[i] = i;
  
  for(int i=0;i<nPrime;i++)
    for(int j=prime[i];j<BUF;j+=prime[i])
      while(num[j]%prime[i]==0) num[j] /= prime[i], table[j]++;

  for(int i=2;i<BUF;i++)
    if(num[i]!=1) 
      table[i]++;
  
  for(int i=3;i<BUF;i++)
    table[i] += table[i-1];
}

bool read(){
  cin >> n;
  return n>=0;
}

void work(int cases){
  int *pos = lower_bound(table,table+BUF,n);

  if(*pos!=n)
    cout << "Case " << cases << ": Not possible." << endl;
  else
    cout << "Case " << cases << ": " << pos-table << '!' << endl;
}

int main(){
  makeTable();
  
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
