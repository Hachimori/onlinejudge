#include<iostream>
using namespace std;

int dp[22];

int makeTable(){
  dp[0] = 1;
  dp[1] = 0;
  
  for(int i=2;i<22;i++){
    dp[i] = 0;
    for(int j=1;j<i;j++){
      int cnt1 = 0, cnt2 = 0;        
      for(int k=1;k<j;k++) cnt1++;
      for(int k=j+1;k<i;k++) cnt2++;
      dp[i] += dp[cnt1]*dp[cnt2];
    }
  }
}

int n;

bool read(){
  return cin >> n;
}

void work(){
  cout << dp[n*2] << endl;
}

int main(){
  makeTable();
  
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  
  return 0;
}
