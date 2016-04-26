// DP
//
//
// E-transform �͐���̑S�Ă̗v�fAj��
// Aj-1 < Bj <= Aj ���� Bj%(Aj-1 - Aj)==0 �ƂȂ� Bj �ɕς��邱�Ƃł���B
//
// ���鐔��Eigensequence�ɂȂ邩�́A����̑S�Ă̗v�fAj��
// Aj-1 < Bj <= Aj ���� Bj%(Aj-1 - Aj)==0 ���� Bj==Aj �ƂȂ邩�ǂ����Ŕ���ł���B
//
// Aj-2�ȑO�̐��͍l������K�v���Ȃ����Ƃ��d�v�B
//
//
// tbl[n]�ɂ́A�n�߂�start,�I��肪n�ƂȂ��Ă���Eigensequence�̌���ۑ��B
// 
// tbl[n+i] (i: i%(n+i)==0�ƂȂ�i) �� tbl[n]�̈ꕔ�ł��邩��,
// tbl[n+i] += tbl[n]�Ƃ��Ă䂫�A�{�g���A�b�v�Ƀe�[�u�����\�z����B

#include<iostream>
#include<vector>

#define BUF 50

using namespace std;

int start, finish;

bool read(){
  cin >> start >> finish;
  if(start>=finish) return false;
  return true;
}

void work(){
  vector<int> tbl(BUF,0);
  tbl[start] = 1;
  
  for(int i=start;i<finish;i++)
    for(int j=i+1;j<=finish;j++)
      if(j%(j-i)==0)
	tbl[j] += tbl[i];
  
  cout << start << ' ' << finish << ' ' << tbl[finish] << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
