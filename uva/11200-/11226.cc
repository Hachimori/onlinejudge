#include<iostream>
#include<algorithm>
#define BUF 500005
using namespace std;

int prime[BUF];

void makePrime(){
  bool isPrime[BUF];
  for(int i=0;i<BUF;i++) isPrime[i] = true;

  for(int i=2;i*i<BUF;i++)
    if(isPrime[i])
      for(int j=i*2;j<BUF;j+=i)
        isPrime[j] = false;

  int cur = 0;
  for(int i=2;i<BUF;i++)
    if(isPrime[i])
      prime[cur++] = i;
}

int sopf(int n){
  int ret = 0, cur = n;

  for(int i=0;prime[i]*prime[i]<=n;i++)
    while(cur%prime[i]==0){
      cur /= prime[i];
      ret += prime[i];
    }
  if(cur!=1) ret += cur;
  
  return ret;
}

int table[BUF];

void makeTable(){
  for(int i=2;i<BUF;i++){
    int next = sopf(i);

    if(i==next) 
      table[i] = 1;
    else
      table[i] = table[next]+1;
  }
}

int L, R;

void read(){
  cin >> L >> R;
  if(L>R) swap(L,R);
}

void work(int cases){
  cout << "Case #" << cases << ":" << endl;

  cout << *max_element(table+L,table+R+1) << endl;
}

int main(){
  makePrime();
  makeTable();
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  
  return 0;
}
