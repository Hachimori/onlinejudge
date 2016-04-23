#include<iostream>
#define BUF 75
using namespace std;

int nSubject, point;

void read(){
  int toPay;
  cin >> nSubject >> point >> toPay;
  
  point -= toPay*nSubject;
}

int rec(int curr, int pt, int dp[][BUF]){
  if(dp[curr][pt]!=-1) return dp[curr][pt];
  if(curr==nSubject){
    return dp[curr][pt] = (pt==0 ? 1 : 0);
  }
  
  int sum = 0;
  for(int i=0;i<=pt;i++)
    sum += rec(curr+1,pt-i,dp);

  return dp[curr][pt]=sum;
}

void work(){
  int dp[BUF][BUF];
  for(int i=0;i<=nSubject;i++)
    for(int j=0;j<=point;j++)
      dp[i][j] = -1;
  
  if(point<0) cout << 0 << endl;
  else cout << rec(0,point,dp) << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
