#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<sstream>
#define LINE 205
using namespace std;

class Data{
public:
  string str;
  int lineId, wordId;

  Data(){}
  Data(string s, int l, int w): str(s), lineId(l), wordId(w){}

  bool operator< (const Data &d) const {
    if(str!=d.str) return str<d.str;
    if(lineId!=d.lineId) return lineId<d.lineId;
    return wordId<d.wordId;
  }
};

int nLine;
set<string> ignore;
vector<string> line[LINE];

string toup(string &s){
  string ret;
  for(int i=0;i<s.size();i++) ret += toupper(s[i]);
  return ret;
}

string tolow(string &s){
  string ret;
  for(int i=0;i<s.size();i++) ret += tolower(s[i]);
  return ret;
}

void read(){
  while(true){
    string s;
    getline(cin,s);
    if(s=="::") break;
    ignore.insert(s);
  }
  
  nLine = 0;
  while(true){
    string s; if(getline(cin,s)==NULL) break;

    stringstream in(s);
    while(in>>s) line[nLine].push_back(tolow(s));
    nLine++;
  }
}

void work(){
  vector<Data> ans;

  for(int i=0;i<nLine;i++)
    for(int j=0;j<line[i].size();j++)
      if(!ignore.count(line[i][j]))
        ans.push_back(Data(line[i][j],i,j));

  sort(ans.begin(),ans.end());

  for(int i=0;i<ans.size();i++){
    Data &p = ans[i];
    for(int j=0;j<line[p.lineId].size();j++){
      if(j) cout << ' ';
      if(j==p.wordId)
        cout << toup(line[p.lineId][j]);
      else
        cout << line[p.lineId][j];
    }cout << endl;
  }
}

int main(){
  read();
  work();
  
  return 0;
}
