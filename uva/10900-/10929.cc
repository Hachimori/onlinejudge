#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;
  while(cin>>s,s!="0"){
    int rem = 0;
    for(int i=0;i<s.size();i++){
      rem = rem*10+s[i]-'0';
      rem %= 11;
    }
    if(rem==0)
      cout << s << " is a multiple of 11." << endl;
    else
      cout << s << " is not a multiple of 11." << endl;
  }
  return 0;
}
