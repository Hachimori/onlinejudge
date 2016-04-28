#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#define BUF 105
using namespace std;

int nLine;
vector<string> line[BUF];

void read(){
  for(int i=0;i<BUF;i++) line[i].clear();
  
  for(nLine=0;;nLine++){
    string s; getline(cin,s);
    if(s.empty()) break;

    stringstream in(s);
    while(in>>s) line[nLine].push_back(s);
  }
}

void work(int cases){
  cout << "Case #" << cases << ":" << endl;

  for(int i=0;i<nLine;i++){
    int letter = 0;
    for(int j=0;j<line[i].size();j++)
      if(letter<line[i][j].size())
        cout << line[i][j][letter++];
    cout << endl;
  }
}

int main(){
  int cases;
  cin >> cases;

  string dummy; getline(cin,dummy); getline(cin,dummy);

  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work(i+1);
  }
  
  return 0;
}
