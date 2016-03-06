#include<iostream>
using namespace std;
const int BUF = 10000;

string from, to;
int nLine;
string lines[BUF];

void read(){
  getline(cin,from);
  getline(cin,to);
  nLine = 0;
  while(1){
    getline(cin,lines[nLine]);
    if(lines[nLine].empty()) break;
    nLine++;
  }
}

void work(){
  char from2to[128];
  memset(from2to,-1,sizeof(from2to));
  for(int i=0;i<from.size();i++)
    from2to[from[i]] = to[i];
  
  cout << to << endl;
  cout << from << endl;
  for(int i=0;i<nLine;i++){
    for(int j=0;j<lines[i].size();j++)
      cout << (from2to[lines[i][j]]==-1 ? lines[i][j] : from2to[lines[i][j]]);
    cout << endl;
  }
}

int main(){
  int cases;
  cin >> cases;
  string dummy;
  getline(cin,dummy); getline(cin,dummy);
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
