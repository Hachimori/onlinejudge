// n! �ɂ����āA����0�̂����͖�蕶�ŗ^����ꂽ�Ƃ���A
// f(n,p) = floor(n/p) + floor(n/(p^2)) + floor(n/(p^3)) + ...
// �ł���B
//
// 1! 2! 3! 4! 5! .... (n-1)! n!
// ������A�ȉ��̂悤�ɕ\���B
// 1! 2! 3! .. (p-1)! p! (p+1)! ... (2*p-1)! (2*p)! (2*p+1)! ...
//
// 
// ������A ��f(k,p)�͈ȉ��̂悤�ɂȂ�B
// 0 + 0 + 0 + ... + 0 + 1 + 1 + .... + 1 + 2 + 2 + ... + 2 + 3 + 3 + ....
//
// ���̑��a�����߂�B
//
//
// �܂��A���̐��� num/p �ƂȂ�B���̐���nSeq�Ƃ����B
//
// ������������̂́A���̏ꏊ��p�Ŋ���؂��Ƃ���B
// ���� (p*p)! �̂Ƃ��͐�����2�����邱�Ƃɒ��ӁB
//
// 
// ��f(k,p) �̂����Afloor(k/p)�̑��a�����߂�B
// (n+1-p) + (n+1-2*p) + (n+1-3*p) + ...
//
// (n+1-p)�Ƃ����̂�p�Ԗڂ̍����琔����1������̂ŁA
// p�ԖڈȑO�̍����l�����Ȃ��A�Ƃ������ƁB
// 
// ����𐔎��Ƃ݂Ď��ɕ\���ƁA�ȉ��̂悤�ɂȂ�B
// nSeq*(n+1) - p*nSeq*(nSeq+1)/2 
// 
// - p*nSeq*(nSeq+1)/2 �̕����́A����-p,����-p�̓���������B
// 
//
// ��f(k,p) �̂����Afloor(k/(p^2))�̑��a�����߂�B
// (n+1-p^2) + (n+1-2*p^2) + (n+1-3*p^2) + ...
// 
// ���ꐔ���͏�Ɠ����B
//
// 
// �����p�̗ݏ悪num�𒴂���܂ŌJ��Ԃ��B
// 
// �Ȃ��Ap��base�������ԑ傫�������B

#include<iostream>
using namespace std;
typedef long long ll;

ll num, base;

bool read(){
  cin >> num >> base;
  return !(num==0 && base==0);
}

int getPrime(){
  int cur = base, ret;
  for(int i=2;i*i<=cur;i++)
    if(cur%i==0){
      while(cur%i==0) cur/=i;
      ret = i;
    }
  
  return (cur==1 ? ret : cur);
}

void work(){
  int p = getPrime();
  ll ans = 0;

  for(ll pp=getPrime();pp<=num;pp*=p){
    ll nSeq = num/pp;
    ans += nSeq*(num+1)-pp*nSeq*(nSeq+1)/2;
  }
  
  cout << ans << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
