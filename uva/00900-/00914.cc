#include<iostream>
#include<algorithm>
#include<map>
#define PRIME 1000005
using namespace std;

int nPrime, prime[PRIME];

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

int lower, upper;

void read(){
  cin >> lower >> upper;
}

void work(){
  int bgn = lower_bound(prime,prime+nPrime,lower)-prime;
  int end = upper_bound(prime,prime+nPrime,upper)-prime;
  map<int,int> M;
  
  for(int i=bgn;i+1<end;i++)
    if(!M.count(prime[i+1]-prime[i]))
      M[prime[i+1]-prime[i]] = 1;
    else
      M[prime[i+1]-prime[i]]++;
  
  bool danger = false;
  int maxV = 0, champ;
  for(map<int,int>::iterator i=M.begin();i!=M.end();i++){
    if(maxV<i->second){
      champ = i->first;
      maxV = i->second;
      danger = false;
    }
    else if(maxV==i->second)
      danger = true;
  }

  if(danger || maxV==0) cout << "No jumping champion" << endl;
  else cout << "The jumping champion is " << champ << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  makeTable();
  
  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
