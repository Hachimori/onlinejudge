#include<iostream>
#include<string>

using namespace std;

string s;

bool read(){
  cin >> s;
  if(s=="0") return false;
  return true;
}

bool check(int &cur, int &state){
  char ch = s[cur];
  bool a, b;
  
  if(ch=='N'){
    cur++;
    return !check(cur,state);
  }
  else if(ch<5){
    cur++;
    return (state&(1<<ch));
  }
  else {
    cur++;
    bool a = check(cur,state);
    bool b = check(cur,state);
    
    if(ch=='K') return a && b;
    if(ch=='A') return a || b;
    if(ch=='C') return !(a && !b);
    if(ch=='E') return a == b;
  }
}

void work(){
  for(int i=0;i<s.size();i++){
    if(s[i]=='p') s[i] = 0;
    if(s[i]=='q') s[i] = 1;
    if(s[i]=='r') s[i] = 2;
    if(s[i]=='s') s[i] = 3;
    if(s[i]=='t') s[i] = 4;
  }
  
  for(int state=0;state<(1<<5);state++){
    int cur = 0;
    if(!check(cur,state)){
      cout << "not" << endl;
      return;
    }
  }
  cout << "tautology" << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
