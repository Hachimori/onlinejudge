#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cassert>
#define BUF 1000
using namespace std;

class BigInt {
public:
  int digit[BUF], leng;
  
  BigInt(){}
  BigInt(char s[BUF]){
    leng = strlen(s);
    
    for(int i=0;i<leng;i++)
      digit[i] = s[leng-i-1]-'0';
  }
  
  int operator% (int n) {
    assert(n!=0);      // ƒ[ƒŠ„‚èŽZƒ`ƒFƒbƒN

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
};

char s[BUF];

bool read(){
  return scanf("%s",s)!=EOF;
}

void work(){
  BigInt num(s);
  
  bool leap = false, hulu = false, bulu = false;
  
  if((num%4==0 && !(num%100==0)) || num%400==0)
    leap = true;
  
  if(num%15==0)
    hulu = true;

  if(leap && num%55==0)
    bulu = true;

  
  if(leap)
    cout << "This is leap year." << endl;
  
  if(hulu)
    cout << "This is huluculu festival year." << endl;

  if(bulu)
    cout << "This is bulukulu festival year." << endl;

  if(!(leap|hulu|bulu))
    cout << "This is an ordinary year." << endl;
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  
  return 0;
}
