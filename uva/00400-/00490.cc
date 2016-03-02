#include<iostream>
#include<string>
using namespace std;
const int BUF = 105;

int main(){
  int nStr = 0;
  string str[BUF];
  while(getline(cin,str[nStr])) nStr++;

  int maxLen = 0;
  for(int i=0;i<nStr;i++) 
    maxLen = max(maxLen,(int)str[i].size());

  for(int i=0;i<nStr;i++)
    if(str[i].size()<maxLen)
      str[i] += string(maxLen-str[i].size(),' ');
  
  for(int i=0;i<maxLen;i++){
    for(int j=nStr-1;j>=0;j--)
      cout << str[j][i];
    cout << endl;
  }

  return 0;
}
