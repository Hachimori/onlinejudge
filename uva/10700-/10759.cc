#include<iostream>
using namespace std;
const int DICE = 25, BUF = 155;

long long gcd(long long a, long long b){
  return b==0 ? a : gcd(b,a%b);
}

int main(){
  long long dp[DICE][BUF]={0};
  dp[0][0] = 1;
  for(int i=0;i<24;i++)
    for(int j=0;j<BUF;j++)
      if(dp[i][j])
        for(int k=1;k<=6;k++)
          dp[i+1][j+k] += dp[i][j];

  int nDice, atLeast;
  while(cin >> nDice >> atLeast,nDice|atLeast){
    long long nume = 0;
    for(int i=atLeast;i<BUF;i++) nume += dp[nDice][i];

    long long deno = 1;
    for(int i=0;i<nDice;i++) deno *= 6;
    
    long long div = gcd(nume,deno);
    nume /= div;
    deno /= div;

    if(nume==0)
      cout << 0 << endl;
    else if(deno==1)
      cout << 1 << endl;
    else
      cout << nume << '/' << deno << endl;
  }
  return 0;
}
