#include<iostream>
#include<algorithm>
#include<string>
#define BUF 1005
using namespace std;

string s;

void read(){
  getline(cin,s);
}

int rec(int l, int r, int dp[][BUF]){
  if(l==r) return 1;
  if(l>r)  return 0;
  if(dp[l][r]!=-1) return dp[l][r];
  
  int maxV = -1;
  maxV = max(maxV,rec(l+1,r,dp));
  maxV = max(maxV,rec(l,r-1,dp));
  
  if(s[l]==s[r])
    maxV = max(maxV,rec(l+1,r-1,dp)+2);

  return dp[l][r]=maxV;
} 

void work(){
  if(s.size()==0) cout << 0 << endl;
  else {
    static int dp[BUF][BUF];
    for(int i=0;i<s.size();i++)
      for(int j=0;j<s.size();j++)
	dp[i][j] = -1;
    
    cout << rec(0,s.size()-1,dp) << endl;
  }
}

int main(){
  int cases;
  cin >> cases;

  string dummy; getline(cin,dummy);
  
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
