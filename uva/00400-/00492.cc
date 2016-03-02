#include<iostream>
#include<cctype>
using namespace std;


string s;

bool read(){
  return getline(cin,s);
}


bool vowel(char a){
  string vow = "aiueo";
  return vow.find(tolower(a))!=string::npos;
}


void work(){
  for(int i=0;i<s.size();){
    if(isalpha(s[i])){
      string word;
      while(i<s.size() && isalpha(s[i])) word += s[i++];

      if(vowel(word[0]))
        cout << word << "ay";
      else
        cout << word.substr(1) << word[0] << "ay";
    }
    else{
      cout << s[i++];
    }
  }
  cout << endl;
}


int main(){
  while(read()) work();
  return 0;
}
