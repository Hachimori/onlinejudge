#include<iostream>
#include<cstdlib>
using namespace std;
const int BUF = 1000005;

int nPrime, prime[BUF];

void makePrime(){
  bool isPrime[BUF];
  for(int i=0;i<BUF;i++) isPrime[i] = true;
  for(int i=2;i*i<BUF;i++)
    if(isPrime[i])
      for(int j=i*2;j<BUF;j+=i)
        isPrime[j] = false;
  nPrime = 0;
  for(int i=2;i<BUF;i++)
    if(isPrime[i])
      prime[nPrime++] = i;
}

int main(){
  makePrime();

  int n;
  while(cin>>n,n){
    int two = 0, five = 0;

    int ans = 1;
    for(int i=0;i<nPrime && prime[i]<=n;i++){
      int toAdd = 1;
      for(long long p=prime[i];p<=n;p*=prime[i],toAdd++);
      if(prime[i]==2)
        two = toAdd-1;
      else if(prime[i]==5)
        five = toAdd-1;
      else
        for(int j=0;j<toAdd-1;j++)
          ans = ans*prime[i]%10;
    }
    for(int i=0;i<abs(two-five);i++)
      ans = ans*(two<five ? 5 : 2)%10;

    cout << ans << endl;
  }
  return 0;
}
