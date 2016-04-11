#include<iostream>
#include<string>
using namespace std;

int base;
string s, mod;

bool read(){
  cin >> base >> s >> mod;
  return base!=0;
}

void work(){
  for(int i=0;i<s.size();i++) s[i] -= '0';
  
  long long modInt = strtol(mod.c_str(),NULL,base), divided = 0;
  for(int i=0;i<s.size();i++){
    divided = divided*base+s[i];
    divided %= modInt;
  }
  
  string ans;
  while(divided){
    ans = (char)(divided%base+'0')+ans;
    divided /= base;
  }
  cout << (ans.empty() ? "0" : ans) << endl;
}

int main(){
  while(read()) work();
  return 0;
}
