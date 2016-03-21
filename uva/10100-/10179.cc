// uva 10179
//
// オイラーのφ関数
// 1からnの中で、nと互いに素である数の個数をφ(n)として与える。
// 
// オイラーのφ関数の性質: 
//   pを素数とすると、φ(p) = p-1
//   m,nを互いに素な正整数とすると、 φ(mn)=φ(m)φ(n)   
//   Σd|n φ(d) = n   (d|n: nを割り切るd)
//
// 計算法:
// http://ja.wikipedia.org/wiki/%E3%82%AA%E3%82%A4%E3%83%A9%E3%83%BC%E3%81%AE%CF%86%E9%96%A2%E6%95%B0
//
// 前原さんのコードを参照した
// http://www.prefield.com/algorithm/math/eulerphi.html

#include<iostream>
using namespace std;

int N;

bool read(){
  cin >> N;
  return N!=0;
}

int eulerPhi(int n){
  int ret = n;
  for(int i=2;i*i<=n;i++)
    if(n%i==0){
      while(n%i==0) n /= i;
      ret -= ret/i;
    }
  if(n!=1) ret -= ret/n;
  return ret;
}

void work(){
  cout << eulerPhi(N) << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
