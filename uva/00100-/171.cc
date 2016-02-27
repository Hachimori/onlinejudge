#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cstdio>
#define STOP 0
#define SUCCESS 1
#define FAIL -1
#define BUF 10000
using namespace std;

int nStr;
string sList[BUF];

string get(int n){
  if(n<nStr)
    return sList[n];
  return "------";
}

bool isNnn(int &n){
  string s = get(n);
  for(int i=0;i<s.size();i++)
    if(!isdigit(s[i]))
      return false;
  n++;
  return true;
}

bool isCas(int &n){
  if(get(n)=="CHANGE" && get(n+1)=="AVERAGE" && get(n+2)=="SPEED"){
    n += 3;
    return true;
  }
  if(get(n)=="CAS"){
    n++;
    return true;
  }
  return false;
}

bool isChange(int &n){
  if(!isCas(n)) return false;
  
  if(get(n)=="TO") n++;
  else return false;
  
  if(!isNnn(n)) return false;
  
  if(get(n)=="KMH"){
    n++;
    return true;
  }
  return false;
}

bool isRecord(int &n){
  if(get(n)=="RECORD" && get(n+1)=="TIME"){
    n += 2;
    return true;
  }
  return false;
}

bool isTime(int &n){
  return isRecord(n) || isChange(n);
}

int isSignWord(int &n){
  string s = get(n);
  for(int i=0;i<s.size();i++)
    if(!('A'<=s[i] && s[i]<='Z') && s[i]!='.')
      return (s[i]=='"' ? STOP : FAIL);
  n++;
  return SUCCESS;
}

bool invalid(int n){
  string s = get(n);
  
  bool ok = false;
  for(int i=0;i<s.size();i++)
    if('A'<=s[i] && s[i]<='Z') ok=true;
  if(!ok) return true;
  
  int cnt = 0;
  for(int i=0;i<s.size();i++)
    if(s[i]=='\"') cnt++;
  if(cnt>1) return true;
  
  return s=="\"";
}

bool isSign(int &n){
  string s = get(n);
  if(s.size()>=3 && s[0]=='"' && s[s.size()-1]=='"'){
    for(int i=1;i<s.size()-1;i++)
      if(!('A'<=s[i] && s[i]<='Z') && s[i]!='.') 
	return false;
    n++;
    return true;
  }

  bool flg = false;
  flg |= invalid(n);
  if(s[0]=='"'){
    n++;
    while(true){
      flg |= invalid(n);
      if(isSignWord(n)!=SUCCESS) break;
    }
    if(isSignWord(n)==FAIL || flg) return false;
    s = get(n);
    if( s[s.size()-1]=='"'){
      n++;
      return true;
    }
    return false;
  }
  else
    return false;
}

int isWhere(int &n){
  if(get(n)=="AT"){
    n++;
    return (isSign(n) ? SUCCESS : FAIL);
  }
  return STOP;
}

bool isWhen(int &n){
  if(get(n)=="FIRST" || get(n)=="SECOND" || get(n)=="THIRD"){
    n++;
    return true;
  }
  return false;
}

bool isDirec(int &n){
  if(get(n)=="RIGHT" || get(n)=="LEFT"){
    n++;
    return true;
  }
  return false;
}

bool isHow(int &n){
  if(get(n)=="GO"){
    n++;
    isWhen(n);
    return true;
  }
  
  if(get(n)=="KEEP"){
    n++;
    return true;
  }
  
  return false;
}

bool isDir(int &n){
  if(!isHow(n)) return false;
  if(!isDirec(n)) return false;
  if(isWhere(n)==FAIL) return false;
  return true;
}

bool isNavi(int &n){
  if(!isDir(n)) return false;
  
  while(true){
    if(get(n)=="AND" && get(n+1)=="THEN"){
      n += 2;
      if(!isDir(n)) return false;
    }
    else
      break;
  }

  return true;
}

bool isInst(int &n){
  if(isNavi(n)){
    if(get(n)=="AND"){
      n++;
      return isTime(n);
    }
    return true;
  }
  return n==0 && isTime(n);
}

int main(){
  for(int caze=1;;caze++){
    nStr = 0;
    string buf; getline(cin,buf);
    if(buf=="#") break;
    
    stringstream in(buf);
    while(in>>sList[nStr++]);
    nStr--;

    int cur = 0;
    printf("%3d.",caze);
    if(isInst(cur) && cur==nStr)
      for(int i=0;i<nStr;i++)
	cout << ' ' << sList[i];
    else
      cout << " Trap!";
    cout << endl;
  }

  return 0;
}
