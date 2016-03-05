// ikeyanagiさんのコードを参照した

#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int n;
  while(cin >> n){
    if(n==1){
      cout << 7 << endl;
      continue;
    }
    double toAdd = log2(10)-3;
    int nDigit = (int)(log10(n)+1), base = 0;
    double hi = log2(n+1)-(int)log2(n);
    double lo = log2(n)  -(int)log2(n);
    for(int p=1;;p++){ 
      hi += toAdd;
      lo += toAdd;
      if(lo>=1.0) lo-=1.0, base++;
      if(hi>=1.0) hi-=1.0;
      if(p<=nDigit) continue;
      if(lo<hi) continue;
      cout << 1+base+3LL*p+(int)log2(n) << endl;
      break;
    }
  }
  return 0;
}
