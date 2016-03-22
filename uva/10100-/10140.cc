#include<iostream>
#include<climits>
#include<algorithm>

#define MAX_PRIME 50000
#define MAX_SIZE 1000005

using namespace std;

int nPrime, primeList[MAX_PRIME];
int smaller, bigger;

void makePrime(){
  
  bool prime[MAX_PRIME];

  for(int i=0;i<MAX_PRIME;i++)
    prime[i] = true;
    
  for(int i=3;i*i<MAX_PRIME;i+=2)
    if(prime[i])
      for(int j=i*2;j<MAX_PRIME;j+=i)
	prime[j]=false;

  nPrime=1;
  primeList[0]=2;

  for(int i=3;i<MAX_PRIME;i+=2)
    if(prime[i]){
      primeList[nPrime]=i;
      nPrime++;
    }

}

bool read(){
  if(!(cin >> smaller >> bigger)) return false;

  if(smaller==1) smaller=2;
  return true;
}

bool isPrime(int n, int &factor){
  
  for(int i=0;primeList[i]*primeList[i]<=n && i<nPrime;i++)
    if(n%primeList[i]==0){ 
      factor=i;
      return false;
    }

  return true;
}

void work(){
  /*
  for(int i=0;i<100;i++)
    cout << primeList[i] << endl;
  */

  int closeL, closeR, minClose=INT_MAX;
  int disL, disR, maxDis=INT_MIN;
  
  bool prime[MAX_SIZE];
  bool usedPrime[MAX_PRIME];

  for(int i=0;i<bigger-smaller+1;i++)
    prime[i] = true;

  for(int i=0;i<MAX_PRIME;i++)
    usedPrime[i] = false;
  
  for(int i=0;i<nPrime && primeList[i]*primeList[i]<=bigger;i++){
    
    if(!primeList[i]) continue;

    long long begin;
    if(smaller==primeList[i]) begin=primeList[i];
    else if(smaller>primeList[i]){ 
      if(smaller%primeList[i]==0)
	begin=0;
      else
	begin=primeList[i]*(smaller/primeList[i]+1)-smaller;
    }
    else{ 
      begin=2*primeList[i]-smaller;
      
    }

    for(long long j=begin;j<bigger-smaller+1;j+=primeList[i])
      prime[j]=false;
    
  }

  int prevPrime=0;

  for(int i=0;i<bigger-smaller+1;i++){
    if(prime[i]){
      if(prevPrime==0) prevPrime=i+smaller;
      else {
	if(minClose>i+smaller-prevPrime){
	  minClose = i+smaller-prevPrime;
	  closeL = prevPrime;
	  closeR = i+smaller;
	}
	if(maxDis<i+smaller-prevPrime){
	  maxDis = i+smaller-prevPrime;
	  disL = prevPrime;
	  disR = i+smaller;
	}
	prevPrime=i+smaller;
      }
    }
  }
  
  if(minClose==INT_MAX) cout << "There are no adjacent primes." << endl;
  else 
    cout << closeL << ',' << closeR << " are closest, " << disL << ','
	 << disR << " are most distant." << endl;
  
}

int main(){

  makePrime();

  while(read())
    work();

  return 0;
}
