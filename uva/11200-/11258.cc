#include<iostream>
#include<algorithm>
#include<cstdio>
#include<climits>
#define BUF 205
#define INF INT_MAX
using namespace std;
typedef long long integer;

int n;
char str[BUF];

void read(){
  cin >> str;
  n = strlen(str);
}

integer toNum(int L, int R){
  integer ret = 0;
  for(int i=L;i<=R;i++){
    ret *= 10;
    ret += str[i]-'0';
    if(ret>INF) return 1LL+INF;
  }
  return ret;
}

void work(){
  integer dp[BUF];
  
  for(int L=n-1;L>=0;L--){
    dp[L] = toNum(L,n-1);
    if(dp[L]>INF) dp[L] = -1;
    else continue;
    
    for(int k=L;k+1<n;k++){
      integer val = toNum(L,k);
      if(val>INF) continue;
      dp[L] = max(dp[L],val+dp[k+1]);
    }
  }
  
  cout << dp[0] << endl;
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
