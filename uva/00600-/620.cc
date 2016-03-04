#include<iostream>
using namespace std;

bool isValid(string s){
  if(s.size()%2==0) return false;
  while(s.size()>1){
    if(s[0]=='B' && s[s.size()-1]=='A')
      s = s.substr(1,s.size()-2);
    else if(s[s.size()-2]=='A' && s[s.size()-1]=='B')
      s = s.substr(0,s.size()-2);
    else
      return false;
  }
  return s[0]=='A';
}

int main(){
  int cases;
  cin >> cases;
  for(int kk=0;kk<cases;kk++){
    string s;
    cin >> s;
    if(!isValid(s))
      cout << "MUTANT" << endl;
    else if(s.size()==1)
      cout << "SIMPLE" << endl;
    else if(s[0]=='B' && s[s.size()-1]=='A')
      cout << "MUTAGENIC" << endl;
    else
      cout << "FULLY-GROWN" << endl;
  }
  return 0;
}
