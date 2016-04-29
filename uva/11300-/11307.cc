#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
const int BUF = 10005, COLOR = 20, INF = 1<<20;

int nNode, nIn[BUF];
vector<int> adj[BUF];

bool read(){
  for(int i=0;i<BUF;i++){ adj[i].clear(); nIn[i] = 0; }
  cin >> nNode;
  if(nNode==0) return false;
  string dummy; getline(cin,dummy);
  for(int i=0;i<nNode;i++){
    string s;
    getline(cin,s);
    stringstream in(s);
    int src, dst;
    char ch;
    in >> src >> ch;
    while(in >> dst){
      adj[src].push_back(dst);
      nIn[dst]++;
    }
  }
  return true;
}

int rec(int cur, int color, int dp[BUF][COLOR]){
  int &ret = dp[cur][color];
  if(ret!=-1) return ret;
  ret = 0;
  for(int i=0;i<adj[cur].size();i++){
    int minV = INF;
    for(int col=1;col<COLOR;col++)
      if(color!=col)
        minV = min(minV,rec(adj[cur][i],col,dp)+col);
    ret += minV;
  }
  return ret;
}

void work(){
  static int dp[BUF][20];
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<nNode;i++)
    if(nIn[i]==0){
      int minV = INF;
      for(int col=1;col<COLOR;col++)
        minV = min(minV,rec(i,col,dp)+col);
      cout << minV << endl;
    }
}

int main(){
  while(read()) work();
  return 0;
}
