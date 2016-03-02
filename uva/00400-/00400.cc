#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int ROW = 105, COL = 60;

int nStr;
string str[ROW];

bool read(){
  if(!(cin >> nStr)) return false;
  string dummy; getline(cin,dummy);
  for(int i=0;i<nStr;i++) getline(cin,str[i]);
  return true;
}


void work(){
  sort(str,str+nStr);

  int maxLen = 0;
  for(int i=0;i<nStr;i++) maxLen = max(maxLen,(int)str[i].size());
  maxLen = min(COL-2,maxLen);

  int col = COL/(maxLen+2), row = nStr/col+(nStr%col!=0);

  string b[ROW];
  for(int i=0;i<row;i++) b[i] = string(COL,' ');
  
  for(int i=0;i<nStr;i++)
    for(int r=i%row,c=i/row*(maxLen+2),j=0;j<str[i].size();c++,j++)
      b[r][c] = str[i][j];
  
  cout << string(COL,'-') << endl;
  for(int i=0;i<row;i++){
    int last = COL-1;
    while(b[i][last]==' ') last--;
    for(int j=0;j<=last;j++)
      cout << b[i][j];
    cout << endl;
  }
}


int main(){
  while(read()) work();
  return 0;
}
