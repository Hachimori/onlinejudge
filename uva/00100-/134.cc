#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cstdio>
#include<cctype>
#define SUCCEED 0
#define NONE 1
#define FAIL 2
using namespace std;

bool isPredStr(int &n);

vector<string> sList;
string get(int n){
  if(n<sList.size())
    return sList[n];
  else
    return "----";
}

bool read(){
  sList.clear();
  
  string buf;
  
  while(true){
    char ch = getchar();
    if(ch=='.') break;
    if(ch=='#') return false;
    buf += ch;
  }
  while(getchar()!='\n');
  
  stringstream in(buf);
  while(in>>buf) sList.push_back(buf);
  
  return true;
}

bool isVowel(char ch){
  string s="aiueo";
  return s.find(ch)!=string::npos;
}

bool isConsonant(char ch){
  return !isVowel(ch) && islower(ch);
}

bool isA(int &n){
  string s = get(n);
  if(s.size()==1 && isVowel(s[0])){
    n++;
    return true;
  }
  return false;
}

bool isMod(int &n){
  string s = get(n);
  if(s.size()==2 && s[0]=='g' && isVowel(s[1])){
    n++;
    return true;
  }
  return false;
}

bool isBa(int &n){
  string s = get(n);
  if(s.size()==2 && s[0]=='b' && isVowel(s[1])){
    n++;
    return true;
  }
  return false;
}

bool isDa(int &n){
  string s = get(n);
  if(s.size()==2 && s[0]=='d' && isVowel(s[1])){
    n++;
    return true;
  }
  return false;
}

bool isLa(int &n){
  string s = get(n);
  if(s.size()==2 && s[0]=='l' && isVowel(s[1])){
    n++;
    return true;
  }
  return false;
}

bool isNam(int &n){
  string s = get(n);
  if(isConsonant(s[s.size()-1])){
    n++;
    return true;
  }
  return false;
}

bool isPreda(int &n){
  string s = get(n);
  if(s.size()==5){
    if(!isConsonant(s[0]) || !isConsonant(s[3]) || !isVowel(s[4])) return false;
    
    bool ok = false;
    if(isConsonant(s[1]) && isVowel(s[2])) ok = true;
    if(isVowel(s[1]) && isConsonant(s[2])) ok = true;

    if(ok){
      n++;
      return true;
    }
  }
  return false;
}

int isPredName(int &n){
  if(isNam(n)) return SUCCEED;
  if(isLa(n)){
    if(isPredStr(n)) return SUCCEED;
    return FAIL;
  }
  return NONE;
}

int isVerbPred(int &n){
  return isMod(n) && isPredStr(n);
}

bool isPredStr(int &n){
  if(!isPreda(n)) return false;
  while(isPreda(n));
  return true;
}

bool isPreds(int &n){
  if(!isPredStr(n)) return false;
  while(true){
    if(!isA(n)) break;
    if(!isPredStr(n)) return false;
  }
  return true;
}

bool isPredClaim(int &n){
  if(isDa(n)){
    if(isPreds(n)) return true;
    return false;
  }
  
  return isPredName(n)==SUCCEED && isBa(n) && isPreds(n);
}

bool isState(int &n){
  if(isPredName(n)!=SUCCEED) return false;
  if(!isVerbPred(n)) return false;
  if(isPredName(n)==FAIL) return false;
  return true;
}

bool isSentence(int &n){
  if(isState(n)) return true;
  n = 0;
  return isPredClaim(n);
}

void work(){
  int n=0;
  if(isSentence(n) && n==sList.size())
    cout << "Good" << endl;
  else
    cout << "Bad!" << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
