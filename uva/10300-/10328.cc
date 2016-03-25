#include<iostream>
using namespace std;
const int BUF = 105, BI = 40;

class BigInt{
public:
  int leng, v[BI];
  
  BigInt(){}
  BigInt(int n){
    memset(v,0,sizeof(v));
    leng = 0;
    while(n){
      v[leng++] = n%10;
      n /= 10;
    }
  }

  BigInt operator+ (BigInt opp){
    for(int i=0;i<leng;i++){
      opp.v[i] += v[i];
      if(opp.v[i]>=10){
        opp.v[i+1] += opp.v[i]/10;
        opp.v[i] %= 10;
      }
    }
    for(opp.leng=BI-1;!opp.v[opp.leng];opp.leng--); 
    opp.leng++;
    return opp;
  }

  BigInt operator* (BigInt opp){
    int t[BI] = {0};
    for(int i=0;i<leng;i++)
      for(int j=0;j<opp.leng;j++){
        t[i+j] += v[i]*opp.v[j];
        if(t[i+j]>=10){
          t[i+j+1] += t[i+j]/10;
          t[i+j] %= 10;
        }
      }
    for(int i=0;i<BI;i++){
      if(t[i]) opp.leng = i+1;
      opp.v[i] = t[i];
    }
    return opp;
  }
};

int limit, need;

bool read(){
  return cin >> limit >> need;
}

BigInt mypow(BigInt p, int n){
  if(n==0) return BigInt(1);
  BigInt t = mypow(p,n/2);
  return n&1 ? t*t*p : t*t;
}

BigInt rec(int nToss, int nCont, BigInt dp[BUF][BUF]){
  BigInt &ret = dp[nToss][nCont];
  if(ret.leng!=-1) return ret;
  if(nCont==need) return ret = mypow(BigInt(2),limit-nToss);
  if(nToss==limit) return ret = BigInt(0);
  return ret = rec(nToss+1,nCont+1,dp)+rec(nToss+1,0,dp);
}

void work(){
  static BigInt dp[BUF][BUF];
  for(int i=0;i<=limit;i++)
    for(int j=0;j<=need;j++)
      dp[i][j].leng = -1;
  rec(0,0,dp);

  for(int i=dp[0][0].leng-1;i>=0;i--)
    cout << dp[0][0].v[i];
  cout << endl;
}

int main(){
  while(read()) work();
  return 0;
}
