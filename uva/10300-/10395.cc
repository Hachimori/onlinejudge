#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void rec(string &s, int idx){
  if(idx<0){
    cout << s << endl;
    return;
  }
  rec(s,idx-1);
  
  if(idx&1)
    for(int i=0;i<idx;i++){
      swap(s[i],s[idx]);
      rec(s,idx-1);
    }
  else
    for(int i=0;i<idx;i++){
      swap(s[0],s[idx]);
      rec(s,idx-1);
    }
}

int main(){
  string s;
  while(cin >> s){
    rec(s,s.size()-1);
    cout << endl;
  }
  return 0;
}
