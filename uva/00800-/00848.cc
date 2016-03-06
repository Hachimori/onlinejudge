#include<iostream>
using namespace std;
const int BUF = 10000;

int main(){
  int nLine = 0;
  string lines[BUF];
  while(getline(cin,lines[nLine])) nLine++;

  string toPrint;
  for(int i=0;i<nLine;i++){
    string s = lines[i];
    if(s.empty()){ cout << endl; continue; }
    for(int sIdx=0;sIdx<s.size();){
      string space, letters;
      while(sIdx<s.size() && s[sIdx]==' ') space += s[sIdx++];
      while(sIdx<s.size() && s[sIdx]!=' ') letters += s[sIdx++];

      if(toPrint.size()+space.size()+letters.size()<=72)
        toPrint += space+letters;
      else{
        while(toPrint[toPrint.size()-1]==' ') toPrint.erase(toPrint.size()-1);
        cout << toPrint << endl;
        toPrint = letters;
      }
    }
    if(i+1<nLine && !(lines[i+1].empty() || lines[i+1][0]==' ') && toPrint.size()+1<=72){
      toPrint += ' ';
    }
    else{
      while(toPrint[toPrint.size()-1]==' ') toPrint.erase(toPrint.size()-1);
      cout << toPrint << endl;
      toPrint = "";
    }
  }
  return 0;
}
