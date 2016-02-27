#include<iostream>
#include<string>
using namespace std;

string str;

bool read(){
  str = "";
  while(1){
    string s;
    if(getline(cin,s)==NULL) return false;
    str += ' '+s;
    if(s.substr(0,2)=="~~") break;
  }
  return true;
}

void work(){
  int ans = 0;
  string cntAndMove = "@^[(+-*/=";

  for(int k=0;k<str.size();k++){
    char ch = str[k];
    if(isalpha(ch) || ch=='_'){
      ans++;
      while(isalnum(str[k+1]) || str[k+1]=='_') k++;
    }
    else if(isdigit(ch)){
      ans++;
      while(isdigit(str[k+1])) k++;
      if(str[k+1]=='.' && isdigit(str[k+2])){
        k += 2;
        while(isdigit(str[k+1])) k++;
      }
      if(toupper(str[k+1])=='E'){
        if(str[k+2]=='-' || str[k+2]=='+') k++;
        k++;
      }
      while(isdigit(str[k+1])) k++;
    }
    else if(cntAndMove.find(ch)!=string::npos){
      ans++;
    }
    else if(ch=='$'){
      ans++;
      while(isdigit(str[k+1]) || ('A'<=toupper(str[k+1]) && toupper(str[k+1])<='F')) k++;
    }
    else if(ch=='<'){
      ans++;
      if(str[k+1]=='=' || str[k+1]=='>') k++;
    }
    else if(ch=='>'){
      ans++;
      if(str[k+1]=='=') k++;
    }
    else if(ch=='{'){
      while(str[k]!='}') k++;
    }
    else if(ch==':'){
      if(str[k+1]=='='){
        ans++;
        k++;
      }
    }
    else if(ch=='\''){
      ans++;
      while(1){
        while(str[k+1]!='\'') k++;
        if(str[k+2]=='\'') k+=2;
        else 
          break;
      }
      k++;
    }
    else if(ch=='~'){
      if(str[k+1]=='~'){
        cout << "Program by "+str.substr(k+2)+" contains " << ans << " units." << endl;
        break;
      }
    }
  }
}

int main(){
  while(read())
    work();
  return 0;
}
