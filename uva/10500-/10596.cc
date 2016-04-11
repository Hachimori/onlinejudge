#include<iostream>
#include<stack>

#define MAX_SIZE 205

using namespace std;

int nNode, nEdge;
int adjList[MAX_SIZE][MAX_SIZE];

bool read(){
  
  if(!(cin >> nNode >> nEdge)) return false;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adjList[i][j] = 0;
  
  for(int i=0;i<nEdge;i++){
    int src, dst;
    cin >> src >> dst;

    adjList[src][dst]++;
    adjList[dst][src]++;
  }
  
  return true;
}

void dfs(int curr, int &nVisited, bool visited[]){
  
  if(visited[curr]) return;
  visited[curr] = true;
  nVisited++;
  
  for(int i=0;i<nNode;i++){
    if(adjList[curr][i]==0) continue;
    
    dfs(i,nVisited,visited);
  }

}

void work(){
  int start=0;
  int nNeed=0;
  
  for(int i=0;i<nNode;i++){
    
    int sum=0;
    for(int j=0;j<nNode;j++) {
      sum += adjList[i][j];
    }
    
    if(sum%2==1){
      cout << "Not Possible" << endl;
      return;
    }

    if(sum>0){
      nNeed++;
      start=i;
    }
  }

  int nVisited = 0;
  bool visited[MAX_SIZE];
  
  for(int i=0;i<MAX_SIZE;i++)
    visited[i] = false;
  
  dfs(start,nVisited,visited);
  
  if(nVisited==nNeed) cout << "Possible" << endl;
  else 
    cout << "Not Possible" << endl;
}

int main(){
  
  while(read())
    work();

  return 0;
}
