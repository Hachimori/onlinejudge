// 10178  オイラーの公式
//
// R: 面の数 　V: 頂点の数　E: 辺の数  K: 連結成分の数
// R+V-E-K=1

#include<iostream>
#define NODE 60
using namespace std;

int nNode, nEdge, adj[NODE][NODE];

bool read(){
  int ch2id[256];
  
  for(int i=0;i<256;i++) 
    ch2id[i] = -1;
  for(int i=0;i<NODE;i++)
    for(int j=0;j<NODE;j++)
      adj[i][j] = 0;
  
  if(!(cin >> nNode >> nEdge)) return false;
  nNode = 0;
  
  for(int i=0;i<nEdge;i++){
    char s, t;
    cin >> s >> t;

    if(ch2id[s]==-1) ch2id[s] = nNode++;
    if(ch2id[t]==-1) ch2id[t] = nNode++;
    
    adj[ch2id[s]][ch2id[t]]++; 
    adj[ch2id[t]][ch2id[s]]++;
  }
  
  return true;
}

void dfs(int curr, bool visited[]){
  visited[curr] = true;
  for(int i=0;i<nNode;i++){
    if(!adj[curr][i] || visited[i]) continue;
    dfs(i,visited);
  }
}

void work(){
  int nSCC = 0;
  bool visited[NODE];
  
  for(int i=0;i<nNode;i++) visited[i] = false;

  for(int i=0;i<nNode;i++){
    if(visited[i]) continue;
    dfs(i,visited);
    nSCC++;
  }
  
  cout << 1-nNode+nEdge+nSCC << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
