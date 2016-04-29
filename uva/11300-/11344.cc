#include<iostream>
using namespace std;
const int DIV = 20;

bool canDivide(string s, int div){
  int rem = 0;
  for(int i=0;i<s.size();i++)
    rem = (rem*10+s[i]-'0')%div;
  return rem==0;
}

int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    string s;
    cin >> s;
    int nDiv, div[DIV];
    cin >> nDiv;
    for(int i=0;i<nDiv;i++) cin >> div[i];
    for(int i=0;i<nDiv;i++)
      if(!canDivide(s,div[i])){
        cout << s << " - Simple." << endl;
        goto _fail;
      }
    cout << s << " - Wonderful." << endl;
  _fail:;
  }
  return 0;
}
