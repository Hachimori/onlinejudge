// DP
//
// calc(l,r) は文字列をlからrにかけて1段階圧縮する。
// 長さlengの圧縮ができたら、lengの中で更に圧縮が可能な場合があるので
// lengの範囲に合わせてcalc()を呼んで圧縮し、最短の文字列を返す。

#include<iostream>
#include<algorithm>
#include<string>
#define BUF 100
using namespace std;

string s;

bool read(){
  cin >> s;
  return s!="*";
}

int calc(int l, int r){
  for(int leng=1;leng<=r-l+1;leng++){
    if((r-l+1)%leng!=0) continue;
    
    bool ok = true;
    for(int i=l;i+leng<=r;i+=leng)
      for(int j=i,k=i+leng;j<i+leng;j++,k++)
	if(s[j]!=s[k]){
	  ok = false;
	  goto finish;
	}
  finish:
    
    if(ok){
      if(r-l+1==leng) return leng;
      
      int dp[BUF];
      fill(dp+l,dp+l+leng+1,100);
      dp[l] = 0;
      
      for(int i=l;i<l+leng;i++)
	for(int j=i;j<l+leng;j++)
	  dp[j+1] = min(dp[j+1],dp[i]+calc(i,j));
	  
      return dp[l+leng];
    }
  }
} 

void work(){
  int dp[BUF];
  fill(dp,dp+s.size()+1,100);
  
  dp[0] = 0;

  for(int i=0;i<s.size();i++)
    for(int j=i;j<s.size();j++)
      dp[j+1] = min(dp[j+1],dp[i]+calc(i,j));

  cout << dp[s.size()] << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
