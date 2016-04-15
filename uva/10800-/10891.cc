#include<iostream>
#include<algorithm>
#define BUF 100
#define INF (1<<30)
using namespace std;

int nNum, num[BUF];

bool read(){
  cin >> nNum;
  if(nNum==0) return false;
  
  for(int i=0;i<nNum;i++) cin >> num[i];
  return true;
}

int rec(int L, int R, int dp[BUF][BUF]){
  if(L>R) return 0;
  if(dp[L][R]!=-INF) return dp[L][R];
  
  int maxV = -INF, sum = 0;
  for(int i=L;i<=R;i++){
    sum += num[i];
    maxV = max(maxV,sum-rec(i+1,R,dp));
  }
    
  sum = 0;
  for(int i=R;i>=L;i--){
    sum += num[i];
    maxV = max(maxV,sum-rec(L,i-1,dp));
  }

  return dp[L][R] = maxV;
}

void work(){
  int dp[BUF][BUF];
  for(int i=0;i<nNum;i++)
    for(int j=0;j<nNum;j++)
      dp[i][j] = -INF;

  cout << rec(0,nNum-1,dp) << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
