// 10831
// 平方剰余・ヤコビ記号
//
// a と p が互いに素で
// x^2 ≡ a%p
// が解をもつとき、aはpを法として平方剰余であるという。
//
// x^2 ≡ a%p について、
// p = 7　のとき
// 
// 0^2 = 0  ≡ 0
// 1^2 = 1  ≡ 1
// 2^2 = 4  ≡ 4
// 3^2 = 9  ≡ 2 (9 mod 7)
// 4^2 = 16 ≡ 2 (16 mod 7)
// 5^2 = 25 ≡ 4 (25 mod 7)
// 6^2 = 36 ≡ 1 (36 mod 7)
//
// となり、0,1,2,4,は、7を法として平方剰余である。
//
//
// 以下の(a/p)をルジャンドル記号という。
// (a/p) = 1 if(gcd(a,p)==1 && x^2≡a%p が解をもつ)
// (a/p) = 0 if(gcd(a,p)!=1)
// (a/p) = -1 if(gcd(a,p)==1 && x^2≡a%p が解をもたない)
//
// n>2 であり素数ならばルジャンドル記号とヤコビ記号は等しい。
//
//
// http://www80.sakura.ne.jp/~aozora/suuron/node39.html
// http://www.absoluteastronomy.com/ref/jacobi_symbol
// http://futureboy.homeip.net/fsp/colorize.fsp?fileName=JacobiSymbol.frink

#include<iostream>
#include<cmath>
#include<cfloat>
#include<algorithm>

#define EPS FLT_EPSILON
#define EQ(x,y) (fabs((x)-(y))<EPS)

using namespace std;

int a,p;

bool read(){
  cin >> a >> p;
  if(a==-1 && p==-1) return false;
  
  return true;
}

// p は2より大きい素数でなくてはならない
// p は2より大きい素数しかこないことは問題文で保証されている
int jacobi(int a, int p){
  
  int j = 1;

  a %= p;
  if(a<0)
    a += p;
  
  while(a!=0){
    
    while(a%2==0){
      a /= 2;
      if(p%8==3 || p%8==5) j = -j;
    }
    
    swap(a,p);
    
    if(a%4==3 && p%4==3) j = -j;
    
    a %= p;
    
  }
  
  if(p==1) return j;
  else return 0;
}

void work(){
  
  if(jacobi(a,p)!=-1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
