#include<iostream>
using namespace std;
const int BUF = 10005, INF = 1<<20;

int main(){
  int dp[BUF];
  for(int i=0;i<BUF;i++) dp[i] = INF;
  dp[0] = 0;
  for(int i=0;i<BUF;i++)
    for(int j=1;i+j*j<BUF;j++)
      dp[i+j*j] = min(dp[i+j*j],dp[i]+1);

  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    int n;
    cin >> n;
    cout << dp[n] << endl;
  }
  return 0;
}
