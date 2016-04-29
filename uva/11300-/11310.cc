#include<iostream>
using namespace std;
const int BUF = 41;

int main(){
  long long dp[BUF];
  dp[0] = dp[1] = 1;
  dp[2] = 5;
  for(int i=3;i<BUF;i++)
    dp[i] = dp[i-3]*2+dp[i-2]*4+dp[i-1];

  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    int n;
    cin >> n;
    cout << dp[n] << endl;
  }
  return 0;
}
