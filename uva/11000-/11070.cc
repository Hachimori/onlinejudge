#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<cctype>
#include<cstdio>
using namespace std;

class Term{
public:
  char ope;
  double val;

  Term(){}
  Term(char o, double v): ope(o), val(v){}
};

vector<Term> term;

bool read(){
  string s;
  if(!(cin >> s)) return false;
  
  term.clear();
  
  for(int cur=0;cur<s.size();){
    string toPush;

    if(s[cur]=='+'||s[cur]=='-'||s[cur]=='*'||s[cur]=='/')
      term.push_back(Term(s[cur++],-1));
    else{
      while(cur<s.size() && (isdigit(s[cur]) || s[cur]=='.')) toPush+=s[cur++];
      term.push_back(Term(-1,atof(toPush.c_str())));
    }
  }
  
  return true;
}

void work(){
  while(true){
    bool finish = true;
    for(int i=0;i+1<term.size();i++)
      if(term[i].ope=='-' && term[i+1].ope==-1){
	term[i].ope = '+';
	term[i+1].val *= -1;
	finish = false;
	break;
      }
    if(finish) break;
  }

  while(true){
    bool finish = true;
    for(int i=1;i<term.size();i++){
      if(term[i].ope=='*'){
	term[i-1].val *= term[i+1].val;
	term.erase(term.begin()+i);
	term.erase(term.begin()+i);
	finish = false;
	break;
      }
      if(term[i].ope=='/'){
	term[i-1].val /= term[i+1].val;
	term.erase(term.begin()+i);
	term.erase(term.begin()+i);
	finish = false;
	break;
      }
    }
    if(finish) break;
  }

  while(true){
    bool finish = true;
    for(int i=1;i<term.size();i++){
      if(term[i].ope=='+'){
	term[i-1].val += term[i+1].val;
	term.erase(term.begin()+i);
	term.erase(term.begin()+i);
	finish = false;
	break;
      }
      if(term[i].ope=='-'){
	term[i-1].val -= term[i+1].val;
	term.erase(term.begin()+i);
	term.erase(term.begin()+i);
	finish = false;
	break;
      }
    }
    if(finish) break;
  }

  printf("%.3lf\n",(term[0].ope==-1 ? term[0].val : term[1].val));
}

int main(){
  while(read())
    work();
  
  return 0;
}
