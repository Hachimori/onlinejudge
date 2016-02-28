#include<iostream>
#include<string>
#include<cctype>
#include<sstream>
#include<cassert>
using namespace std;

class Parser{
public:
  string s, ope;
  int cur, val[256], pre[256];

  Parser(){}

  void init(){
    ope = "+-*/=";
    for(int i=0;i<256;i++) val[i] = pre[i] = 0;
  }

  void setStr(string _s){
    s = _s;
    cur = s.size()-1;
    for(int i=0;i<256;i++)
      pre[i] = val[i];
  }

  string fact(){
    if(s[cur]==')'){
      cur--; // ')';
      string ret = expr();
      cur--; // '(';
      return ret;
    }
    
    if(isalpha(s[cur]))
      return string(1,s[cur--]);
    
    if(isdigit(s[cur])){
      string ret;
      while(isdigit(s[cur])) ret = s[cur--]+ret;
      if(cur>=0 && s[cur]=='_'){ ret = "-"+ret; cur--; };
      return ret;
    }

    assert(false);
  }
  
  string expr(){
    string n = fact();

    while(cur>=0 && ope.find(s[cur])!=string::npos){
      char op = s[cur--];
      string m = fact();
      n = calc(n,op,m);
    }

    return n;
  }
  
  string calc(string a, char op, string b){
    int anum, bnum, ret;

    if(isalpha(a[0]))
      anum = val[a[0]];
    else
      anum = atoi(a.c_str());

    if(isalpha(b[0]))
      bnum = val[b[0]];
    else
      bnum = atoi(b.c_str());
    
    switch(op){
    case '=':
      ret = (val[b[0]] = anum);
      break;
    case '+':
      ret = bnum+anum;
      break;
    case '-':
      ret = bnum-anum;
      break;
    case '*':
      ret = bnum*anum;
      break;
    case '/':
      ret = bnum/anum;
      break;
    }

    stringstream out;
    out << ret;
    return out.str();
  }

  void print(){
    bool first = true;
    for(int i=0;i<256;i++)
      if(pre[i]!=val[i]){
        if(first) first = false;
        else cout << ", ";
        cout << (char)i << " = " << val[i];
      }

    if(first) cout << "No Change";
    cout << endl;
  }
};


int main(){
  Parser parser;
  parser.init();

  while(true){
    string tmp;
    getline(cin,tmp);
    if(tmp[0]=='#') break;

    string s;
    for(int i=0;i<tmp.size();i++)
      if(!isspace(tmp[i]))
        s += tmp[i];

    parser.setStr(s);
    parser.expr();
    parser.print();
  }
  
  return 0;
}
