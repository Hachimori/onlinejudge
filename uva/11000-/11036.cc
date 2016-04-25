#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cctype>
#define BUF 11000005
#define ADD -1
#define MUL -2
#define VAR -3 
using namespace std;
typedef long long ll;

int mod, init;
vector<int> ope;

bool read(){
  cin >> mod;
  if(mod==0) return false;
  cin >> init;
  
  ope.clear();
  
  while(true){
    string s;
    cin >> s;
    if(s=="N") continue;
    if(s=="%") break;
    
    if(s=="+") ope.push_back(ADD);
    if(s=="*") ope.push_back(MUL);
    if(s=="x") ope.push_back(VAR);
    if(isdigit(s[0])) ope.push_back(atoi(s.c_str()));
  }
  
  return true;
}

void work(){
  map<int,int> visited;
  int cur = init;
  
  visited[init] = 0;
  
  while(true){
    stack<int> S;
    
    for(int i=0;i<ope.size();i++){
      ll a, b;
      switch(ope[i]){
      case ADD:
	a = S.top(); S.pop();
	b = S.top(); S.pop();
	S.push((a+b)%mod);
	break;
      case MUL:
	a = S.top(); S.pop();
	b = S.top(); S.pop();
	S.push((a*b)%mod);
	break;
      case VAR:
	S.push(cur%mod);
	break;
      default:
	S.push(ope[i]%mod);
	break;
      }
    }

    if(visited.count(S.top())){
      cout << visited[cur]-visited[S.top()]+1 << endl;
      break;
    }
    else{
      visited[S.top()] = visited[cur]+1;
      cur = S.top();
    }
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}
