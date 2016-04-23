#include<iostream>
#define BUF 31
using namespace std;

int num, dp[BUF];

int rec(int num){
  if(dp[num]!=-1) return dp[num];
  if(num%2==1) return dp[num] = 0;
  if(num==0) return dp[num] =  1;
  if(num==2) return dp[num] =  3;

  dp[num] = 3*rec(num-2);
  for(int i=4;num-i>=0;i+=2)
    dp[num] += 2*rec(num-i);

  return dp[num];
}

bool read(){
  cin >> num;
  return num!=-1;
}

void work(){
  cout << rec(num) << endl;
}

int main(){
  for(int i=0;i<BUF;i++) dp[i] = -1;
  
  while(read())
    work();

  return 0;
}
