#include<iostream>
#include<algorithm>
#define BUF 25
using namespace std;

int LCS(int a[BUF], int b[BUF], int n){
  int dp[BUF][BUF];

  dp[0][0] = 0;
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      int lu = (i==0 || j==0) ? 0 : dp[i-1][j-1];
      int l  = (j==0) ? 0 : dp[i][j-1];
      int u  = (i==0) ? 0 : dp[i-1][j];
      
      if(a[i]==b[j])
        dp[i][j] = lu+1;
      else
        dp[i][j] = max(l,u);
    }
  
  return dp[n-1][n-1];
}

int main(){
  int n, order[BUF];

  cin >> n;
  for(int i=0;i<n;i++){
    int num; cin >> num;
    order[num-1] = i;
  }
  
  while(true){
    int v[BUF];
    for(int i=0;i<n;i++){
      int num; 
      if(!(cin >> num)) return 0;
      v[num-1] = i;
    }

    cout << LCS(order,v,n) << endl;
  }
  
  return 0;
}
