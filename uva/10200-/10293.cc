#include<iostream>
using namespace std;
const int LETTER = 35;

string s;

bool read(){
  s = "";
  while(1){
    string toPush;
    if(!getline(cin,toPush)) return false;
    if(toPush.size() && toPush[0]=='#') break;
    if(toPush[toPush.size()-1]=='-')
      s += toPush;
    else
      s += toPush+' ';
  }
  return true;
}


void work(){
  int cnt[LETTER]={}, idx = 0;
  while(idx<s.size()){
    while(idx<s.size() && !isalpha(s[idx])) idx++;
    int len = 0;
    while(idx<s.size() && (isalpha(s[idx]) || s[idx]=='-' || s[idx]=='\'')){
      len += (isalpha(s[idx]) ? 1 : 0);
      idx++;
    }
    cnt[len]++;
  }
  
  for(int i=1;i<LETTER;i++)
    if(cnt[i])
      cout << i << ' ' << cnt[i] << endl;
  cout << endl;
}

int main(){
  while(read()) work();
  return 0;
}
