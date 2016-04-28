#include<iostream>
#include<string>
#define BUF 105
using namespace std;

string str;

void read(){
  str = "";
  
  string toPush;
  getline(cin,toPush);

  for(int i=0;i<toPush.size();i++)
    if(isalpha(toPush[i]))
      str += toPush[i];
}

bool valid(int sz){
  char ch[BUF][BUF];
  
  for(int i=0,cur=0;i<sz;i++)
    for(int j=0;j<sz;j++)
      ch[i][j] = str[cur++];

  for(int i=0;i<sz;i++)
    for(int j=0;j<sz;j++){
      if(ch[i][j]!=ch[j][i]) return false;
      if(ch[i][j]!=ch[sz-1-i][sz-1-j]) return false;
      if(ch[i][j]!=ch[sz-1-j][sz-1-i]) return false;
    }

  return true;
}

void work(int cases){
  int sz = 0;
  for(;;sz++)
    if(sz*sz>=str.size()) break;

  cout << "Case #" << cases << ":" << endl;

  if(sz*sz!=str.size() || !valid(sz))
    cout << "No magic :(" << endl;
  else
    cout << sz << endl;
}

int main(){
  int cases;
  cin >> cases;

  string dummy; getline(cin,dummy);
  
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  
  return 0;
}
