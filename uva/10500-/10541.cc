#include<iostream>
using namespace std;
const int BIBUF = 55, BUF = 205;

class BigInt{
public:
  int len, v[BIBUF];
  BigInt(){}
  BigInt(int n){
    memset(v,0,sizeof(v));
    len = 0;
    while(n){
      v[len++] = n%10;
      n /= 10;
    }
  }

  BigInt operator+ (BigInt opp){
    for(int i=0;i<len;i++) opp.v[i] += v[i];
    for(int i=0;i<BIBUF;i++){
      if(opp.v[i]>=10){
        opp.v[i+1] += opp.v[i]/10;
        opp.v[i] %= 10;
      }
      if(opp.v[i])
        opp.len = i+1;
    }
    return opp;
  }

  void print(){
    if(len==0){
      cout << 0 << endl;
      return;
    }
    for(int i=len-1;i>=0;i--)
      cout << v[i];
    cout << endl;
  }
};

int leng, nCode, code[BUF];

bool read(){
  cin >> leng >> nCode;
  for(int i=0;i<nCode;i++)
    cin >> code[i];
}

BigInt rec(int len, int cod, BigInt dp[BUF][BUF]){
  if(len>=leng)
    return cod==nCode ? 1 : 0;
  if(cod==nCode)
    return 1;
  BigInt &ret = dp[len][cod];
  if(ret.len!=-1) return ret;
  ret = 0;
  if(len+code[cod]<=leng)
    ret = ret+rec(len+code[cod]+1,cod+1,dp)+rec(len+1,cod,dp);
  else
    ret = ret+rec(len+1,cod,dp);
  return ret;
}

void work(){
  static BigInt dp[BUF][BUF];
  for(int i=0;i<leng;i++)
    for(int j=0;j<nCode;j++)
      dp[i][j].len = -1;
  rec(0,0,dp).print();
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
