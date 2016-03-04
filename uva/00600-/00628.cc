#include<iostream>
using namespace std;
const int BUF = 1005, TOPRINT = 100000;

int nWord, nRule;
string word[BUF], rule[BUF];

bool read(){
  if(!(cin >> nWord)) return false;
  for(int i=0;i<nWord;i++) cin >> word[i];
  cin >> nRule;
  for(int i=0;i<nRule;i++) cin >> rule[i];
  return true;
}

void rec(int ruleIdx, int passIdx, char toPrint[TOPRINT], string &curRule){
  if(ruleIdx==curRule.size()){
    for(int i=0;i<passIdx;i++)
      cout << toPrint[i];
    cout << endl;
    return;
  }
  if(curRule[ruleIdx]=='0')
    for(char i='0';i<='9';i++){
      toPrint[passIdx] = i;
      rec(ruleIdx+1,passIdx+1,toPrint,curRule);
    }
  else
    for(int i=0;i<nWord;i++){
      for(int j=0;j<word[i].size();j++)
        toPrint[passIdx+j] = word[i][j];
      rec(ruleIdx+1,passIdx+word[i].size(),toPrint,curRule);
    }
}

void work(){
  cout << "--" << endl;
  char toPrint[TOPRINT];
  for(int i=0;i<nRule;i++)
    rec(0,0,toPrint,rule[i]);
}

int main(){
  while(read()) work();
  return 0;
}
