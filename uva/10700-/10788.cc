#include<iostream>
#include<cstring>
#define BUF 105
#define MULTIPLE 0
#define SINGLE 1
#define NO 2
using namespace std;

int leng;
char str[BUF];

void read(){
  cin >> str;
  leng = strlen(str);
}

int rec(int l, int r, int dp[][BUF]){
  if(dp[l][r]!=-1) return dp[l][r];
  if(r<l) return SINGLE;
  if((r-l)%2==0) return NO;
  if(r-l==1) return (str[l]==str[r] ? SINGLE : NO);
  
  int cnt = 0;
  for(int i=l+1;i<r;i++){
    if(str[l]!=str[i]) continue;
    int ret1 = rec(l+1,i-1,dp), ret2 = rec(i+1,r,dp);
    
    if(ret1!=NO && ret2!=NO){
      if(ret1==MULTIPLE || ret2==MULTIPLE) cnt += 2;
      else cnt++;
    }
  }
  if(str[l]==str[r]){
    switch(rec(l+1,r-1,dp)){
    case MULTIPLE:
      cnt+=2;
      break;
    case SINGLE:
      cnt++;
      break;
    }
  }
  
  if(cnt>1) return dp[l][r]=MULTIPLE;
  if(cnt==1) return dp[l][r]=SINGLE;
  return dp[l][r]=NO;
}

void work(int cases){
  int dp[BUF][BUF];
  for(int i=0;i<leng;i++)
    for(int j=0;j<leng;j++)
      dp[i][j] = -1;
  
  cout << "Case " << cases << ": ";
  switch(rec(0,leng-1,dp)){
  case MULTIPLE:
    cout << "Valid, Multiple" << endl;
    break;
  case SINGLE:
    cout << "Valid, Unique" << endl;
    break;
  case NO:
    cout << "Invalid" << endl;
    break;
  }
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  
  return 0;
}
