#include<iostream>
#include<sstream>
using namespace std;

string itoa(int n){
  stringstream out;
  out << n;
  return out.str();
}

int main(){
  string s;
  while(cin >> s,s!="0"){
    while(s.size()>=2){
      int sum = 0;
      for(int i=0;i<s.size();i++)
        sum += s[i]-'0';
      s = itoa(sum);
    }
    cout << s << endl;
  }
  return 0; 
}
