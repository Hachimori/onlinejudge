#include<iostream>
#include<cassert>
using namespace std;
const int BUF = 3000;

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

  BigInt operator* (BigInt n) {
    BigInt ret(*this);
    ret *= n;
    return ret;
  }

  BigInt& operator*= (BigInt n) {
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
    return *this = ret;
  }

  void normalize() {
    leng = BUF-1;
    while(leng>0 && !digit[leng-1]) leng--;
  }
};

int main(){
  int n;
  static BigInt tbl[1001];
  tbl[0] = tbl[1] = 1;
  for(int i=2;i<=1000;i++)
    tbl[i] = tbl[i-1]*i;

  while(cin >> n){
    assert(n<=1000);
    cout << n << "!" << endl;
    for(int i=tbl[n].leng-1;i>=0;i--)
      cout << tbl[n].digit[i];
    cout << endl;
  }
  return 0;
}
