#include<iostream>
using namespace std;
const int BUF = 1005;

int nNum, num[BUF];

bool read(){
  nNum = 0;
  while(1){
    cin >> num[nNum];
    if(num[nNum]==0) break;
    nNum++;
  }
  return nNum>0;
}

int gcd(int a, int b){
  return b==0 ? a : gcd(b,a%b);
}

void work(){
  sort(num,num+nNum);
  int ans = num[1]-num[0];
  for(int i=1;i+1<nNum;i++)
    ans = gcd(ans,num[i+1]-num[i]);
  cout << ans << endl;
}

int main(){
  while(read()) work();
  return 0;
}
