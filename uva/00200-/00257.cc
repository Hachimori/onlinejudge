#include<iostream>
using namespace std;

string s;

bool read(){
  return cin >> s;
}

void work(){
  string found = "";
  for(int len=3;len<=min((int)s.size(),4);len++){
    for(int pos=0;pos+len<=s.size();pos++){
      if(found.find(s.substr(pos,len))!=string::npos) continue;
      bool ok = true;
      for(int i=0;i<len/2;i++)
        ok &= s[pos+i]==s[pos+len-i-1];

      if(ok){
        if(!found.empty() && s.substr(pos,len).find(found)==string::npos){
          cout << s << endl;
          return;
        }
        if(found.empty()) found = s.substr(pos,len);
      }
    }
  }
}

int main(){
  while(read()) work();
  return 0;
}
