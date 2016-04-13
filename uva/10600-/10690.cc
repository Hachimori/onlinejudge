#include<iostream>
#include<numeric>
#include<algorithm>
#define INF (1<<30)
#define BUF 105
#define RANGE (55*100)
#define SHIFT (55*50)
using namespace std;

int N, M, val[BUF];

bool read(){
  if(!(cin >> N >> M)) return false;
  
  for(int i=0;i<N+M;i++) cin >> val[i];
  
  if(N>M) swap(N,M);
  
  return true;
}

void work(){
  static bool dp[55][RANGE];

  for(int i=0;i<=N;i++)
    for(int j=0;j<RANGE;j++)
      dp[i][j] = false;
  dp[0][0+SHIFT] = true;

  for(int i=0;i<N+M;i++)
    for(int j=N-1;j>=0;j--)
      for(int k=-50*N;k<=50*N;k++)
        if(dp[j][k+SHIFT])
          dp[j+1][k+val[i]+SHIFT] = true;
  
  int sum = accumulate(val,val+N+M,0);
  int maxV = -INF, minV = INF;
  
  for(int i=-50*N;i<=50*N;i++)
    if(dp[N][i+SHIFT]){
      maxV = max(maxV,i*(sum-i));
      minV = min(minV,i*(sum-i));
    }
      
  cout << maxV << ' ' << minV << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
