#include<iostream>
#include<vector>
#include<algorithm>
#define NODE 35
#define INF (1<<20)
using namespace std;

int nNode;
vector<int> adj[NODE];

bool read(){
  nNode = 0;
  for(int i=0;i<NODE;i++) adj[i].clear();
  
  int nEdge;
  if(!(cin >> nEdge)) return false;

  for(int i=0;i<nEdge;i++){
    int s, t;
    cin >> s >> t;
    
    adj[s].push_back(t);
    nNode = max(nNode,s+1);
    nNode = max(nNode,t+1);
  }
  
  return true;
}

bool isCycle(int curr, int init, bool visited[NODE]){
  visited[curr] = true;
  for(int i=0;i<adj[curr].size();i++){
    int next = adj[curr][i];
    if(next==init) return true;
    if(visited[next]) continue;
    if(isCycle(next,init,visited)) return true;
  }
  return false;
}

void setInf(int curr, int mat[NODE]){
  mat[curr] = -1;
  
  for(int i=0;i<adj[curr].size();i++){
    int next = adj[curr][i];
    if(mat[next]==-1) continue;
    setInf(next,mat);
  }
}

void dfs(int curr, int mat[NODE]){
  {
    bool visited[NODE];
    for(int i=0;i<nNode;i++)
      visited[i] = false;

    if(isCycle(curr,curr,visited)){
      setInf(curr,mat);
      return;
    }
  }
  mat[curr]++;

  for(int i=0;i<adj[curr].size();i++){
    int next = adj[curr][i];
    if(mat[next]==-1) continue;
    dfs(next,mat);
  }
}

void work(int cases){
  int mat[NODE][NODE];

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      mat[i][j] = 0;
  
  for(int i=0;i<nNode;i++){
    dfs(i,mat[i]);
    if(mat[i][i]!=-1) mat[i][i] = 0;
  }

  cout << "matrix for city " << cases << endl;
  for(int i=0;i<nNode;i++){
    for(int j=0;j<nNode;j++){
      if(j) cout << ' ';
      cout << mat[i][j];
    }
    cout << endl;
  }
}

int main(){
  for(int i=0;read();i++)
    work(i);
  
  return 0;
}
