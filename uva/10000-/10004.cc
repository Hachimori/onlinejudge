#include<iostream>

#define YET -1
#define BLACK 0
#define WHITE 1
#define MAX_NODE 205

using namespace std;

int nNode;
bool adjList[MAX_NODE][MAX_NODE];

bool read(){

  cin >> nNode;
  if(nNode==0) return false;

  int nEdge;
  cin >> nEdge;

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adjList[i][j] = false;

  for(int i=0;i<nEdge;i++){
    int source, target;
    cin >> source >> target;
    
    adjList[source][target] = true;
    adjList[target][source] = true;
  }

  return true;

}

bool dfs(int curr, int visited[MAX_NODE]){
  
  for(int i=0;i<nNode;i++){
    if(!adjList[curr][i]) continue;
    if(visited[i]!=YET && visited[curr]==visited[i]) return false;
    else if(visited[i]==BLACK || visited[i]==WHITE) continue;
    else {
      visited[i] = !visited[curr];
      if(!dfs(i,visited)) return false;
    }
  }

  return true;
}

bool check(int visited[MAX_NODE]){

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      if(adjList[i][j] && visited[i]==visited[j]) return false;
    
  
  return true;
}

void work(){

  int visited[MAX_NODE];

  for(int i=0;i<nNode;i++)
    visited[i] = YET;

  visited[0] = BLACK;

  if(!dfs(0,visited)){ 
    cout << "NOT BICOLORABLE." << endl;
    return;
  }
  else if(!check(visited)){
    cout << "NOT BICOLORABLE." << endl;
    return;
  }
  
  cout << "BICOLORABLE." << endl;

}

int main(){
  
  while(read())
    work();

  return 0;
}
