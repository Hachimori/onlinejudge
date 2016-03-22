// uva 10179
//
// $B%*%$%i!<$N&U4X?t(B
// 1$B$+$i(Bn$B$NCf$G!"(Bn$B$H8_$$$KAG$G$"$k?t$N8D?t$r&U(B(n)$B$H$7$FM?$($k!#(B
// 
// $B%*%$%i!<$N&U4X?t$N@-<A(B: 
//   p$B$rAG?t$H$9$k$H!"&U(B(p) = p-1
//   m,n$B$r8_$$$KAG$J@5@0?t$H$9$k$H!"(B $B&U(B(mn)=$B&U(B(m)$B&U(B(n)   
//   $B&2(Bd|n $B&U(B(d) = n   (d|n: n$B$r3d$j@Z$k(Bd)
//
// $B7W;;K!(B:
// http://ja.wikipedia.org/wiki/%E3%82%AA%E3%82%A4%E3%83%A9%E3%83%BC%E3%81%AE%CF%86%E9%96%A2%E6%95%B0
//
// $BA086$5$s$N%3!<%I$r;2>H$7$?(B
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
