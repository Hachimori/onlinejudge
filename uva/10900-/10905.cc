// search+prune
//
//
// �u��������S�T���Ō��߂�B
// ���ڂ��Ă��鐔����u�������ʁA�ȑO����������Ԃ������
// ���Ƃ��킩������T����ł��؂�B
//
// rec�֐����Ŏg���Ă���terminal[n]�́An�̏ꏊ�������̌q���ڂ�
// �Ȃ��Ă��邩�ǂ���������킷�B�u���������ȑO�u���������ƈ�v���A
// ���u���I��������������̐����̌q���ڂƂȂ��Ă�����A�u���Ă�
// �Ӗ��͂Ȃ��B
//
// ���̂悤�ɂ��Ȃ��ƁA 9 9 9 9 9 9 9 .... �̃P�[�X��TLE.

#include<iostream>
#include<string>
#include<algorithm>
#define STR 55
#define BUF 10000
using namespace std;

int nStr;
string str[STR];

bool read(){
  cin >> nStr;
  if(nStr==0) return false;
  
  for(int i=0;i<nStr;i++)
    cin >> str[i];
  
  return true;
}

bool putAble(int idx, char ch[], int sId, bool terminal[]){
  for(int i=0;i<str[sId].size();i++){
    if(ch[idx+i]<str[sId][i]) return true;
    if(ch[idx+i]>str[sId][i]) return false;
  }
  return !terminal[idx+str[sId].size()];
}

void rec(int nChose, int idx, char ch[], bool used[], bool terminal[]){
  if(nChose==nStr) return;

  for(int i=0;i<nStr;i++){
    if(used[i]) continue;
    if(!putAble(idx,ch,i,terminal)) continue;
    used[i] = true;
    
    for(int j=0;j<str[i].size();j++){
      terminal[j+idx] = false;
      ch[j+idx] = str[i][j];
    }
    terminal[idx+str[i].size()] = true;
    
    rec(nChose+1,idx+str[i].size(),ch,used,terminal);
    
    used[i] = false;
  }
}

void work(){
  sort(str,str+nStr);
  reverse(str,str+nStr);
  
  char ch[BUF];
  bool used[STR], terminal[BUF];
  
  fill(used,used+nStr,false);
  fill(ch,ch+BUF,0);
  fill(terminal,terminal+BUF,false);
  
  rec(0,0,ch,used,terminal);
  
  for(int i=0;ch[i]!=0;i++)
    cout << ch[i];
  cout << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
