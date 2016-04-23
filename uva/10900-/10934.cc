#include<iostream>
#define BALLOON 105
#define DROP 70
#define INF (1LL<<63)
using namespace std;
typedef long long integer;

int nAvail;
integer height, dp[BALLOON][DROP];

integer rec(int balloon, int drop){
  if(balloon==0) return dp[balloon][drop] = 0;
  if(drop==0) return dp[balloon][drop] = 0;
  if(drop==1) return dp[balloon][drop] = 1;
  if(dp[balloon][drop]!=INF) return dp[balloon][drop];

  return dp[balloon][drop] = rec(balloon-1,drop-1)+rec(balloon,drop-1)+1;
}

bool read(){
  cin >> nAvail;
  if(nAvail==0) return false;
  cin >> height;
  return true;
}

void work(){
  for(int i=0;i<64;i++)
    if(rec(nAvail,i)>=height){
      cout << i << endl;
      return;
    }

  cout << "More than 63 trials needed." << endl;
}

int main(){
  for(int i=0;i<BALLOON;i++)
    for(int j=0;j<DROP;j++)
      dp[i][j] = INF;

  while(read())
    work();

  return 0;
}
