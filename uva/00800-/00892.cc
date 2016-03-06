#include<iostream>
#include<string>
#include<cctype>
using namespace std;
const int LINE = 100;

int nLine;
string line[LINE];

void read(){
  nLine = 0;
  while(1){
    getline(cin,line[nLine]);
    if(line[nLine]=="#") break;
    nLine++;
  }
}

void work(){
  bool afterHyphen = false;
  string toPrint = "";
  for(int i=0;i<nLine;i++){
    for(int j=0;j<line[i].size();j++){
      if(isalpha(line[i][j]))
        toPrint += line[i][j];
      else if(line[i][j]==' '){
        if(afterHyphen){
          cout << endl << toPrint << endl << ' ';
          afterHyphen = false;
          toPrint = "";
        }
        else {
          cout << toPrint << ' ';
          toPrint = "";
        }
      }
      else if(line[i][j]=='-' && j==line[i].size()-1)
        afterHyphen = true;
    }
    if(!afterHyphen){
      cout << toPrint << endl;
      toPrint = "";
    }
  }
}

int main(){
  read();
  work();
  return 0;
}
