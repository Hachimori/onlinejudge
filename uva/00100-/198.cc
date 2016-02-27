#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cctype>
#define BUF 10000
using namespace std;
typedef vector<string> VS;

int expr(int &, VS &);
int term(int &, VS &);
int fact(int &, VS &);

bool visited[BUF], valid;
VS def[BUF];
map<string,int> n2id;

int fact(int &p, VS &vs){
  int v;
  
  if(vs[p]=="("){
    p++;
    v = expr(p,vs);
    p++;
  }
  else if(vs[p]=="-" || isdigit(vs[p][0])){
    if(vs[p]=="-"){
      p++;
      vs[p] = '-'+vs[p];
    }
    v = atoi(vs[p++].c_str());
  }
  else if(n2id.count(vs[p])){
    int opp = n2id[vs[p++]];

    if(visited[opp])
      valid = false;
    else{
      visited[opp] = true;
      int nexp = 0;
      v = expr(nexp,def[opp]);
      visited[opp] = false;
    }
  }
  else{
    p++;
    valid = false;
  }
  return v;
}

int term(int &p, VS &vs){
  int v = fact(p,vs);

  while(vs[p]=="*")
    v *= fact(++p,vs);
  
  return v;
}

int expr(int &p, VS &vs){
  int v = term(p,vs);
  
  while(vs[p]=="+" || vs[p]=="-")
    if(vs[p]=="+")
      v += term(++p,vs);
    else 
      v -= term(++p,vs);
  
  return v;
}

VS split(string buf){
  string s;
  VS ret;

  for(int i=0;i<buf.size();i++)
    if(!isspace(buf[i]))
      s += buf[i];
  s += ' ';
  
  if(s.find(':')!=string::npos){
    ret.push_back(s.substr(0,s.find(':')));
    int cur = s.find(':')+2;
    
    while(cur<s.size()){
      string toPush;
      while(isalpha(s[cur]) || isdigit(s[cur])) toPush += s[cur++];

      if(!toPush.empty()) ret.push_back(toPush);
      
      ret.push_back(string(1,s[cur++]));
    }
  }
  else{
    stringstream in(buf);
    while(in>>buf) ret.push_back(buf);
    ret.push_back(" ");
  }
  
  return ret;
}

int main(){
  string str;
  
  while(getline(cin,str)){
    VS sList;
    sList = split(str);
    
    string fst = sList[0], scd = sList[1];

    if(fst=="PRINT")
      if(!n2id.count(scd))
        cout << "UNDEF" << endl;
      else{
        int p = 0;
        valid = true;
        fill(visited,visited+BUF,false);
        
        int ret = expr(p,def[n2id[scd]]);
        
        if(!valid)
          cout << "UNDEF" << endl;
        else
          cout << ret << endl;
      }
    else if(fst=="RESET")
      n2id.clear();
    else {
      if(!n2id.count(fst)){
        int sz = n2id.size();
        n2id[fst] = sz;
      }
      
      def[n2id[fst]] = VS(sList.begin()+1,sList.end());
    }
  }
  
  return 0;
}
