#include<iostream>
using namespace std;
const int BASE = 129, BUF = 101, DIGIT = 250;

class bi{
public:
  int leng, digit[DIGIT];

  bi(){}
  bi(int n){
    memset(digit,0,sizeof(digit));
    leng = 0;
    while(n){
      digit[leng++] = n%10;
      n /= 10;
    }
  }

  bi operator+ (bi opp){
    for(int i=0;i<leng;i++)
      opp.digit[i] += digit[i];
    for(int i=0;i<DIGIT;i++){
      if(opp.digit[i]>=10){
        opp.digit[i+1] += opp.digit[i]/10;
        opp.digit[i] %= 10;
      }
      if(opp.digit[i]) opp.leng = i+1;
    }
    return opp;
  }

  bi operator* (int n){
    bi ret = 0;
    for(int i=0;i<leng;i++)
      ret.digit[i] += digit[i]*n;
    for(int i=0;i<DIGIT;i++){
      if(ret.digit[i]>=10){
        ret.digit[i+1] += ret.digit[i]/10;
        ret.digit[i] %= 10;
      }
      if(ret.digit[i]) ret.leng = i+1;
    }
    return ret;
  }

  void print(){
    for(int i=leng-1;i>=0;i--)
      cout << digit[i];
    cout << endl;
  }
};

bi rec(bool prevOne, int nPut, int B, int N, bi dp[2][BUF]){
  if(nPut==0) return 1;
  bi &ret = dp[prevOne][nPut];
  if(ret.leng!=-1) return ret;
  ret = 0;
  if(prevOne){
    ret = ret+rec(0,nPut-1,B,N,dp)*(B-2);
    ret = ret+rec(1,nPut-1,B,N,dp);      
  }
  else{
    ret = ret+rec(0,nPut-1,B,N,dp)*(B-1);
    ret = ret+rec(1,nPut-1,B,N,dp);
  }
  return ret;
}

int main(){
  static bi dp[BASE][2][BUF];
  for(int i=0;i<BASE;i++)
    for(int j=0;j<2;j++)
      for(int k=0;k<BUF;k++)
        dp[i][j][k].leng = -1;

  int B, N;
  while(cin >> B >> N,B|N){
    bi ans = 0;
    ans = ans+rec(1,N-1,B,N,dp[B]);
    ans = ans+rec(0,N-1,B,N,dp[B])*(B-2);
    ans.print();
  }
  return 0;
}
