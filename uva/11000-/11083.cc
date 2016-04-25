// n! において、後ろに0のつく個数は問題文で与えられたとおり、
// f(n,p) = floor(n/p) + floor(n/(p^2)) + floor(n/(p^3)) + ...
// である。
//
// 1! 2! 3! 4! 5! .... (n-1)! n!
// これを、以下のように表す。
// 1! 2! 3! .. (p-1)! p! (p+1)! ... (2*p-1)! (2*p)! (2*p+1)! ...
//
// 
// これより、 Σf(k,p)は以下のようになる。
// 0 + 0 + 0 + ... + 0 + 1 + 1 + .... + 1 + 2 + 2 + ... + 2 + 3 + 3 + ....
//
// この総和を求める。
//
//
// まず、項の数は num/p となる。項の数をnSeqとおく。
//
// 数字が増えるのは、項の場所がpで割り切れるところ。
// 項が (p*p)! のときは数字が2増えることに注意。
//
// 
// Σf(k,p) のうち、floor(k/p)の総和を求める。
// (n+1-p) + (n+1-2*p) + (n+1-3*p) + ...
//
// (n+1-p)というのはp番目の項から数字が1増えるので、
// p番目以前の項を考慮しない、ということ。
// 
// これを数式とみて式に表すと、以下のようになる。
// nSeq*(n+1) - p*nSeq*(nSeq+1)/2 
// 
// - p*nSeq*(nSeq+1)/2 の部分は、初項-p,公差-pの等差数列より。
// 
//
// Σf(k,p) のうち、floor(k/(p^2))の総和を求める。
// (n+1-p^2) + (n+1-2*p^2) + (n+1-3*p^2) + ...
// 
// これ数式は上と同じ。
//
// 
// これをpの累乗がnumを超えるまで繰り返す。
// 
// なお、pはbaseをつくる一番大きい因数。

#include<iostream>
using namespace std;
typedef long long ll;

ll num, base;

bool read(){
  cin >> num >> base;
  return !(num==0 && base==0);
}

int getPrime(){
  int cur = base, ret;
  for(int i=2;i*i<=cur;i++)
    if(cur%i==0){
      while(cur%i==0) cur/=i;
      ret = i;
    }
  
  return (cur==1 ? ret : cur);
}

void work(){
  int p = getPrime();
  ll ans = 0;

  for(ll pp=getPrime();pp<=num;pp*=p){
    ll nSeq = num/pp;
    ans += nSeq*(num+1)-pp*nSeq*(nSeq+1)/2;
  }
  
  cout << ans << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
