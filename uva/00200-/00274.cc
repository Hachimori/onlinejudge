#include<iostream>
#include<string>
#include<sstream>
#define NODE 105
using namespace std;

int nNode, cInit, mInit;
bool ans1, ans2;
int adj[2][NODE][NODE];

void read(){
  cin >> nNode >> cInit >> mInit;
  cInit--, mInit--;
  
  for(int i=0;i<2;i++)
    for(int j=0;j<nNode;j++)
      for(int k=0;k<nNode;k++)
	adj[i][j][k] = false;
  
  while(true){
    int src, dst;
    cin >> src >> dst;

    if(src==-1 && dst==-1) break;
    src--, dst--;

    adj[0][src][dst] = true;
  }
  
  string s; getline(cin,s);
  while(getline(cin,s) && s.size()!=0){
    stringstream in(s);

    int src, dst;
    if(!(in >> src >> dst)) break;

    src--, dst--;
    adj[1][src][dst] = true;
  }
}

void dfs(int curr, int id, bool visited[][NODE]){
  visited[id][curr] = true;

  for(int i=0;i<nNode;i++){
    if(!adj[id][curr][i]) continue;
    if(i==mInit) ans2 = true;
    if(visited[!id][i]) ans1 = true;
    if(visited[id][i] || visited[!id][i])
      continue;

    dfs(i,id,visited);
  }
}

void work(){
  bool visited[2][NODE];
  
  for(int i=0;i<nNode;i++)
    adj[0][i][i] = adj[1][i][i] = false;
  
  for(int i=0;i<2;i++)
    for(int j=0;j<nNode;j++)
      visited[i][j] = false;

  dfs(cInit,0,visited);

  ans1 = ans2 = false;

  dfs(mInit,1,visited);
  if(visited[0][mInit]) ans1 = true, ans2 = false;
    
  cout << (ans1 ? 'Y' : 'N') << ' ' << (ans2 ? 'Y' : 'N') << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  
  return 0;
}
