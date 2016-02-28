#include<iostream>

#define MAX_SIZE 40000

using namespace std;

int nPrime, prime[MAX_SIZE];

void makeTable(){
  bool isPrime[MAX_SIZE];
  
  for(int i=0;i<MAX_SIZE;i++)
    isPrime[i] = true;
  
  nPrime = 0;
  
  for(int i=2;i*i<MAX_SIZE;i++)
    if(isPrime[i])
      for(int j=i*2;j<MAX_SIZE;j+=i)
	isPrime[j] = false;
  
  for(int i=2;i<MAX_SIZE;i++)
    if(isPrime[i])
      prime[nPrime++] = i;
}

int lower, upper;

void read(){
  cin >> lower >> upper;
}

void work(){
  int maxVal = 0, maxNum;

  for(int curr=lower;curr<=upper;curr++){
    int tmp = curr, val = 1;
    
    for(int i=0;i<nPrime && prime[i]<=curr && tmp!=1;i++){
      int nDiv = 1;
      while(tmp%prime[i]==0){ 
	tmp /= prime[i];
	nDiv++;
      }
      val *= nDiv;
    }

    if(tmp!=1) val *= 2;
    if(maxVal<val){
      maxVal = val;
      maxNum = curr;
    }
  }
  
  cout << "Between " << lower << " and " << upper << ", "
       << maxNum << " has a maximum of " << maxVal << " divisors." << endl;
}

int main(){
  makeTable();

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
