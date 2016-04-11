#include<iostream>
#include<map>
#include<cassert>
#include<utility>
#include<algorithm>
#include<vector>
#include<set>

#define MAX_PRIME 1000000

using namespace std;

long long small, big, nPrime;
long long primeList[MAX_PRIME];
vector<long long> almostPrimeList;

void makePrime(){
  

  bool isPrime[MAX_PRIME];
	
  for(int i=0;i<MAX_PRIME;i++)
    isPrime[i] = true;

  for(int j=3;j*j<MAX_PRIME;j+=2)
    if(isPrime[j])
      for(int k=j*2;k<MAX_PRIME;k+=j)
	isPrime[k]=false;
	
  primeList[0]=2;
  nPrime = 1;

  for(int l=3;l<MAX_PRIME;l+=2)
    if(isPrime[l]){
      primeList[nPrime] = l;
      nPrime++;
      //cout << l << " ";
    }

  
  long long limit=1000000;
  limit*=limit;
  
  for(int i=0;i<nPrime;i++)
    for(long long j=primeList[i]*primeList[i];j<limit;j*=primeList[i])
      almostPrimeList.push_back(j);

  sort(almostPrimeList.begin(),almostPrimeList.end());
      
}

void read(){
  cin >> small >> big; 

  if(small>big)
    swap(small,big);

}

void work(){
  


  /*
  int ans=0;
  
  for(map<long long,int>::iterator i=nDivided.begin();i!=nDivided.end();i++)
    if(i->second==1)
      ans++;
  */
  cout << upper_bound(almostPrimeList.begin(),almostPrimeList.end(),big)-
          lower_bound(almostPrimeList.begin(),almostPrimeList.end(),small) << endl;

}

int main(){

  int cases;
  cin >> cases;

  makePrime();

  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
