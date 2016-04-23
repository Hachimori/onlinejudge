#include<iostream>
#include<string>
using namespace std;

string s;

bool read(){
  return cin >> s;
}

void work(){
  string sList[8] = {"ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
  for(int i=0;i<s.size();i++){
    for(int j=0;j<8;j++)
      if(sList[j].find(s[i])!=string::npos){
        cout << j+2;
        goto _found;
      }
    cout << s[i];
  _found:;
  }
  cout << endl;
}



int main(){
  while(read()) work();
  return 0;
}
