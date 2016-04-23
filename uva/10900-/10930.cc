#include<iostream>
#include<algorithm>
#define NUM 35
#define BUF 2005
using namespace std;

int nNum, num[NUM];

bool read(){
  if(!(cin >> nNum)) return false;
  
  for(int i=0;i<nNum;i++)
    cin >> num[i];
  
  return true;
}

void work(int cases){
  bool dp[NUM][BUF];
  int cnum[NUM];
  
  for(int i=0;i<nNum;i++)
    cnum[i] = num[i];
  sort(cnum,cnum+nNum);
  
  for(int i=0;i<NUM;i++)
    for(int j=0;j<BUF;j++)
      dp[i][j] = false;
  dp[0][0] = true;
  

  bool ok = true;
  
  for(int i=0;i<nNum;i++){
    if(dp[i][cnum[i]]) {
      ok = false;
      break;
    }
    for(int j=0;j<BUF;j++)
      if(dp[i][j]){
	dp[i+1][j] = true;
	if(j+cnum[i]<BUF)
	  dp[i+1][j+cnum[i]] = true;
      }
  }

  for(int i=0;i<nNum;i++)
    if(cnum[i]!=num[i])
      ok = false;
  
  if(unique(cnum,cnum+nNum)-cnum!=nNum)
    ok = false;

  cout << "Case #" << cases << ":";
  for(int i=0;i<nNum;i++)
    cout << ' ' << num[i];
  cout << endl;

  if(ok) cout << "This is an A-sequence." << endl;
  else cout << "This is not an A-sequence." << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);

  return 0;
}
