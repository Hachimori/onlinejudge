#include<iostream>
#include<string>
using namespace std;
const int RULE = 15;


int nRule;
pair<string,string> rule[RULE]; //(from,to)
string str;

bool read(){
  cin >> nRule;
  if(nRule==0) return false;
  string dummy; getline(cin,dummy);
  for(int i=0;i<nRule;i++){
    getline(cin,rule[i].first);
    getline(cin,rule[i].second);
  }
  getline(cin,str);
  return true;
}


void work(){
  for(int i=0;i<nRule;i++){
    while(str.find(rule[i].first)!=string::npos){
      int idx = str.find(rule[i].first);
      str.replace(idx,rule[i].first.size(),rule[i].second);
    }
  }
  cout << str << endl;
}


int main(){
  while(read()) work();
  return 0;
}
