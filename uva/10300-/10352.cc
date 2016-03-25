#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
const int BUF = 500000;

struct cmp{
  bool operator()(string a, string b) const {
    if(a.size()>=3) a[2] = 0;
    if(b.size()>=3) b[2] = 0;
    return a<b;
  }
};

int nStr;
string str[BUF];

bool read(){
  nStr = 0;
  while(1){
    if(!(cin >> str[nStr])) return false;
    if(str[nStr]=="#") break;
    nStr++;
  }
  return true;
}


void work(int cases){
  map<string,pair<string,int>,cmp > M;
  for(int i=0;i<nStr;i++){
    if(str[i].size()>5) str[i] = str[i].substr(0,5);
    if(M.count(str[i]))
      M[str[i]] = make_pair(str[i],M[str[i]].second+1);
    else
      M[str[i]] = make_pair(str[i],1);
  }

  cout << "Set #" << cases << ":" << endl;
  for(map<string,pair<string,int>,cmp >::iterator i=M.begin();i!=M.end();i++)
    cout << i->second.first << ' ' << i->second.second << endl;
  cout << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  return 0;
}
