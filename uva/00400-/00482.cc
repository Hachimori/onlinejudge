#include<iostream>
#include<algorithm>
#include<sstream>
using namespace std;
const int BUF = 1000000;

int nVal;
pair<int,string> val[BUF];

void read(){
  string dummy; getline(cin,dummy);
  string str; 
  stringstream in;

  getline(cin,str);
  in.str(str);
  nVal = 0;
  while(in >> val[nVal].first) nVal++;

  getline(cin,str);
  in.clear();
  in.str(str);
  nVal = 0;
  while(in >> val[nVal].second) nVal++;
}


void work(){
  sort(val,val+nVal);
  for(int i=0;i<nVal;i++) cout << val[i].second << endl;
}


int main(){
  int cases;
  cin >> cases;
  string dummy; getline(cin,dummy);
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
