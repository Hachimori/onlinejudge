#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cassert>
#define BUF 60
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

  int operator% (int n) {
    BigInt div(*this);
    int rem = 0;
    for(int i=leng-1;i>=0;i--){
      rem = rem*10+div.digit[i];
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

  bool operator< (const BigInt n) const {
    if(leng!=n.leng) return leng<n.leng;

    for(int i=leng-1;i>=0;i--)
      if(digit[i]!=n.digit[i]) return digit[i]<n.digit[i];
    
    return false;
  }
};

string s;

bool read(){
  cin >> s;
  return s!="0";
}

void print(string name){
  cout << "Ghost of " << name << "!!!" << endl;
}

void work(){
  BigInt num(s);

  cout << s << endl;

  
  if(num<BigInt(2148)){
    cout << "No ghost will come in this year" << endl;
    return;
  }

  bool came = false;
  bool leap = (num%4==0 && num%100!=0) || num%400==0;
  num = num-BigInt(2148);
  
  if(num%2==0){
    came = true;
    print("Tanveer Ahsan");
  }

  if(num%5==0){
    came = true;
    print("Shahriar Manzoor");
  }

  if(num%7==0){
    came = true;
    print("Adrian Kugel");
  }

  if(num%11==0){
    came = true;
    print("Anton Maydell");
  }
    
  if(num%15==0){
    came = true;
    print("Derek Kisman");
  }

  if(num%20==0){
    came = true;
    print("Rezaul Alam Chowdhury");
  }
    
  if(num%28==0){
    came = true;
    print("Jimmy Mardell");
  }
  
  if(num%36==0){
    came = true;
    print("Monirul Hasan");
  }
  
  if(leap){
    came = true;
    print("K. M. Iftekhar");
  }

  if(!came)
    cout << "No ghost will come in this year" << endl;
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }

  return 0;
}
