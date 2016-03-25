#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

#define MAX_SIZE 105
#define MAX_NUM 5005
#define MAX_DIGIT 200

using namespace std;

int nPrime;
int primeList[MAX_NUM];
vector<int> factorList[MAX_NUM];

int nNume, nDeno;
pair<int,int> numeList[MAX_SIZE], denoList[MAX_SIZE];


class BigInt{
public:

  int digit[MAX_DIGIT];
  int digitLength;

  BigInt(){}
  BigInt(int n){
    int cursor=0;

    for(;n>0;cursor++,n/=10)
      digit[cursor] = n%10;

    digitLength = cursor;
  }
  
  void print(){
    int cursor=digitLength-1;
    
    for(int i=cursor;i>=0;i--)
      cout << digit[i];
  }
  
  BigInt operator*( BigInt bi ){
    int result[MAX_DIGIT];

    for(int i=0;i<MAX_DIGIT;i++)
      result[i] = 0;
  
    for(int i=0;i<digitLength;i++)
      for(int j=0;j<bi.digitLength;j++)
	result[i+j] += bi.digit[j]*digit[i];

    for(int i=0;i<MAX_DIGIT;i++)
      if(result[i]>=10){
	result[i+1]+=result[i]/10;
	result[i]%=10;
      }

    for(int i=0;i<MAX_DIGIT;i++){
      bi.digit[i] = result[i];

      if(result[i]>0 && bi.digitLength<i+1)
	bi.digitLength = i+1;
    }

    return bi;
  }

};

void createPrime(){
  
  bool isPrime[MAX_NUM];
  
  for(int i=0;i<MAX_NUM;i++)
    isPrime[i] = true;
  nPrime=0;
  
  for(int i=3;i*i<MAX_NUM;i++)
    if(isPrime[i])
      for(int j=i*2;j<MAX_NUM;j+=i)
	isPrime[j] = false;
  
  primeList[0] = 2;
  nPrime++;

  for(int i=3;i<MAX_NUM;i+=2)
    if(isPrime[i])
      primeList[nPrime++] = i;

}

void factorize(){
  
  
  for(int i=2;i<MAX_NUM;i++){
    int currNum=i;
    
    for(int currPrime=0;primeList[currPrime]<=currNum && currPrime<nPrime;currPrime++){

      while(currNum%primeList[currPrime]==0){
	currNum/=primeList[currPrime];
	factorList[i].push_back(primeList[currPrime]);
      }

    }

  }

}

bool read(){
  
  if(!(cin >> nNume >> nDeno)) return false;

  for(int i=0;i<nNume;i++){
    int n,r;
    cin >> n >> r;

    numeList[i] = make_pair(n,min(r,n-r));
  }
  
  for(int i=0;i<nDeno;i++){
    int n,r;
    cin >> n >> r;

    denoList[i] = make_pair(n,min(r,n-r));
  }
  
  

  return true;
}

void work(){
  
  int numeFactor[MAX_NUM], denoFactor[MAX_NUM];
  
  for(int i=0;i<MAX_NUM;i++){
    numeFactor[i]=0;
    denoFactor[i]=0;
  }
  
  
  for(int i=0;i<nNume;i++)    
    for(int j=numeList[i].first-numeList[i].second+1;j<=numeList[i].first;j++)
      for(int k=0;k<factorList[j].size();k++)
	numeFactor[factorList[j][k]]++;
  
  for(int i=0;i<nDeno;i++)    
    for(int j=2;j<=denoList[i].second;j++)
      for(int k=0;k<factorList[j].size();k++)
	numeFactor[factorList[j][k]]++;
  
  for(int i=0;i<nDeno;i++)    
    for(int j=denoList[i].first-denoList[i].second+1;j<=denoList[i].first;j++)
      for(int k=0;k<factorList[j].size();k++)
	denoFactor[factorList[j][k]]++;
  
  for(int i=0;i<nNume;i++)    
    for(int j=2;j<=numeList[i].second;j++)
      for(int k=0;k<factorList[j].size();k++)
	denoFactor[factorList[j][k]]++;  
  
  
  for(int i=0;i<MAX_NUM;i++){
    if(numeFactor[i]<denoFactor[i]){
      cout << 0 << endl;
      return;
    }
    
    numeFactor[i]-=denoFactor[i];
  }
  
  
  BigInt curr=BigInt(1);
  
  for(int i=0;i<MAX_NUM;i++){
    
    for(int j=0;j<numeFactor[i];j++)
      curr=curr*BigInt(i);
    
    if(curr.digitLength>=101){
      cout << -1 << endl;
      return;
    }
  }
  
  curr.print();
  cout << endl;
}

int main(){

  createPrime();
  factorize();
  
  while(read())
    work();

  return 0;
}
