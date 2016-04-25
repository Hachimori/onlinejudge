#include<iostream>
#include<set>
#include<string>
#define BUF 100000
using namespace std;

int nStr;
string str[BUF];

void read(){
  nStr = 0;
  
  while(true){
    if(getline(cin,str[nStr])==NULL) break;
    nStr++;
  }
}

void work(){
  set<string> S;
  string toPush;
  
  for(int i=0;i<nStr;i++){
    if(str[i].size()==0) continue;
    
    for(int j=0;j<str[i].size();j++)

      if(str[i][j]=='-'){
        if(j!=str[i].size()-1)
          toPush += '-';
      }
      else if(isalpha(str[i][j]))
        toPush += tolower(str[i][j]);
      else {
        if(toPush.size()>0) S.insert(toPush);
        toPush = "";
      }
    
    if(toPush.size()>0 && str[i][str[i].size()-1]!='-'){
      S.insert(toPush);
      toPush = "";
    }
  }

  for(set<string>::iterator i=S.begin();i!=S.end();i++)
    cout << *i << endl;
}

int main(){
  read();
  work();
  return 0;
}
