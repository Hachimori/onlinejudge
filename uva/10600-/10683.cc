#include<iostream>
#include<cstdio>
using namespace std;

int f(string s, int idx, int len){
  return atoi(s.substr(idx,len).c_str());
}

int main(){
  string s;
  while(cin >> s){
    int hh = f(s,0,2), mm = f(s,2,2), ss = f(s,4,2), cc = f(s,6,2);
    double rate = 1.0*(hh*60*60*100+mm*60*100+ss*100+cc)/(24*60*60*100);
    printf("%07d\n",(int)(rate*10000000+1e-6));
  }
  return 0;
}
