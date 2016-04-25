// $B5a$a$k?t$O(B gcd(m,n)!=1 && gcd(m,n)!=m $B$rK~$?$9(Bm$B$N8D?t!#(B
// $B$3$3$G!"$3$NO@M}<0$N(Bnot$B$r$H$k$H!"(B gcd(m,n)==1 || gcd(m,n)==m $B$H$J$k!#(B
//
// n$B$+$iFsHVL\$N<0$rK~$?$9(Bm$B$N8D?t$r0z$$$??t$O!":G=i$N<0$,I=$9?t$HEy$7$$!#(B
// $BFsHVL\$N<0$rK~$?$9(Bm$B$N8D?t$r5a$a$k$3$H$r9M$($k!#(B
//
// gcd(m,n)==1 $B$rK~$?$9(Bm$B$N8D?t$O%*%$%i!<$N&U4X?t$G5a$a$k$3$H$,=PMh$k!#(B
// gcd(m,n)==m $B$rK~$?$9(Bm$B$N8D?t$O(B, m$B$NLs?t$N?t$KEy$7$$!#(B
//
// m$B$NAG0x?tJ,2r$r(B p1^e1*p2^e2*$B!D(B*pn^en(p1$B!D(Bpn$B$OAG?t(B) $B$H$7$?$H$-!"(B
// m$B$NLs?t$N?t$O!"(B(1+e1)*(1+e2)*$B!D(B*(1+en)
//
// $B$^$?!"(Bgcd(m,n)==1 $B$H(B gcd(m,n)==m $B$rF1;~$KK~$?$9(Bm$B$O(B1$B$N$_$G$"$k$+$i!"(B
// $BJRJ}$N<0$rK~$?$9(Bm$B$N8D?t$rB-$7$?$H$-!"=EJ#$9$k$N$O(B1$B$N$_$G$"$k!#(B
//
// $B$h$C$FEz$($O!"&U(B(n)+(1+e1)*(1+e2)*$B!D(B*(1+en)-1$B$H$J$k!#(B

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
