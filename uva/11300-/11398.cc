#include<iostream>
#include<cstdlib>
using namespace std;
const int BUF = 1000;

int nStr;
string str[BUF];

bool read(){
  nStr = 0;
  while(1){
    cin >> str[nStr];
    if(str[nStr]=="~") return false;
    if(str[nStr]=="#") break;
    nStr++;
  }
  return true;
}


void work(){
  char ch;
  string toCnv;
  for(int i=0;i<nStr;i++)
    if(str[i].size()<=2) ch = str[i].size()==1 ? '1' : '0';
    else
      toCnv += string(str[i].size()-2,ch);
  cout << strtol(toCnv.c_str(),NULL,2) << endl;
}

int main(){
  while(read()) work();
  return 0;
}
