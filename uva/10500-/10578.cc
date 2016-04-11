#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
typedef vector<int> State;

string s;
State init;

bool read(){
  if(!getline(cin,s)) return false;
  init = State(6);
  for(int i=0;i<s.size();i++) init[s[i]-'0'-1]++;
  return true;
}

map<State,bool> dp;

bool rec(State &st){
  if(dp.count(st)) return dp[st];
  
  int sum = 0;
  for(int i=0;i<st.size();i++)
    sum += (i+1)*st[i];
  if(sum>31) return dp[st] = true;

  for(int i=0;i<st.size();i++){
    if(st[i]==4) continue;
    State nex = st;
    nex[i]++;
    if(!rec(nex)) return dp[st] = true;
  }
  return dp[st] = false;
}

void work(){
  cout << s << ' ' << ((rec(init)^(s.size()%2))? 'A' : 'B') << endl;
}

int main(){
  while(read()) work();
  return 0;
}
