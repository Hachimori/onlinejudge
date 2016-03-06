#include<iostream>
#include<string>
using namespace std;
const int BUF = 105;

int nStr;
string str[BUF];

void read(){
  nStr = 0;
  while(getline(cin,str[nStr]) && !str[nStr].empty()) nStr++;
}

void work(){
  string origin = "the quick brown fox jumps over the lazy dog";
  for(int key=0;key<nStr;key++){
    if(origin.size()!=str[key].size()) continue;
    bool success = true;
    char ch2orig[128] = {0};
    for(int i=0;i<origin.size();i++){
      if((origin[i]==' ')^(str[key][i]==' ')) success = false;
      if(!ch2orig[str[key][i]])
        ch2orig[str[key][i]] = origin[i];
      else if(ch2orig[str[key][i]]!=origin[i])
        success = false;
    }
    if(success){
      for(int i=0;i<nStr;i++){
        for(int j=0;j<str[i].size();j++)
          cout << (str[i][j]==' ' ? ' ' : ch2orig[str[i][j]]);
        cout << endl;
      }
      return;
    }
  }
  cout << "No solution." << endl;
}

int main(){
  int cases;
  cin >> cases;
  string dummy; getline(cin,dummy); getline(cin,dummy);
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
