#include<iostream>
#include<string>
#include<set>
#include<cctype>
#include<sstream>
using namespace std;

int main(){
  set<string> S;
  string str;
  while(getline(cin,str)){
    for(int i=0;i<str.size();i++) 
      if(!isalpha(str[i])) 
        str[i] = ' ';
      else
        str[i] = tolower(str[i]);
    stringstream in(str);
    while(in >> str) S.insert(str);
  }

  for(set<string>::iterator it=S.begin();it!=S.end();it++)
    cout << *it << endl;

  return 0;
}
