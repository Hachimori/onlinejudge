#include<iostream>
using namespace std;
const int BUF = 100000;

int L, R;

bool read(){
  return cin >> L >> R;
}

int calc(int n){
  int ret = 0;
  while(n){
    ret += (n%10)*(n%10);
    n /= 10;
  }
  return ret;
}

int dp[BUF];
int rec(int n){
  int &ret = dp[n];
  if(ret!=-1) return ret;
  if(n==1) return ret = 1;
  ret = -2;
  int t = rec(calc(n));
  return ret = t + (t<0 ? 0 : 1);
}

void work(){
  for(int i=L;i<=R;i++)
    if(rec(i)>=0)
      cout << i << ' ' << dp[i] << endl;
}

int main(){
  memset(dp,-1,sizeof(dp));
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  return 0;
}
