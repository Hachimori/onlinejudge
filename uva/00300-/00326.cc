#include<iostream>
using namespace std;
const int BUF = 15;

int nVal, val[BUF], term;

bool read(){
  cin >> nVal;
  if(nVal==0) return false;
  for(int i=0;i<nVal;i++) cin >> val[i];
  cin >> term;
  return true;
}


int rec(int row, int col, int dp[BUF][BUF]){
  int &ret = dp[row][col];
  if(ret!=-1) return ret;
  if(row==0) return ret = val[col];
  return ret = rec(row-1,col+1,dp)-rec(row-1,col,dp);
}


void work(){
  int dp[BUF][BUF];
  memset(dp,-1,sizeof(dp));

  long long last[BUF];
  for(int i=0;i<nVal;i++)
    last[i] = rec(i,nVal-i-1,dp);

  for(int i=0;i<term;i++)
    for(int j=nVal-1;j-1>=0;j--)
      last[j-1] += last[j];
  
  cout << "Term " << nVal+term << " of the sequence is " << last[0] << endl;
}


int main(){
  while(read()) work();
  return 0;
}
