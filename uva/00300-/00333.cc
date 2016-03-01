#include<iostream>
#include<cctype>
using namespace std;

string s;

bool read(){
  return getline(cin,s);
}

bool invalidChar(){
  string digits;
  for(int i=0;i<s.size();i++)
    if(isdigit(s[i]) || s[i]=='X') digits += s[i];
    else if(s[i]!='-' && s[i]!=' ') return true;
  for(int i=0;i<digits.size();i++)
    if(digits[i]=='X' && i!=9)
      return true;
  if(digits.size()!=10) return true;
  return false;
}

int calc(){
  string digits;
  for(int i=0;i<s.size();i++)
    if(isdigit(s[i]) || s[i]=='X') digits += s[i];

  int sum = 0;
  for(int i=0;i<digits.size();i++)
    sum += (10-i)*(digits[i]=='X' ? 10 : digits[i]-'0');
  return sum;
}

void work(){
  while(s.size()>=1 && s[0]==' ') s = s.substr(1);
  while(s.size()>=1 && s[s.size()-1]==' ') s = s.substr(0,s.size()-1);
  
  if(invalidChar() || calc()%11!=0)
    cout << s << " is incorrect." << endl;
  else
    cout << s << " is correct." << endl;
}

int main(){
  while(read()) work();
  return 0;
}
