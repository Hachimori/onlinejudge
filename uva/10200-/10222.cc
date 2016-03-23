#include<iostream>
using namespace std;

int main(){
  string from="ertyuiop[]dfghjkl;'cvbnm,.";
  string   to="qwertyuiopasdfghjklzxcvbnm";
  string s;
  getline(cin,s);
  for(int i=0;i<s.size();i++)
    if(s[i]!=' ')
      cout << to[from.find(tolower(s[i]))];
    else
      cout << ' ';
  cout << endl;
  return 0;
}
