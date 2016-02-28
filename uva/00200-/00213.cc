#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

string str;
vector< pair<int,int> > ope;

bool read(){
  ope.clear();
  if(!getline(cin,str)) return false;
  while(1){
    string nBitStr;
    for(int i=0;i<3;i++){
      char ch;
      cin >> ch;
      nBitStr += ch;
    }
    int nBit = strtol(nBitStr.c_str(),NULL,2);
    if(nBit==0) break;
    while(1){
      string s;
      for(int i=0;i<nBit;i++){
        char ch;
        cin >> ch;
        s += ch;
      }
      if(s==string(nBit,'1')) break;
      ope.push_back(make_pair(nBit,strtol(s.c_str(),NULL,2)));
    }
  }
  string dummy; getline(cin,dummy);
  return true;
}


void work(){
  for(int i=0;i<ope.size();i++){
    int idx = 0;
    for(int j=0;j<ope[i].first;j++)
      idx += (1<<j)-1;
    cout << str[idx+ope[i].second];
  }cout << endl;
}


int main(){
  while(read()) work();
  return 0;
}
