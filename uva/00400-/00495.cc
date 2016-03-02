#include<iostream>
using namespace std;
const int NUM = 5001, LEN = 2000;

int main(){
  static int bi[NUM][LEN]={0}, len[NUM]={0};
  
  bi[0][0] = 0, len[0] = 0;
  bi[1][0] = 1, len[1] = 1;
  for(int i=2;i<NUM;i++){
    for(int j=0;j<len[i-1];j++)
      bi[i][j] = bi[i-1][j]+bi[i-2][j];
    for(int j=0;j<LEN;j++){
      if(bi[i][j]>=10){
        if(j+1==LEN) exit(1);
        bi[i][j+1] += bi[i][j]/10;
        bi[i][j] %= 10;
      }
      if(bi[i][j]) len[i] = j+1;   
    }
  }

  int n;
  while(cin >> n){
    cout << "The Fibonacci number for " << n << " is ";
    if(n==0)
      cout << 0 << endl;
    else{
      for(int i=len[n]-1;i>=0;i--)
        cout << bi[n][i];
      cout << endl;
    }
  }

  return 0;
}
