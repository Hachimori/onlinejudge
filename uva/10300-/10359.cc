#include<iostream>
using namespace std;
const int BUF = 255, LEN = 500;

int main(){
  int tbl[BUF][LEN], len[BUF];
  memset(tbl,0,sizeof(tbl));
  memset(len,0,sizeof(len));
  tbl[0][0] = 1;
  len[0] = 1;
  tbl[1][0] = 1;
  len[1] = 1;
  
  for(int i=2;i<BUF;i++){
    for(int j=0;j<len[i-2];j++) tbl[i][j] += tbl[i-2][j]*2;
    for(int j=0;j<len[i-1];j++) tbl[i][j] += tbl[i-1][j];
    for(int j=0;j<LEN;j++){
      if(tbl[i][j]>=10){
        tbl[i][j+1] += tbl[i][j]/10;
        tbl[i][j] %= 10;
      }
      if(tbl[i][j]) len[i] = j+1;
    }
  }

  int n;
  while(cin>>n){
    for(int i=len[n]-1;i>=0;i--)
      cout << tbl[n][i];
    cout << endl;
  }

  return 0;
}
