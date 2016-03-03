#include<iostream>
using namespace std;
const int BUF = 105;

int n, b[BUF][BUF];

bool read(){
  cin >> n;
  if(n==0) return false;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin >> b[i][j];
  return true;
}

void work(){
  int rCnt = 0, rPos, cCnt = 0, cPos;
  for(int i=0;i<n;i++){
    int sum1 = 0, sum2 = 0;
    for(int j=0;j<n;j++){
      sum1 += b[i][j];
      sum2 += b[j][i];
    }
    if(sum1%2==1) rCnt++, rPos = i;
    if(sum2%2==1) cCnt++, cPos = i;
  }
  
  if(rCnt==0 && cCnt==0)
    cout << "OK" << endl;
  else if(rCnt==1 && cCnt==1)
    cout << "Change bit (" << rPos+1 << ',' << cPos+1 << ')' << endl;
  else
    cout << "Corrupt" << endl;
}

int main(){
  while(read()) work();
  return 0;
}
