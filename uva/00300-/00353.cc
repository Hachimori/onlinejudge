#include<iostream>
#include<string>
#include<set>

using namespace std;

string source;

bool read(){

  if(!(cin >> source)) return false;

  return true;
}

bool isParindrome(string str){
  
  for(int i=0,j=str.length()-1;i<str.length();i++,j--)
    if(str[i]!=str[j]) return false;
  
  return true;
}

void work(){
  
  set<string> S;

  for(int i=0;i<source.length();i++){
    for(int j=i;j<source.length();j++){
      
      string part = source.substr(i,j-i+1);
      
      if(isParindrome(part))
	S.insert(part);
      
    }
  }

  cout << "The string \'" << source << "\' contains " << S.size() 
       << " palindromes." << endl;


}

int main(){

  while(read())
    work();

  return 0;
}
