#include<iostream>
using namespace std;
typedef long long integer;

void rec(integer nume1, integer deno1, integer nume2, integer deno2, int idx, string s){
  integer nexNume = nume1+nume2, nexDeno = deno1+deno2;
  if(idx==s.size()){
    cout << nexNume << '/' << nexDeno << endl;
    return;
  }
  if(s[idx]=='L')
    rec(nume1,deno1,nexNume,nexDeno,idx+1,s);
  else
    rec(nexNume,nexDeno,nume2,deno2,idx+1,s);
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    string s;
    cin >> s;
    rec(0,1,1,0,0,s);
  }
  return 0;
}
