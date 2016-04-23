#include<iostream>
#include<string>
#include<cctype>
using namespace std;

string str;

bool read(){
  getline(cin,str);
  if(str=="DONE") return false;
  
  string next;
  for(int i=0;i<str.size();i++)
    if(isalpha(str[i]))
      next += toupper(str[i]);
  
  str = next;
  
  return true;
}

void work(){
  for(int i=0;i<str.size()/2;i++)
    if(str[i]!=str[str.size()-i-1]){
      cout << "Uh oh.." << endl;
      return;
    }
  cout << "You won't be eaten!" << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
