#include<iostream>
#include<algorithm>
using namespace std;
const int BUF = 1000005;

int dp[BUF];
void makeTable(){
  dp[1] = 0;
  for(int i=2;i<BUF;i++)
    dp[i] = (dp[i-1]+15)%i;
}

int L, R;

bool read(){
  cin >> L >> R;
  return !(L==0 && R==0);
}

void work(){
  if(L>R) swap(L,R);
  bool isLast[BUF]={false};
  for(int i=L;i<=R;i++){
    isLast[dp[i]] = true;
    if(dp[i]!=0) isLast[i-dp[i]] = true;
  }

  for(int i=1;i<=L/2;i++)
    if(!isLast[i]){
      cout << i << endl;
      return;
    }
  cout << "Better estimate needed" << endl;
}

int main(){
  makeTable();
  while(read()) work();
  return 0;
}
