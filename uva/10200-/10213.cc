#include<iostream>
#include<algorithm>
#define BUF 1000
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
  
  
  BigInt operator/ (int n){
    BigInt div = 0;
    int rem = 0;
    for(int i=leng-1;i>=0;i--){
      rem = rem*10 + digit[i];
      div.digit[i] = rem/n;
      rem = rem%n;
    }
    div.normalize();
    
    return div;
  }

  void normalize() {
    leng = BUF-1;
    while(leng>0 && !digit[leng-1]) leng--;
  }
};

BigInt bino(int n, int k){
  return k==0 ? 1 : bino(n-1,k-1)*n/k;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    int n;
    cin >> n;
    BigInt ans = 0;
    for(int j=0;j<=2;j++) 
      ans = ans+bino(n,j*2);
    ans.print();
  }
  return 0;
}
