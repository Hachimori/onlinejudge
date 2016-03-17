#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
const int INF = 1<<30;

enum Ope{LPAREN=INF,RPAREN=INF+1,ADD=INF+2,MUL=INF+3};

int nPrint;
vector<int> ope;

bool read(){
  string s;
  if(!(cin >> s >> nPrint)) return false;
  ope.clear();
  for(int i=0;i<s.size();i++){
    string opeList = "[]+*";
    if(opeList.find(s[i])!=string::npos)
      ope.push_back(INF+opeList.find(s[i]));
    else {
      string toPush;
      while(i<s.size() && (s[i]=='-' || isdigit(s[i]))) toPush += s[i++];
      i--;
      ope.push_back(atoi(toPush.c_str()));
    }
  }
  return true;
}


vector<int> get(int L, int R){
  if(R-L==2) return vector<int>(nPrint,ope[L+1]);
  vector<int> ret, S = get(L+3,R-1);
  if(ope[L+2]==ADD){
    ret.push_back(ope[L+1]);
    for(int i=1;i<nPrint;i++)
      ret.push_back(ret[i-1]+S[i-1]);
  }
  else{
    ret.push_back(ope[L+1]*S[0]);
    for(int i=1;i<nPrint;i++)
      ret.push_back(ret[i-1]*S[i]);
  }
  return ret;
}


void work(){
  vector<int> ans = get(0,ope.size()-1);
  for(int i=0;i<nPrint;i++){
    if(i) cout << ' ';
    cout << ans[i];
  }cout << endl;
}


int main(){
  while(read()) work();
  return 0;
}
