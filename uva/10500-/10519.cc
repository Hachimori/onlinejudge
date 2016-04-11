#include<iostream>
#include<string>
using namespace std;
const int BUF = 210;

class BigInt{
public:
  int len, v[BUF];

  BigInt(){}
  BigInt(int n){
    memset(v,0,sizeof(v));
    len = 0;
    while(n){
      v[len++] = n%10;
      n /= 10;
    }
  }
  BigInt(string s){
    memset(v,0,sizeof(v));
    len = s=="0" ? 0 : s.size();
    for(int i=0;i<s.size();i++)
      v[len-i-1] = s[i]-'0';
  }

  BigInt operator* (BigInt opp){
    BigInt ret("0");
    for(int i=0;i<len;i++)
      for(int j=0;j<opp.len;j++)
        ret.v[i+j] += v[i]*opp.v[j];
    ret.normalize();
    return ret;
  }

  BigInt operator+ (BigInt opp){
    for(int i=0;i<len;i++)
      opp.v[i] += v[i];
    opp.normalize();
    return opp;
  }
  
  BigInt minusOne(){
    BigInt ret = *this;
    ret.v[0]--;
    for(int i=0;i<len;i++)
      if(ret.v[i]<0){
        ret.v[i] += 10;
        ret.v[i+1]--;
      }
    ret.normalize();
    return ret;
  }

  void normalize(){
    for(int i=0;i<BUF;i++){
      v[i+1] += v[i]/10;
      v[i] %= 10;
      if(v[i]) len = i+1;
    }
  }

  void print(){
    for(int i=len-1;i>=0;i--)
      cout << v[i];
    cout << endl;
  }
};

string s;

bool read(){
  return cin >> s;
}

void work(){
  if(s=="0"){
    cout << 1 << endl;
    return;
  }
  BigInt bi(s);
  (bi*(bi.minusOne())+2).print();
}

int main(){
  while(read()) work();
  return 0;
}
