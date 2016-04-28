#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
const int BUF = 1005;

int nVal, val[BUF];

void read(){
  cin >> nVal;
  for(int i=0;i<nVal;i++) cin >> val[i];
}

// f(x) = maximum number of coins we can get from any values between [0,x]
int rec(int n, map<int,int> &dp){
  if(n==0) return 0;
  if(dp.count(n)) return dp[n];

  int maxV = 0;
  for(int i=0;i+1<nVal;i++)
    if(val[i]<=n)
      maxV = max(maxV,rec(min(val[i+1]-val[i]-1,min(n-val[i],val[i]-1)),dp)+1);
  return dp[n] = maxV;
}

void work(){
  map<int,int> dp;
  int maxV = 0;
  for(int i=0;i<nVal;i++)
    maxV = max(maxV,rec(val[i]-1,dp)+1);
  cout << maxV << endl;
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
