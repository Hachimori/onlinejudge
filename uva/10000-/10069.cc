#include<iostream>
#include<vector>
using namespace std;
const int DIGIT = 105, BUF = 105;


class BigInt{
public:
  int len, digit[DIGIT];
  BigInt(){}
  BigInt(int n){
    memset(digit,0,sizeof(digit));
    if(n==-1){
      len = -1;
      return;
    }
    len = 0;
    while(n){
      digit[len] = n%10;
      len++;
      n /= 10;
    }
  }

  BigInt operator+ (BigInt opp) {
    for(int i=0;i<DIGIT;i++){
      opp.digit[i] += digit[i];
      if(opp.digit[i]>=10){
        opp.digit[i+1]++;
        opp.digit[i]-=10;
      }
      if(opp.digit[i]) opp.len = i+1;
    }
    return opp;
  }

  void print(){
    if(len==0) cout << 0;
    for(int i=len-1;i>=0;i--)
      cout << digit[i];
    cout << endl;
  }
};


string X, Z;

void read(){
  cin >> X >> Z;
}


void work(){
  static BigInt dp[2][BUF];
  for(int i=0;i<2;i++)
    for(int j=0;j<=Z.size();j++)
      dp[i][j] = 0;

  dp[0][0] = 1;
  for(int i=0;i<X.size();i++){
    for(int j=0;j<=Z.size();j++)
      dp[1][j] = dp[1][j]+dp[0][j];

    for(int j=0;j<Z.size();j++)
      if(X[i]==Z[j]) 
        dp[1][j+1] = dp[1][j+1]+dp[0][j];

    for(int j=0;j<=Z.size();j++){
      dp[0][j] = dp[1][j];
      dp[1][j] = 0;
    }
  }
  
  dp[0][Z.size()].print();
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
