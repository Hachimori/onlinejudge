#include<iostream>
#include<map>
using namespace std;

int rec(long long n, int limit, map<long long,int> &dp){
  if(n>=limit) return dp[n] = 0;
  if(dp.count(n)) return dp[n];
  for(int i=2;i<=9;i++)
    if(!rec(n*i,limit,dp))
      return dp[n] = 1;
  return dp[n] = 0;
}

int main(){
  int n;
  while(cin >> n){
    map<long long, int> dp;
    cout << (rec(1,n,dp) ? "Stan wins." : "Ollie wins.") << endl;
  }
  return 0;
}
