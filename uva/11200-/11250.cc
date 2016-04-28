#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#define BUF 60
#define PRIME 50
using namespace std;
typedef long long integer;

int nPrime, prime[PRIME];

void makeTable(){
  bool isPrime[PRIME];
  for(int i=0;i<PRIME;i++)
    isPrime[i] = true;

  for(int i=2;i*i<PRIME;i++)
    if(isPrime[i])
      for(int j=i*2;j<PRIME;j+=i)
	isPrime[j] = false;

  nPrime = 0;
  for(int i=2;i<PRIME;i++)
    if(isPrime[i])
      prime[nPrime++] = i;
}

class BigInt {
public:
  int leng;
  integer digit[BUF];
  
  BigInt(){}
  BigInt(int n){
    leng = 0;
    fill(digit,digit+BUF,0);
    
    while(n>0){ 
      digit[leng++] = n%10; 
      n /= 10;
    }
  }

  void print(){
    if(leng==0) printf("0");
    for(int i=leng-1;i>=0;i--) printf("%d",digit[i]);
    printf("\n");
  }
  
  BigInt operator+ (BigInt n) {
    BigInt ret(*this);
    
    for(int i=0;i<max(leng,n.leng);i++) {
      if(i<n.leng) ret.digit[i] += n.digit[i];
      if(ret.digit[i]>=10){
        ret.digit[i+1]++;
        ret.digit[i] %= 10;
      }
    }
    ret.normalize();
    
    return ret;
  }

  
  BigInt operator- (BigInt n) {
    BigInt ret(*this);
    
    int limit = max(leng,n.leng);
    for(int i=0;i<limit;i++) {
      if(i<n.leng) ret.digit[i] -= n.digit[i];
      if(ret.digit[i]<0){
        ret.digit[i+1]--;
        ret.digit[i] += 10;
      }
    }
    ret.normalize();
    
    return ret;
  }

  BigInt operator- (int n) {
    BigInt ret(*this);
    
    ret.digit[0] -= n;
    
    for(int i=0;ret.digit[i]<0;i++){
      ret.digit[i+1] -= (-ret.digit[i]/10+((-ret.digit[i])%10!=0));
      ret.digit[i] += (-ret.digit[i]/10+((-ret.digit[i])%10!=0))*10;
    }
    ret.normalize();
    
    return ret;
  }

  
  BigInt operator* (BigInt n) {
    BigInt ret(0);
    
    for(int i=0;i<leng;i++)
      if(digit[i])
	for(int j=0;j<n.leng;j++){
	  ret.digit[i+j] += digit[i]*n.digit[j];
	  if(ret.digit[i+j]>=10){
	    ret.digit[i+j+1] += ret.digit[i+j]/10;
	    ret.digit[i+j] %= 10;
	  }
	}
    ret.normalize();

    return ret;
  }
  
  BigInt operator* (int n) {
    BigInt ret(0);
    
    for(int i=0;i<leng || ret.digit[i]>=10;i++){
      ret.digit[i] += digit[i]*n;
      if(ret.digit[i]>=10){
	ret.digit[i+1] += ret.digit[i]/10;
	ret.digit[i] %= 10;
      }
    }
    ret.normalize();
    
    return ret;
  }

  BigInt operator/ (BigInt n){
    BigInt L(1), R(*this);
    
    while(L!=R){
      BigInt mid = (L+R)/2;

      if(mid*n<=*this)
	(mid!=L ? L : R ) = mid;
      else
	R = mid;
    }
    
    return L;
  }
  
  BigInt operator/ (integer n){
    BigInt div(*this);
    integer rem = 0;
    
    for(int i=leng-1;i>=0;i--){
      rem = rem*10 + div.digit[i];

      div.digit[i] = rem/n;
      rem %= n;
    }
    div.normalize();
    
    return div;
  }

