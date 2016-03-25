#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int FLOOR = 125, HOLE = 20, INF = 1<<30;

string name;
int nFloor, nHole, cost[FLOOR][HOLE][HOLE];

bool read(){
  if(!(cin >> name)) return false;
  cin >> nFloor >> nHole;
  nFloor--;
  for(int i=0;i<nFloor;i++)
    for(int j=0;j<nHole;j++)
      for(int k=0;k<nHole;k++)
        cin >> cost[i][j][k];
  return true;
}

void work(){
  int dp[FLOOR][HOLE];
  for(int i=0;i<=nFloor;i++)
    for(int j=0;j<nHole;j++)
      dp[i][j] = INF;
  
  for(int i=0;i<nHole;i++) dp[0][i] = 0;
  for(int i=0;i<nFloor;i++)
    for(int j=0;j<nHole;j++)
      for(int k=0;k<nHole;k++)
        dp[i+1][k] = min(dp[i+1][k],dp[i][j]+cost[i][j][k]+2);

  cout << name << endl;
  cout << *min_element(dp[nFloor],dp[nFloor]+nHole) << endl;
}

int main(){
  while(read()) work();
  return 0;
}
