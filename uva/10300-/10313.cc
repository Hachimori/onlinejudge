#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
typedef long long integer;
const int INF = 1<<20, BUF = 305;

int minC, maxC, toPay;

bool read(){
  string s;
  if(getline(cin,s)==NULL) return false;
  stringstream in(s);

  vector<int> nList;

  int v;
  while(in >> v) nList.push_back(v);
  
  toPay = nList[0];
  minC = 0;
  maxC = toPay;
  if(nList.size()==2){
    maxC = nList[1];
  }
  else if(nList.size()==3){
    minC = nList[1];
    maxC = nList[2];
  }
  
  return true;
}

integer dp[BUF][BUF];
integer rec(int n, int r){
  if(n<r) return 0;
  if(n==r) return 1;
  if(r==1) return 1;
  if(dp[n][r]!=-1) return dp[n][r];
  return dp[n][r] = rec(n-r,r)+rec(n-1,r-1);
}

void work(){
  if(toPay==0){
    cout << (minC==0) << endl;
    return;
  }
  integer sum = 0;
  for(int i=max(1,minC);i<=maxC;i++)
    sum += rec(toPay,i);
  cout << sum << endl;
}

int main(){
  memset(dp,-1,sizeof(dp));
  while(read()) work();
  return 0;
}
