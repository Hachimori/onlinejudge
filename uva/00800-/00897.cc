#include<iostream>
#include<cmath>
using namespace std;
const int BUF = 1000000;

bool isPrime[BUF];

void makePrime(){
  for(int i=0;i<BUF;i++) isPrime[i] = true;
  for(int i=2;i*i<BUF;i++)
    if(isPrime[i])
      for(int j=i*2;j<BUF;j+=i)
        isPrime[j] = false;
}

bool isAnagramPrime(int num, int nDigit, int cnt[10]){
  if(nDigit==0) return isPrime[num];
  for(int i=0;i<=9;i++)
    if(cnt[i]){
      cnt[i]--;
      if(!isAnagramPrime(num*10+i,nDigit-1,cnt)) return false;
      cnt[i]++;
    }
  return true;
}

int main(){
  makePrime();
  int n;
  while(cin >> n, n){
    if(n>=1000000){
      cout << 0 << endl;
      continue;
    }
    int limit = (int)pow(10.,(int)(log10(n)+1));
    for(int i=n+1;i<limit;i++){
      int nDigit = 0, cnt[10]={};
      for(int v=i;v;nDigit++,cnt[v%10]++,v/=10);
      if(isAnagramPrime(0,nDigit,cnt)){
        cout << i << endl;
        goto _success;
      }
    }
    cout << 0 << endl;
  _success:;
  }
  return 0;
}
