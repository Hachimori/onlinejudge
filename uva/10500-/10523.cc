#include<iostream>
using namespace std;
const int BUF = 300;

class BigInt{
public:
  int len, v[BUF];
  BigInt(){}
  BigInt(int n){
    len = 0;
    memset(v,0,sizeof(v));
    while(n){
      v[len++] = n%10;
      n /= 10;
    }
  }

  BigInt operator+ (BigInt bi){
    for(int i=0;i<BUF;i++)
      bi.v[i] += v[i];
    for(int i=0;i<BUF;i++){
      if(bi.v[i]) bi.len = i+1;
      if(bi.v[i]>=10){
        bi.v[i+1] += bi.v[i]/10;
        bi.v[i] %= 10;
      }
    }
    return bi;
  }

  BigInt operator* (BigInt bi){
    BigInt ret = 0;
    for(int i=0;i<len;i++)
      for(int j=0;j<bi.len;j++)
        ret.v[i+j] += v[i]*bi.v[j];
    for(int i=0;i<BUF;i++){
      if(ret.v[i]) ret.len = i+1;
      if(ret.v[i]>=10){
        ret.v[i+1] += ret.v[i]/10;
        ret.v[i] %= 10;
      }
    }
    return ret;
  }
};

int n, a;

bool read(){
  return cin >> n >> a;
}

BigInt pow(BigInt p, int n){
  if(n==0) return 1;
  BigInt t = pow(p,n/2);
  return n&1 ? t*t*p : t*t;
}

void work(){
  BigInt ans = 0;
  for(int i=1;i<=n;i++)
    ans = ans+pow(BigInt(a),i)*i;
  for(int i=ans.len-1;i>=0;i--)
    cout << ans.v[i];
  if(ans.len==0)
    cout << 0;
  cout << endl;
}

int main(){
  while(read()) work();
  return 0;
}
