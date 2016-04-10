#include<iostream>
#include<algorithm>
#define BUF 2000
#define NUM 801
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

  
  BigInt operator* (int n) {
    BigInt ret(0);
    
    for(int i=0;i<leng;i++){
      ret.digit[i] += digit[i]*n;

      for(int j=0;ret.digit[i+j]>=10;j++){
	ret.digit[i+j+1] += ret.digit[i+j]/10;
	ret.digit[i+j] %= 10;
      }
    }
    ret.normalize();

    return ret;
  }
  

  void normalize() {
    leng = BUF-1;
    while(leng>0 && !digit[leng-1]) leng--;
  }

  void print(){
    if(leng==0) cout << 0;
    for(int i=leng-1;i>=0;i--)
      cout << digit[i];
    cout << endl;
  }
};

BigInt dp[NUM];


void makeTable(){
  dp[0] = BigInt(1);
  dp[1] = BigInt(0);
  
  for(int k=2;k<NUM;k++)
    dp[k] = (dp[k-1]+dp[k-2])*(k-1);
}

int num;

bool read(){
  cin >> num;
  return num!=-1;
}

void work(){
  dp[num].print();
}

int main(){
  makeTable();

  while(read())
    work();
  
  return 0;
}
