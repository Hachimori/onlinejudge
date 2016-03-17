#include<iostream>
using namespace std;
const int BUF = 35;

int nMove, adj[BUF][BUF];
bool isGoal[BUF];

bool read(){
  memset(adj,0,sizeof(adj));
  memset(isGoal,0,sizeof(isGoal));
  int nNode;
  if(!(cin >> nNode)) return false;
  for(int i=0;i<nNode;i++){
    char src, dst1, dst2, isGoalCh;
    cin >> src >> dst1 >> dst2 >> isGoalCh;
    adj[src-'A'][dst1-'A']++;
    adj[src-'A'][dst2-'A']++;
    isGoal[src-'A'] = isGoalCh=='x';
  }
  cin >> nMove;
  return true;
}

void work(){
  int dp[BUF][BUF]={};
  dp[0][0] = 1;
  for(int i=0;i<nMove;i++)
    for(int src=0;src<BUF;src++)
      for(int dst=0;dst<BUF;dst++)
        dp[i+1][dst] += adj[src][dst]*dp[i][src];
  
  int sum = 0;
  for(int i=0;i<BUF;i++)
    if(isGoal[i])
      sum += dp[nMove][i];
  cout << sum << endl;
}

int main(){
  while(read()) work();
  return 0;
}
