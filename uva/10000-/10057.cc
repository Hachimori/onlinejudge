/*
  A = 0 の時の値は
             1*cnt[1] + 2*cnt[2] + 3*cnt[3] + ... + (n-1)*cnt[n-1] + n*cnt[n]
  となる。

  A = 1 の時の値は
  1*cnt[0]            + 1*cnt[2] + 2*cnt[3] + ... + (n-2)*cnt[n-1] + (n-1)*cnt[n]
  となる。

  これからわかることは、A以降のcnt[i]の係数が1減り、A以前のcnt[i]の係数が1増えている
  と言う事である。なので、cntの区間の和を最初に計算しておいて、値を計算する。
  
  n                            B
  Σcnt[i] を sum[n]とすると、Σcnt[i] は sum[j]-sum[i-1]である。
  i=0                         i=A
  
 */

#include<iostream>
#include<numeric>
#include<cstdio>
#include<cstdlib>
#define BUF 65537
#define INF (1LL<<60)
using namespace std;
typedef long long integer;

int nNum, cnt[BUF];

bool read(){
  if(scanf("%d",&nNum)==EOF) return false;

  for(int i=0;i<BUF;i++) cnt[i] = 0;
  
  for(int i=0;i<nNum;i++){
    int num; scanf("%d",&num);
    cnt[num]++;
  }
  
  return true;
}

void work(){
  int sum[BUF];
  
  sum[0] = cnt[0];
  for(int i=1;i<BUF;i++)
    sum[i] = cnt[i]+sum[i-1];
  
  
  integer minV, curV = 0;
  int minA = 0, cntA = cnt[0], diffA = 1;
    
  for(int i=0;i<BUF;i++) curV += (integer)i*cnt[i];
  minV = curV;
  
  for(int A=1;A<BUF;A++){
    curV += sum[A-1];
    curV -= (sum[BUF-1]-sum[A-1]);
    
    if(minV>curV){
      minV = curV;
      minA = A;
      cntA = cnt[A];
      diffA = 1;
    }
    else if(minV==curV){
      cntA += cnt[A];
      diffA++;
    }

  }

  cout << minA << ' ' << cntA << ' ' << diffA << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