  BigInt operator% (BigInt n) {
    BigInt rem(0);
    for(int i=leng-1;i>=0;i--){
      rem = rem*10 + digit[i];
      while(n<=rem) { rem = rem-n; }
    }
    
    return rem;
  }

  integer operator% (integer n) {
    integer rem = 0;
    for(int i=leng-1;i>=0;i--){
      rem = rem*10 + digit[i];
      rem %= n;
    }
    
    return rem;
  }

  void normalize() {
    leng = BUF-1;
    while(leng>0 && !digit[leng-1]) leng--;
  }

  integer toInt(){
    integer ret = 0;
    for(int i=leng-1;i>=0;i--){
      ret *= 10;
      ret += digit[i];
    }
    return ret;
  }

  bool operator<= (const BigInt n) const {
    if(leng!=n.leng) return leng<n.leng;

    for(int i=leng-1;i>=0;i--)
      if(digit[i]!=n.digit[i]) return digit[i]<n.digit[i];
    
    return true;
  }

  bool operator!= (const BigInt n) const {
    if(leng!=n.leng) return true;

    for(int i=leng-1;i>=0;i--)
      if(digit[i]!=n.digit[i]) return true;
    
    return false;
  }
};

class Fract{
public:
  BigInt nume, deno;

  Fract(){}
  Fract(int n, int d): nume(n), deno(d){}

  Fract operator+ (Fract f){
    Fract ret(*this);
    
    ret.nume = ret.nume*f.deno + f.nume*ret.deno;
    ret.deno = ret.deno*f.deno;

    return ret;
  }

  Fract operator- (Fract f){
    Fract ret(*this);
    
    ret.nume = ret.nume*f.deno - f.nume*ret.deno;
    ret.deno = ret.deno*f.deno;

    return ret;
  }

  Fract operator* (Fract f){
    Fract ret(*this);
    
    ret.nume = ret.nume*f.nume;
    ret.deno = ret.deno*f.deno;

    return ret;
  }

  void normalize(){
    for(int i=0;i<min(nPrime,nPrime);i++)
      while(deno%prime[i]==0 && nume%prime[i]==0){
	deno = deno/prime[i];
	nume = nume/prime[i];
      }
    
    BigInt div = gcd(deno,nume);
    
    if(div.leng<18){
      integer divi = div.toInt();
      nume = nume/divi;
      deno = deno/divi;
    }
    else{
      nume = nume/div;
      deno = deno/div;
    }
  }
  
private:
  BigInt gcd(BigInt a, BigInt b){
    if(b.leng<18){
      if(b.leng==0) return a;
      return gcd(b.toInt(),a%b.toInt());
    }

    return gcd(b,a%b);
  }

  integer gcd(integer a, integer b){
    return b==0 ? a : gcd(b,a%b);
  }

};

int num[2];

bool read(){
  for(int i=0;i<2;i++)
    cin >> num[i];
  return num[0]!=0 || num[1]!=0;
}

void work(int cases){
  static Fract f[2];
  
  for(int i=0;i<2;i++){
    if(num[i]<=3){
      f[i] = Fract(0,1);
      for(int j=1;j<=3;j++)
	f[i] = f[i]+Fract(1,j)-Fract(1,num[i]+j);
      f[i] = f[i] * Fract(1,3) - Fract(num[i],2*(num[i]+2));
    }
    else {
      BigInt t(3);

      for(int j=1;j<=3;j++)
	t = t*(num[i]+j);

      f[i].nume = (t - 18)/6;
      f[i].deno = (t * 9)/6;
    }
  }
  f[0].nume = f[0].nume*f[1].nume;
  f[0].deno = f[0].deno*f[1].deno*4;
  f[0].normalize();

  
  printf("Case %d:\n",cases);
  f[0].nume.print();
  for(int i=0;i<f[0].deno.leng;i++) printf("-"); printf("\n");
  f[0].deno.print();
}

int main(){
  makeTable();

  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }
    
  
  return 0;
}
