#include<iostream>
using namespace std;

string s;

bool read(){
  return cin >> s;
}


void work(){
  string ch = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
  string rv = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

  bool palin = true;
  for(int i=0;i<s.size();i++)
    palin &= s[i]==s[s.size()-1-i];
  
  bool mirror = true;
  for(int i=0;i<s.size();i++){
    int idx = ch.find(s[i]);
    mirror &= s[s.size()-1-i]==rv[idx];
  }

  if(mirror && palin)
    cout << s << " -- is a mirrored palindrome." << endl;
  else if(mirror)
    cout << s << " -- is a mirrored string." << endl;
  else if(palin)
    cout << s << " -- is a regular palindrome." << endl;
  else
    cout << s << " -- is not a palindrome." << endl;
  cout << endl;
}


int main(){
  while(read()) work();
  return 0;
}
