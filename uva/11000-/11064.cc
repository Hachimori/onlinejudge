// 求める数は gcd(m,n)!=1 && gcd(m,n)!=m を満たすmの個数。
// ここで、この論理式のnotをとると、 gcd(m,n)==1 || gcd(m,n)==m となる。
//
// nから二番目の式を満たすmの個数を引いた数は、最初の式が表す数と等しい。
// 二番目の式を満たすmの個数を求めることを考える。
//
// gcd(m,n)==1 を満たすmの個数はオイラーのφ関数で求めることが出来る。
// gcd(m,n)==m を満たすmの個数は, mの約数の数に等しい。
//
// mの素因数分解を p1^e1*p2^e2*…*pn^en(p1…pnは素数) としたとき、
// mの約数の数は、(1+e1)*(1+e2)*…*(1+en)
//
// また、gcd(m,n)==1 と gcd(m,n)==m を同時に満たすmは1のみであるから、
// 片方の式を満たすmの個数を足したとき、重複するのは1のみである。
//
// よって答えは、φ(n)+(1+e1)*(1+e2)*…*(1+en)-1となる。

#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

int N;

bool read(){
  if(scanf("%d",&N)==EOF) return false;
  return true;
}

int eulerPhi(int n){
  int ret = n;
  for(ll i=2;i*i<=n;i++)
    if(n%i==0){
      while(n%i==0) n /= i;
      ret -= ret/i;
    }
  if(n!=1) ret -= ret/n;
  return ret;
}

int cntFactNum(int n){
  int ret = 1;
  for(ll i=2;i*i<=n;i++)
    if(n%i==0){
      int cnt = 0;
      while(n%i==0){
	cnt++;
	n /= i;
      }
      ret *= cnt+1;
    }
  if(n!=1) ret *= 2;
  return ret-1;
}

void work(){
  printf("%d\n",N-(eulerPhi(N)+cntFactNum(N)));
}

int main(){
  while(read())
    work();
  
  return 0;
}
