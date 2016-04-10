#include<iostream>
#include<algorithm>
#include<string>
#define BUF 1000
using namespace std;

class BigInt {
public:
  int digit[BUF], leng, sign;
  
  BigInt(){}
  
  BigInt(int n){
    leng = 0, sign = 1;
    fill(digit,digit+BUF,0);
    
    while(n>0){
      digit[leng++] = n%10;
      n /= 10;
    }
  }
  
  BigInt(string s){
    leng = s.size(), sign = 1;
    fill(digit,digit+BUF,0);
    
    for(int i=0;i<leng;i++)
      digit[i] = s[leng-i-1]-'0';
  }

  
  int toInt(){
    int ret = 0;
    for(int i=leng-1;i>=0;i--)
      ret = ret*10 + digit[i];

    return ret;
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
    
    if(n<=ret){
      int limit = max(leng,n.leng);
      for(int i=0;i<limit;i++) {
        if(i<n.leng) ret.digit[i] -= n.digit[i];
        if(ret.digit[i]<0){
          ret.digit[i+1]--;
          ret.digit[i] += 10;
        }
      }
    }
    else {
      ret = n - ret;
      ret.sign = -1;
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
    if(leng==0)
      cout << 0;
    
    for(int i=leng-1;i>=0;i--)
      cout << digit[i];
    cout << endl;
  }

  bool operator<= (const BigInt n) const {
    if(leng!=n.leng) return leng<n.leng;

    for(int i=leng-1;i>=0;i--)
      if(digit[i]!=n.digit[i]) return digit[i]<n.digit[i];
    
    return true;
  }

};

string L, ope, R;

bool read(){
  return (cin >> L >> ope >> R);
}

void work(){
  BigInt a(L), b(R), ans;
  
  if(ope=="+")
    ans = a+b;

  if(ope=="-")
    ans = a-b;

  if(ope=="/")
    ans = a/b;

  if(ope=="%")
    ans = a%b;
  
  if(ans.sign==-1) cout << '-';
  ans.print();
}

int main(){
  while(read())
    work();
  
  return 0;
}
