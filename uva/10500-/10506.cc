#include<iostream>
#include<string>
#define BUF (1<<16)
using namespace std;

int nTake, base;

bool read(){
  return cin >> nTake >> base;
}

bool rec(string &s, int limit, bool used[BUF]){
  if(s.size()==limit){
    for(int i=0;i<nTake-1;i++){
      int v = 0;
      for(int j=1-nTake;j<=0;j++){
        v *= base;
        v += s[(i+j+limit)%limit]-'0';
      }
      if(used[v]) return false;
    }
    cout << s << endl;
    return true;
  }

  int v = 0;
  for(int j=s.size()-nTake+1;j<s.size();j++){
    v += s[j]-'0';
    v *= base;
  }
  
  for(int toAdd=0;toAdd<base;toAdd++){
    if(!used[v+toAdd]){
      used[v+toAdd] = true;
      s += (char)(toAdd+'0');
      if(rec(s,limit,used)) return true;
      s.erase(s.size()-1,1);
      used[v+toAdd] = false;
    }
  }
  
  return false;
}

void work(){
  int limit = 1;
  for(int i=0;i<nTake;i++) limit *= base;
  
  string s = string(nTake,'0');
  bool used[BUF] = {false};
  used[0] = true;
  rec(s,limit,used);
}

int main(){
  while(read()) work();
  return 0;
}
