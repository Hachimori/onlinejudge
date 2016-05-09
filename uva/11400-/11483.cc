#include<iostream>
using namespace std;
const int BUF = 105;

int nStr;
string sList[BUF];

bool read(){
  cin >> nStr;
  if(nStr==0) return false;
  string dummy;
  getline(cin,dummy);
  for(int i=0;i<nStr;i++) getline(cin,sList[i]);
  return true;
}

void work(int cases){
  cout << "Case " << cases << ":" << endl;
  cout << "#include<string.h>" << endl;
  cout << "#include<stdio.h>" << endl;
  cout << "int main()" << endl;
  cout << "{" << endl;

  for(int i=0;i<nStr;i++){
    cout << "printf(\"";
    for(int j=0;j<sList[i].size();j++)
      switch(sList[i][j]){
      case '\\':
        cout << "\\\\";
        break;
      case '\"':
        cout << "\\\"";
        break;
      default:
        cout << sList[i][j];
        break;
      }
    cout << "\\n\");" << endl;
  }
  cout << "printf(\"\\n\");" << endl;
  cout << "return 0;" << endl;
  cout << "}" << endl;
}

int main(){
  for(int i=0;read();i++) work(i+1);
  return 0;
}
