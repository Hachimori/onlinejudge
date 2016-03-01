#include<iostream>
#include<cctype>
using namespace std;

string s;

bool read(){
  getline(cin,s);
  return s!="*";
}

bool valid(){
  int idx = 0;
  if(s[idx]=='+' || s[idx]=='-') idx++;
  if(!isdigit(s[idx])) return false;
  
  while(isdigit(s[idx])) idx++;
  
  bool isFrac = false;
  if(s[idx]=='.'){
    isFrac = true;
    idx++; 
    if(!isdigit(s[idx])) return false;
    while(isdigit(s[idx])) idx++;
    if(idx==s.size()-1) return true;
  }
  
  if(toupper(s[idx])=='E'){
    isFrac = true;
    idx++;
  }
  
  if(!isFrac) return false;
  
  if(s[idx]=='+' || s[idx]=='-') idx++;
  
  if(!isdigit(s[idx])) return false;
  while(isdigit(s[idx])) idx++;
  
  return idx==s.size()-1;
}

void work(){
  while(s.size()>0 && s[0]==' ') s = s.substr(1);
  while(s.size()>0 && s[s.size()-1]==' ') s = s.substr(0,s.size()-1);
  s += ' ';

  if(valid())
    cout << s << "is legal." << endl;
  else
    cout << s << "is illegal." << endl;
}

int main(){
  while(read()) work();
  return 0;
}
