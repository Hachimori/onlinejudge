#include<iostream>
#include<algorithm>
using namespace std;
const int STR = 2000;

int nStr;
string str[STR];

bool read(){
  nStr = 0;
  while(1){
    if(!(cin >> str[nStr])) return false;
    if(str[nStr]=="9") break;
    nStr++;
  }
  return true;
}

void work(int cases){
  cout << "Set " << cases << " is";
  sort(str,str+nStr);
  for(int i=0;i+1<nStr;i++)
    if(str[i]==str[i+1].substr(0,str[i].size())){
      cout << " not immediately decodable" << endl;
      return;
    }
  cout << " immediately decodable" << endl;
}

int main(){
  for(int i=0;read();i++) work(i+1);
  return 0;
}
