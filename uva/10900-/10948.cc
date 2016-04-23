#include<iostream>
#define BUF 1000005
using namespace std;

int nPrime, prime[BUF];
bool isPrime[BUF];

void makePrime(){
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

int num;

bool read(){
  cin >> num;
  return num!=0;
}

void work(){
  cout << num << ":" << endl;
  for(int i=0;i<nPrime && num-prime[i]>0;i++)
    if(isPrime[num-prime[i]]){
      cout << prime[i] << '+' << num-prime[i] << endl;
      return;
    }
  cout << "NO WAY!" << endl;
}

int main(){
  makePrime();
  
  while(read())
    work();
  
  return 0;
}
