#include<iostream>
#include<string>
#include<sstream>
#include<map>
using namespace std;

int main(){
  map<string,string> t2s;
  string ss;
  while(getline(cin,ss),!ss.empty()){
    stringstream in(ss);
    string s,t;
    in >> s >> t;
    t2s[t] = s;
  }

  string t;
  while(cin >> t){
    if(t2s.count(t))
      cout << t2s[t] << endl;
    else
      cout << "eh" << endl;
  }
  return 0;
}
