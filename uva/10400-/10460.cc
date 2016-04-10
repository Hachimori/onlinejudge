// ad-hoc
//
//
// ���ɂǂ��ɕ�����}�����邩�ɂ���āAindex�͈̔͂����߂邱�Ƃ��ł���B
//
// abcd �ɂ��čl����B
//   a ->  ba �Ƃ���ƁA�͈͂� 1-12�ƂȂ� �A
//   a ->  ab �Ƃ���ƁA�͈͂� 13-24�ƂȂ�A
//
//  ba -> cba �Ƃ���ƁA�͈͂� 1-4�ƂȂ�A
//  ba -> bca �Ƃ���ƁA�͈͂� 5-8�ƂȂ�A
//  ba -> bac �Ƃ���ƁA�͈͂� 9-12�ƂȂ�B
//
//
// index�͈͈̔͂ȉ��̒ʂ�B
//  !�ڕW�̕�����
//  -------------
//  !���݂̕�����
//
//
// ����́A������}������ꏊ�� (���݂̕�����+1) �ӏ�����A
// ������}��������́A(���݂̕�����+2) �ӏ�����A
// ���̎��́A(���݂̕�����+3) ����̂ŁA
// 
// (���݂̕�����+1)*(���݂̕�����+2)*(���݂̕�����+3)....
//
//   !�ڕW�̕�����
// = -------------
//   !���݂̕�����
//
// �ƂȂ邩��ł���A
//
//
// �܂��A������}������ꏊ�� (���݂̕�����+1) �ӏ�����̂ŁA
// ������}�����邻�ꂼ��̏ꏊi�ɑ΂���index�͈̔͂́A
//
// /        !�ڕW�̕�����*i�@�@�@�@�@�@�@�@�@     !�ڕW�̕�����*(i+1)�@�@     \
// |  --------------------------------  �`  --------------------------------  |
// \  !���݂̕����� * (���݂̕�����+1)�@�@  !���݂̕����� * (���݂̕�����+1)  /
//                                                                            
// �ł���B

#include<iostream>
#include<climits>
#include<string>

using namespace std;

int idx;
string str;

void read(){
  cin >> str >> idx ;
}

void rec(int currIdx, int nInserted, string currStr){
  if(str.size()-nInserted>=16){
    currStr = str[nInserted] + currStr;
    rec(currIdx,nInserted+1,currStr);
    return;
  }
  if(nInserted==str.size()){
    cout << currStr << endl;
    return;
  }
  
  long long section = 1;
  for(int i=currStr.size()+1;i<=str.size();i++)
    section *= i;
  section /= (currStr.size()+1);
  
  string::iterator j = currStr.begin();
  for(int i=1;i<=currStr.size()+1;i++,j++){
    if(idx<section*i+currIdx){
      currStr.insert(j,str[nInserted]);
      rec(currIdx+section*(i-1),nInserted+1,currStr);
      break;
    }
    
  }
  
}

void work(){
  string s;
  s += str[0];
  idx--;
  
  rec(0,1,s);
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
