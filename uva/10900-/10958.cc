#include<iostream>
#define myabs(x) ((x)>0 ? (x) : -(x))
#define BUF 1100000
using namespace std;
typedef long long integer;

integer prime[BUF];

void makePrime(){
  bool isPrime[BUF];
  for(int i=0;i<BUF;i++)
    isPrime[i] = true;
  
  for(int i=2;i*i<BUF;i++)
    if(isPrime[i])
      for(int j=i*2;j<BUF;j+=i)
        isPrime[j] = false;

  int cur = 0;
  for(int i=2;i<BUF;i++)
    if(isPrime[i])
      prime[cur++] = i;
}

integer m, n, p;

bool read(){
  cin >> m >> n >> p;
  return (m|n|p)!=0;
}

void work(int cases){
  integer cnt = 1, cur = myabs(n*m*p*p);
  
  for(int i=0;prime[i]*prime[i]<=myabs(n*m*p*p);i++){
    int mul = 1;
    while(cur%prime[i]==0){
      mul++;
      cur /= prime[i];
    }
    cnt *= mul;
  }
  if(cur!=1) cnt*=2;
    
  
  cout << "Case " << cases << ": " << 2*cnt-1 << endl;
}

int main(){
  makePrime();
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
