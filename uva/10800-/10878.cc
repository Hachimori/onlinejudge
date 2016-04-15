#include<iostream>
using namespace std;
const int LINE = 100000;

int nLine;
string line[LINE];

void read(){
  string dummy; getline(cin,dummy);
  nLine = 0;
  while(1){
    getline(cin,line[nLine]);
    if(line[nLine]=="___________") break;
    line[nLine].erase(line[nLine].begin()+6);
    nLine++;
  }
}


void work(){
  for(int i=0;i<nLine;i++){
    char mask = 0;
    for(int j=0;j<line[i].size();j++)
      if(line[i][line[i].size()-j-1]=='o')
        mask |= 1<<(j-1);
    cout << mask;
  }
}


int main(){
  read();
  work();
  return 0;
}
