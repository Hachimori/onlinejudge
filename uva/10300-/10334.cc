#include<iostream>
#define BUF 1001
using namespace std;

int main(){
  static int len[BUF], tbl[BUF][BUF];

  memset(len,0,sizeof(len));
  memset(tbl,0,sizeof(tbl));

  len[0] = 1;
  tbl[0][0] = 1;
  len[1] = 1;
  tbl[1][0] = 2;

  for(int i=2;i<BUF;i++){
    for(int j=-2;j<0;j++)
      for(int k=0;k<len[i+j];k++)
        tbl[i][k] += tbl[i+j][k];

    for(int j=0;j<BUF;j++){
      if(tbl[i][j]) len[i] = j+1;
      if(tbl[i][j]>=10){
        tbl[i][j+1]++;
        tbl[i][j] -= 10;
      }
    }
  }
  
  while(1){
    int n;
    if(!(cin >> n)) break;

    for(int i=len[n]-1;i>=0;i--)
      cout << tbl[n][i];
    cout << endl;
  }

  return 0;
}
