#include<iostream>
#define BUF 77
using namespace std;

int dp[BUF], num;

int rec(int curr){
  if(curr==1) return dp[curr] = 1;
  if(curr==2) return dp[curr] = 2;
  if(curr==3) return dp[curr] = 2;
  if(dp[curr]!=-1) return dp[curr];
  
  return dp[curr] = rec(curr-2) + rec(curr-3);
}

bool read(){
  return (cin >> num);
}

void work(){
  cout << rec(num) << endl;
}

int main(){
  for(int i=0;i<BUF;i++)
    dp[i] = -1;
  
  while(read())
    work();
  
  return 0;
}


