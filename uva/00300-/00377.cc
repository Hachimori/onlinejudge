#include<iostream>
using namespace std;
const int DIGIT = 1000;

string ope[3], A, B, goal;

void read(){
  cin >> A >> B;
  for(int i=0;i<3;i++) cin >> ope[i];
  cin >> goal;
}


int cnv(string s){
  int ret = 0;
  for(int i=0;i<s.size();i++){
    switch(s[i]){
      case 'V': ret = ret*4+0; break;
      case 'U': ret = ret*4+1; break;
      case 'C': ret = ret*4+2; break;
      case 'D': ret = ret*4+3; break;
    }
  }
  return ret;
}


void work(){
  int aVal = cnv(A), bVal = cnv(B);
  for(int i=0;i<3;i++){
    if(ope[i]=="A")
      bVal += aVal;
    else if(ope[i]=="L")
      bVal *= 4;
    else if(ope[i]=="R")
      bVal /= 4;
  }
  cout << (bVal==cnv(goal) ? "YES" : "NO") << endl;
}


int main(){
  cout << "COWCULATIONS OUTPUT" << endl;
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}
