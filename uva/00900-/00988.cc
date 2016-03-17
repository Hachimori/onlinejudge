#include<iostream>
#include<vector>
using namespace std;
const int BUF = 15000;

int nNode;
vector<int> adj[BUF];

bool read(){
  for(int i=0;i<BUF;i++) adj[i].clear();
  if(!(cin >> nNode)) return false;
  for(int i=0;i<nNode;i++){
    int nEdge;
    cin >> nEdge;
    for(int j=0;j<nEdge;j++){
      int t;
      cin >> t;
      adj[i].push_back(t);
    }
  }
  return true;
}

int rec(int cur, int dp[BUF]){
  int &ret = dp[cur];
  if(adj[cur].empty()) return ret = 1;
  if(ret!=-1) return ret;
  ret = 0;
  for(int i=0;i<adj[cur].size();i++)
    ret += rec(adj[cur][i],dp);
  return ret;
}

void work(){
  int dp[BUF];
  memset(dp,-1,sizeof(dp));
  cout << rec(0,dp) << endl;
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  return 0;
}
