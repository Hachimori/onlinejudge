#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int PRIME = 1000001, BUF = 101;

int nPrime, prime[PRIME];

void makePrime(){
  bool isPrime[PRIME];
  for(int i=0;i<PRIME;i++) isPrime[i] = true;

  for(int i=2;i*i<PRIME;i++)
    if(isPrime[i])
      for(int j=i*2;j<PRIME;j+=i)
        isPrime[j] = false;

  nPrime = 0;
  for(int i=2;i<PRIME;i++)
    if(isPrime[i])
      prime[nPrime++] = i;
}

string s;

bool read(){
  cin >> s;
  return s[0]!='-';
}

int mod(int num[BUF], int len, int toDiv){
  int rem = 0;
  for(int i=len-1;i>=0;i--){
    rem *= 10;
    rem = (rem+num[i])%toDiv;
  }
  return rem;
}

void div(int num[BUF], int &len, int toDiv){
  int rem = 0;
  for(int i=len-1;i>=0;i--){
    int v = rem*10+num[i];
    rem = v%toDiv;
    num[i] = v/toDiv;
  }
  while(num[len]==0) len--;
  len++;
}

void work(){
  int num[BUF]={0}, len = s.size();
  for(int i=0;i<s.size();i++)
    num[s.size()-i-1] = s[i]-'0';
  
  for(int i=0;i<nPrime;i++){
    if(mod(num,len,prime[i])==0){
      while(mod(num,len,prime[i])==0){
        div(num,len,prime[i]);
        printf("    %d\n",prime[i]);
      }
    }
  }
  if(len>2){
    printf("    ");
    for(int i=len-1;i>=0;i--)
      printf("%d",num[i]);
    printf("\n");
  }
  printf("\n");
}

int main(){
  makePrime();
  while(read()) work();
  return 0;
}
