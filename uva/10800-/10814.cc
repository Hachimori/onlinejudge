#include<iostream>
#include<string>
#include<algorithm>
#include<cassert>
#define BUF 40
using namespace std;

class BigInt {
public:
  int digit[BUF], leng;
  
  BigInt(){}
  BigInt(int n){
    leng = 0;
    fill(digit,digit+BUF,0);
    
    while(n>0){ 
      digit[leng++] = n%10; 
      n /= 10;
    }
  }
  BigInt(string s){
    leng = s.size();
    fill(digit,digit+BUF,0);

    for(int i=0;i<leng;i++)
      digit[i] = s[leng-i-1]-'0';
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

  
  BigInt operator* (BigInt n) {
    BigInt ret(0);
    
    for(int i=0;i<leng;i++)
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
  
  
  BigInt operator/ (BigInt n){
    BigInt div(*this), rem(0);
    for(int i=leng-1;i>=0;i--){
      rem = rem*BigInt(10) + BigInt(div.digit[i]);
      div.digit[i] = 0;
      while(n<=rem) { rem = rem-n; div.digit[i]++; }
    }
    div.normalize();
    
    return div;
  }


  BigInt operator% (BigInt n) {
    BigInt div(*this), rem(0);
    for(int i=leng-1;i>=0;i--){
      rem = rem*BigInt(10) + BigInt(div.digit[i]);
      div.digit[i] = 0;
      while(n<=rem) { rem = rem-n; div.digit[i]++; }
    }
    div.normalize();
    
    return rem;
  }

  void normalize() {
    leng = BUF-1;
    while(leng>0 && !digit[leng-1]) leng--;
  }

  void print(){
    for(int i=leng-1;i>=0;i--)
      cout << digit[i];
  }

  bool operator<= (const BigInt n) const {
    if(leng!=n.leng) return leng<n.leng;

    for(int i=leng-1;i>=0;i--)
      if(digit[i]!=n.digit[i]) return digit[i]<n.digit[i];
    
    return true;
  }

  bool operator== (const BigInt n) const {
    if(leng!=n.leng) return false;
    
    for(int i=leng-1;i>=0;i--)
      if(digit[i]!=n.digit[i]) return false;
    
    return true;
  }
};


string astr, bstr;

void read(){
  string dummy;
  cin >> astr >> dummy >> bstr;
  assert(dummy=="/");
}

BigInt gcd(BigInt a, BigInt b){
  if(b==BigInt(0)) return a;
  return gcd(b,a%b);
}

void work(){
  BigInt a(astr), b(bstr);

  BigInt div = gcd(a,b);

  a = a/div;
  b = b/div;

  a.print();
  cout << " / ";
  b.print();
  cout << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
