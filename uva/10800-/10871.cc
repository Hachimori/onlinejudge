#include<iostream>
#define NUM 10005
#define PRIME 1000000
using namespace std;

int prime[PRIME];

void makePrime(){
  static bool isPrime[PRIME];
  for(int i=0;i<PRIME;i++) isPrime[i] = true;

  for(int i=2;i*i<PRIME;i++)
    if(isPrime[i])
      for(int j=i*2;j<PRIME;j+=i)
        isPrime[j] = false;

  int idx = 0;
  for(int i=2;i<PRIME;i++)
    if(isPrime[i])
      prime[idx++] = i;
}

bool primeChk(int n){
  for(int i=0;prime[i]*prime[i]<=n;i++)
    if(n%prime[i]==0)
      return false;
  return true;
}

int nNum, num[NUM];

void read(){
  cin >> nNum;
  for(int i=0;i<nNum;i++) cin >> num[i];
}


void work(){
  int sum[NUM];   // sum[i]: summation of 0-i numbers
  
  sum[0] = num[0];
  for(int i=1;i<nNum;i++) sum[i] = sum[i-1]+num[i];
    
  for(int len=1;len<nNum;len++)
    for(int i=0;i+len<nNum;i++){
      int v = sum[i+len]-(i==0?0:sum[i-1]);

      if(primeChk(v)){
        cout << "Shortest primed subsequence is length " << len+1 << ":";
        for(int j=i;j<=i+len;j++)
          cout << ' ' << num[j];
        cout << endl;
        return;
      }
    }

  cout << "This sequence is anti-primed." << endl;
}

int main(){
  makePrime();
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}

