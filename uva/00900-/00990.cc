#include<iostream>
#include<algorithm>
#include<vector>
#define BUF 1005
#define DATA 35
#define INF (1<<30)
#define weight first
#define val second
using namespace std;
typedef pair<int,int> Data;

int cap, mul, nData;
Data data[DATA];

bool read(){
  if(!(cin >> cap >> mul)) return false;

  cin >> nData;
  for(int i=0;i<nData;i++)
    cin >> data[i].weight >> data[i].val;
  
  return true;
}

void work(){
  int dp[DATA][BUF], pi[DATA][BUF];

  for(int i=0;i<=nData;i++)
    for(int j=0;j<=cap;j++){
      dp[i][j] = -INF;
      pi[i][j] = -1;
    }
  dp[0][0] = 0;
  
  for(int i=0;i<nData;i++)
    for(int j=cap;j>=0;j--){
      if(dp[i+1][j]<dp[i][j]){
	dp[i+1][j] = dp[i][j];
	pi[i+1][j] = j;
      }

      int nextWeight = j+data[i].weight*mul*3;
      if(nextWeight<=cap && dp[i+1][nextWeight]<dp[i][j]+data[i].val){
	dp[i+1][nextWeight] = dp[i][j]+data[i].val;
	pi[i+1][nextWeight] = j;
      }
    }
  

  int maxV = -1, maxIdx;
  for(int i=0;i<=cap;i++)
    if(maxV<dp[nData][i]){
      maxV = dp[nData][i];
      maxIdx = i;
    }

  vector<int> ans;
  for(int cur=maxIdx,i=nData;;i--){
    if(pi[i][cur]==-1) break;
    if(pi[i][cur]!=cur){
      ans.push_back(i-1);
      cur -= data[i-1].weight*mul*3;
    }
  }

  cout << maxV << endl;
  cout << ans.size() << endl;
  for(int i=ans.size()-1;i>=0;i--)
    cout << data[ans[i]].weight << ' ' << data[ans[i]].val << endl;
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  
  return 0;
}
