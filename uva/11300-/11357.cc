#include<iostream>
#include<vector>
using namespace std;

class Parser{
public:
  string s;
  int idx;
  void init(string _s){
    idx = 0;
    s = _s;
  }

  vector< pair<bool,char> > getClause(){
    vector< pair<bool,char> > ret;
    idx++; // '('
    while(s[idx]!=')')
      if(s[idx]=='&') 
        idx++;
      else if(s[idx]=='~'){
        ret.push_back(make_pair(false,s[idx+1]));
        idx += 2;
      }
      else
        ret.push_back(make_pair(true,s[idx++]));
    idx++; // ')'
    return ret;
  }

  vector< vector<pair<bool,char> > > parse(){
    vector< vector<pair<bool,char> > > ret;
    while(idx<s.size())
      if(s[idx]=='|') 
        idx++; //'|'
      else
        ret.push_back(getClause());
    return ret;
  }
};

bool isOk(vector<pair<bool,char> > ret){
  bool tbl[2][26]={};
  for(int j=0;j<ret.size();j++)
    tbl[ret[j].first][ret[j].second-'a'] = true;
  for(int j=0;j<26;j++)
    if(tbl[0][j] && tbl[1][j])
      return false;
  return true;
}

int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    Parser parser;
    string s;
    cin >> s;
    parser.init(s);
    vector< vector<pair<bool,char> > > ret = parser.parse();

    for(int i=0;i<ret.size();i++)
      if(isOk(ret[i])){
        cout << "YES" << endl;
        goto _success;
      }              
    cout << "NO" << endl;
  _success:;
  }
  return 0;
}
