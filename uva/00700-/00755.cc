#include<iostream>
#include<map>
#include<cctype>
using namespace std;
const int STR = 100005;

int nStr;
string str[STR];

void read(){
  cin >> nStr;
  for(int i=0;i<nStr;i++)
    cin >> str[i];
}

void work(){
  string letter="ABCDEFGHIJKLMNOPRSTUVWXY";
  map<string,int> M;
  for(int i=0;i<nStr;i++){
    string toPush;
    for(int j=0;j<str[i].size();j++){
      char ch = str[i][j];
      if(letter.find(ch)!=string::npos)
        toPush += letter.find(ch)/3+'2';
      else if(isdigit(ch))
        toPush += ch;
    }
    M[toPush]++;
  }

  int cntAns = 0;
  for(map<string,int>::iterator i=M.begin();i!=M.end();i++)
    if(i->second>1){
      cout << i->first.substr(0,3) << '-' << i->first.substr(3) << ' ' << i->second << endl;
      cntAns++;
    }
  if(cntAns==0)
    cout << "No duplicates." << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
