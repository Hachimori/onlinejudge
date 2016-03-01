#include<iostream>
using namespace std;

int idx;
string s;

void read(){
  cin >> s;
}


bool slump(){
  while(1){
    if(s[idx]!='D' && s[idx]!='E') return false;
    idx++;
    if(idx==s.size() || s[idx]!='F') return false;
    while(idx<s.size() && s[idx]=='F') idx++;
    if(idx!=s.size() && s[idx]=='G'){
      idx++;
      return true;
    }
    else if(idx!=s.size() && (s[idx]=='D' || s[idx]=='E'))
      continue;
    else
      return false;
  }
}


bool slimp(){
  if(s[idx]!='A') return false;
  idx++;
  if(s[idx]=='H'){
    idx++; 
    return true;
  }
  if(s[idx]=='B'){
    idx++;
    if(!slimp()) return false;
    if(s[idx]!='C') return false;
    idx++;
    return true;
  }
  if(!slump()) return false;
  if(s[idx]!='C') return false;
  idx++;
  return true;
}


bool slurpy(){
  return slimp() && slump();
}

void work(){
  idx = 0;
  if(slump() && idx==s.size()){
    cout << "YES" << endl;
    return;
  }
  idx = 0;
  if(slimp() && idx==s.size()){
    cout << "YES" << endl;
    return;
  }
  idx = 0;
  if(slurpy() && idx==s.size()){
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
}


int main(){
  cout << "SLURPYS OUTPUT" << endl;
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}
