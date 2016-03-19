/*
  A = 0 �̎��̒l��
             1*cnt[1] + 2*cnt[2] + 3*cnt[3] + ... + (n-1)*cnt[n-1] + n*cnt[n]
  �ƂȂ�B

  A = 1 �̎��̒l��
  1*cnt[0]            + 1*cnt[2] + 2*cnt[3] + ... + (n-2)*cnt[n-1] + (n-1)*cnt[n]
  �ƂȂ�B

  ���ꂩ��킩�邱�Ƃ́AA�ȍ~��cnt[i]�̌W����1����AA�ȑO��cnt[i]�̌W����1�����Ă���
  �ƌ������ł���B�Ȃ̂ŁAcnt�̋�Ԃ̘a���ŏ��Ɍv�Z���Ă����āA�l���v�Z����B
  
  n                            B
  ��cnt[i] �� sum[n]�Ƃ���ƁA��cnt[i] �� sum[j]-sum[i-1]�ł���B
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
