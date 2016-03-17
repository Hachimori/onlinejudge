#include<iostream>
#include<numeric>
using namespace std;
const int BUF = 1000000;

bool isPrime[BUF], isCircular[BUF];
int circularTable[BUF];

void makePrime(){
  for(int i=0;i<BUF;i++) isPrime[i] = true;
  for(int i=2;i*i<BUF;i++)
    if(isPrime[i])
      for(int j=i*2;j<BUF;j+=i)
        isPrime[j] = false;
}

void makeTable(){
  for(int i=0;i<BUF;i++){
    int p=1, len = 1;
    for(;p<=i;p*=10,len++); p/=10,len--;
    bool allPrime = true;
    for(int j=0,v=i;j<len;j++){
      if(!isPrime[v]){ allPrime = false; break; }
      v = v%p*10+v/p;
    }
    isCircular[i] = allPrime;
  }
  circularTable[0] = isCircular[0];
  for(int i=1;i<BUF;i++)
    circularTable[i] = isCircular[i]+circularTable[i-1];
}

int main(){
  makePrime();
  makeTable();
  int L, R;
  while(cin >> L >> R, L!=-1){
    int t = circularTable[R]-circularTable[L-1];
    if(t==0)
      cout << "No Circular Primes." << endl;
    else if(t==1)
      cout << "1 Circular Prime." << endl;
    else
      cout << t << " Circular Primes." << endl;
  }
  return 0;
}
