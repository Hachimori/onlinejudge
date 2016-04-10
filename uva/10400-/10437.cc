#include<iostream>
#include<string>
#include<utility>
#include<cctype>
#define nume first
#define deno second
using namespace std;
typedef pair<int,int> Frac;

Frac expr(int &);
Frac term(int &);
Frac fact(int &);

string str;
bool isInvalid;

int gcd(int a, int b){
  return b==0 ? a : gcd(b,a%b);
}

Frac norm(Frac f){
  int div = gcd(abs(f.nume),abs(f.deno));
  if(f.deno<0){
    f.nume *= -1;
    f.deno *= -1;
  }
  return Frac(f.nume/div,f.deno/div);
}

Frac fact(int &p){
  Frac f(0,0);

  if(isdigit(str[p])){
    while(isdigit(str[p])) f.nume = f.nume*10+str[p++]-'0';
    
    if(str[p]=='|'){
      p++;
      while(isdigit(str[p])) f.deno = f.deno*10+str[p++]-'0';
      if(f.deno==0) isInvalid = true;
    }
    else
      f.deno = 1;
  }
  else {
    p++;
    f = expr(p);
    p++;
  }
  
  return norm(f);
}

Frac term(int &p){
  Frac f = fact(p);
  
  while(str[p]=='*' || str[p]=='/'){
    if(str[p]=='*'){
      Frac mul = fact(++p);
      f = Frac(f.nume*mul.nume,f.deno*mul.deno);
    }
    else{
      Frac div = fact(++p);
      if(div.nume==0) isInvalid = true;
      f = Frac(f.nume*div.deno,f.deno*div.nume);
    }
  }

  return norm(f);
}

Frac expr(int &p){
  Frac f = term(p);
  
  while(str[p]=='+' || str[p]=='-'){
    if(str[p]=='+'){
      Frac add = term(++p);
      f = Frac( f.deno*add.nume+f.nume*add.deno,f.deno*add.deno);
    }
    else{
      Frac sub = term(++p);
      f = Frac(-f.deno*sub.nume+f.nume*sub.deno,f.deno*sub.deno);
    }
  }
  
  return norm(f);
}

int main(){
  string buf;
  while(getline(cin,buf)){
    isInvalid = false;
    str = "";
    for(int i=0;i<buf.size();i++)
      if(!isspace(buf[i]))
        str += buf[i];
    str += '\0';
      
    int p = 0;
    Frac ret = expr(p);
    
    if(isInvalid)
      cout << "INVALID" << endl;
    else {
      if(ret.deno==1)
        cout << ret.nume << endl;
      else
        cout << ret.nume << '|' << ret.deno << endl;
    }
  }

  return 0;
}
