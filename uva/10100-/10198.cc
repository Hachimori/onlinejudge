#include<iostream>
using namespace std;
const int BUF = 1001, DIGIT = 1000;

using namespace std;

class BigInt {
public:
  int digit[DIGIT], leng;
  
  BigInt(){}
  BigInt(int n){
    memset(digit,0,sizeof(digit));
    leng = 0;
    while(n>0){ 
      digit[leng++] = n%10; 
      n /= 10;
    }
  }

  void print(){
    for(int i=leng-1;i>=0;i--)
      cout << digit[i];
    cout << endl;
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
  
  void normalize() {
    leng = DIGIT-1;
    while(leng>0 && !digit[leng-1]) leng--;
  }
};


int main(){
  static BigInt dp[BUF];
  dp[0] = 1;
  dp[1] = 2;
  dp[2] = 5;
  for(int i=3;i<BUF;i++)
    dp[i] = dp[i-1]*2+dp[i-2]+dp[i-3];


  int n;
  while(cin >> n)
    dp[n].print();
  
  return 0;
}
