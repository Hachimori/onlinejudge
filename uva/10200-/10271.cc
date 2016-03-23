// DP
//
//
// ��̃e�[�u����p�ӂ���B
//
// table[n][idx] �ɂ́A idx,idx+1 �̖_���g���A
//                       ����idx+2~nStick�̖_��n-1��g�����ŏ���badness��ۑ��B
//
// minVal[n][idx] �ɂ́A idx~nStick �܂ł̖_��n��g�����ŏ���badness��ۑ��B
//
//
// �e�[�u���̒l���X�V����ɂ́A
// table[n][idx] = (stick[idx]-stick[idx+1])^2 + minVal[n-1][idx+2];
// minVal[n][idx] = min(table[n][idx],minVal[n][idx+1]);
// �Ƃ���B 
//
// �e�[�u���̍X�V�� nStick-(i+1)*3 ����n�߂�̂́A
// �R�ڂɎg���_���\���Ɏc���Ă������߁B

#include<iostream>
#include<climits>
#include<algorithm>

#define MAX_PEOPLE 1015
#define MAX_STICK 5005

using namespace std;

int nPeople, nStick, stick[MAX_STICK];

void read(){
  cin >> nPeople >> nStick;

  nPeople += 8;

  for(int i=0;i<nStick;i++)
    cin >> stick[i];
}

void work(){
  // �����ł� table[idx]:      table[n-1][idx],
  //          nextTable[idx]:  table[n][idx]
  //          minVal[idx]:     minVal[n-1][idx],
  //          nextMinVal[idx]: minVal[n][idx]
  
  int table[MAX_STICK], minVal[MAX_STICK];
  int nextTable[MAX_STICK], nextMinVal[MAX_STICK];

  for(int i=0;i<nStick;i++) 
    minVal[i] = 0;
  
  for(int i=0;i<nPeople;i++){
    nextMinVal[nStick-(i+1)*3+1] = INT_MAX;
    for(int j=nStick-(i+1)*3;j>=0;j--){
      nextTable[j] = (stick[j]-stick[j+1])*(stick[j]-stick[j+1]) + minVal[j+2];
      nextMinVal[j] = min(nextTable[j],nextMinVal[j+1]);
    }
    
    for(int j=0;j<nStick;j++){
      table[j] = nextTable[j];
      minVal[j] = nextMinVal[j];
    }
  }

  cout << minVal[0] << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
