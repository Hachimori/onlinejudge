#include<iostream>
#include<algorithm>
#define NUM 2505
#define BUF 500
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
    if(leng==0) cout << 0;
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

  
  BigInt operator- (int n) {
    BigInt ret(*this);
    
    ret.digit[0] -= n;
    
    int cur = 0;
    while(ret.digit[cur]<0){
      ret.digit[cur+1] -= (-ret.digit[cur]/10+1);
      ret.digit[cur] += (-ret.digit[cur]/10+1)*10;
      cur++;
    }
    
    ret.normalize();
    
    return ret;
  }


  BigInt operator/ (int n){
    BigInt div(*this);
    int rem = 0;
    
    for(int i=leng-1;i>=0;i--){
      rem = rem*10 + div.digit[i];
      div.digit[i] = 0;
      while(n<=rem) { rem = rem-n; div.digit[i]++; }
    }
    div.normalize();
    
    return div;
  }

  void normalize() {
    leng = BUF-1;
    while(leng>0 && !digit[leng-1]) leng--;
  }

  bool operator<= (const BigInt n) const {
    if(leng!=n.leng) return leng<n.leng;

    for(int i=leng-1;i>=0;i--)
      if(digit[i]!=n.digit[i]) return digit[i]<n.digit[i];
    
    return true;
  }
};

BigInt median[NUM];

void makeTable(){
  static BigInt fib[NUM], sum[NUM];
  
  fib[0] = fib[1] = BigInt(1);
  sum[0] = BigInt(1);
  sum[1] = BigInt(2);
  
  for(int i=2;i<NUM;i++){
    fib[i] = fib[i-1]+fib[i-2];
    sum[i] = fib[i]+sum[i-1];
  }

  
  median[0] = BigInt(0);
  for(int i=1;i<NUM;i++)
    median[i] = sum[i-1]+(fib[i]-1)/2;
}

int n;

bool read(){
  cin >> n;
  return n!=0;
}

void work(int cases){
  cout << "Set " << cases << ":" << endl;
  median[n-1].print();
}

int main(){
  makeTable();
  
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
