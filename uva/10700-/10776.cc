#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

void rec(string cur, int idx, int toAdd, string &s, set<string> &S){
  if(S.count(cur)) return;
  S.insert(cur);
  if(toAdd==0) return;
  for(int i=idx;i<s.size();i++)
    rec(cur+s[i],i+1,toAdd-1,s,S);
}

int main(){
  string s;
  int n;
  while(cin >> s >> n){
    set<string> S;
    sort(s.begin(),s.end());
    rec("",0,n,s,S);
    for(set<string>::iterator i=S.begin();i!=S.end();i++)
      if(i->size()==n)
        cout << *i << endl;
  }
  return 0;
}
