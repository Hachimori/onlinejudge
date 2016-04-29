#include<iostream>
#include<cctype>
#include<cassert>
using namespace std;
const int BUF = 105;

int nFib, fib[BUF];
string toMove;

void read(){
  cin >> nFib;
  for(int i=0;i<nFib;i++) cin >> fib[i];
  getline(cin,toMove);
  getline(cin,toMove);
}

int fib2idx(int n){
  if(n==1) return 0;
  if(n==2) return 1;
  int dp[BUF];
  dp[0] = 1;
  dp[1] = 2;
  for(int i=2;;i++){
    dp[i] = dp[i-1]+dp[i-2];
    if(dp[i]==n) return i;
  }
}

void work(){
  string ans = string(BUF,' ');
  for(int i=0,cur=0;i<toMove.size() && cur<nFib;i++){
    if(!isupper(toMove[i])) continue;
    ans[fib2idx(fib[cur++])] = toMove[i];
  }
  
  for(int i=ans.size()-1;;i--)
    if(ans[i]!=' '){
      cout << ans.substr(0,i+1) << endl;
      break;
    }
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
