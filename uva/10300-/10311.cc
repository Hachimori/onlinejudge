#include<iostream>
#define PRIME 10000
using namespace std;

int nPrime, prime[PRIME], n;

void makeTable(){
  bool isPrime[PRIME];
  for(int i=0;i<PRIME;i++)
    isPrime[i] = true;

  for(int i=2;i*i<PRIME;i++)
    if(isPrime[i])
      for(int j=i*2;j<PRIME;j+=i)
        isPrime[j] = false;

  nPrime = 0;
  for(int i=2;i<PRIME;i++)
    if(isPrime[i])
      prime[nPrime++] = i;
}

bool read(){
  return scanf("%d",&n)!=EOF;
}

bool isPrime(int v){
  if(v==1) return false;
  for(int i=0;i<nPrime && prime[i]*prime[i]<=v;i++){
    if(v%prime[i]==0)
      return false;
  }
  return true;
}

void work(){
  if(n%2==0){
    int a1 = -1, b1 = -1, a2 = -1, b2 = -1;
    for(int a=n/2-(n/2%2==0);a>1;a-=2)
      if(a*2!=n && isPrime(a) && isPrime(n-a)){
        a1 = a, b1 = n-a;
        break;
      }
    
    if(n>4 && isPrime(n-2))
      a2 = 2, b2 = n-2;
    
    if(a1!=-1 && a2!=-1 && b1-a1>b2-a2)
      printf("%d is the sum of %d and %d.\n",n,a2,b2);
    else if(a1!=-1)
      printf("%d is the sum of %d and %d.\n",n,a1,b1);
    else
      printf("%d is not the sum of two primes!\n",n);
  }
  else{
    if(n>3 && isPrime(n-2))
      printf("%d is the sum of %d and %d.\n",n,2,n-2);
    else
      printf("%d is not the sum of two primes!\n",n);
  }
}

int main(){
  makeTable();
  while(read()) work();
  return 0;
}
