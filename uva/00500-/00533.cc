#include<iostream>
#include<string>
#include<utility>
#include<cctype>
#include<cstdio>
#define x first
#define y second
using namespace std;
typedef pair<int,int> Val;  // x's coefficient, non coefficient

Val expr(int &n);
Val term(int &n);
Val fact(int &n);

string str;

Val fact(int &p){
  Val val = Val(0,0);

  if(isdigit(str[p])){
    while(isdigit(str[p])) val.y = val.y*10+str[p++]-'0';
  }
  else if(str[p]=='x'){
    p++;
    val.x++;
  }
  else {
    p++;
    val = expr(p);
    p++;
  }
  
  return val;
}

Val term(int &p){
  Val val = fact(p);

  while(str[p]=='*'){
    Val ret = fact(++p);
    val.x = val.x*ret.y + val.y*ret.x;
    val.y = val.y*ret.y;
  }

  return val;
}

Val expr(int &p){
  Val val = term(p);

  while(str[p]=='+' || str[p]=='-'){
    Val ret;
    if(str[p]=='+'){
      ret = term(++p);
      val.x += ret.x;
      val.y += ret.y;
    }
    else{
      ret = term(++p);
      val.x -= ret.x;
      val.y -= ret.y;
    }
  }
  
  return val;
}

int main(){
  string buf;
  for(int caze=0;getline(cin,str);caze++){
    str += '\0';
    if(caze) cout << endl;
    
    cout << "Equation #" << caze+1 << endl;

    int p = 0;
    Val val1 = expr(p);
    p++;  // '=';
    Val val2 = expr(p);
    
    int coeff = val1.x-val2.x;
    int noncoeff = val2.y-val1.y;
    
    if(noncoeff==0 && coeff==0)
      cout << "Infinitely many solutions." << endl;
    else if(noncoeff!=0 && coeff==0)
      cout << "No solution." << endl;
    else
      printf("x = %.6lf\n",1.0*noncoeff/coeff);
  }
  
  return 0;
}
