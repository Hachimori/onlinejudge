#include<iostream>
#include<algorithm>

#define MAX_SIZE 15

using namespace std;

int nNode, nVisit;
int adjList[MAX_SIZE][MAX_SIZE];

bool read(){

  if(!(cin >> nNode >> nVisit)) return false;

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      cin >> adjList[i][j];

  return true;

}

void dfs(int curr, int nVisited, int path[MAX_SIZE], bool visited[MAX_SIZE], bool &succeed){
  
  if(nVisited==nVisit+1){

    cout << "(";
    for(int i=0;i<nVisit+1;i++)
      if(i!=0) cout << ',' << path[i]+1;
      else cout << path[i]+1;
    cout << ")" << endl;
    
    succeed=true;

    return;
  }
  

  for(int i=0;i<nNode;i++){    
    if(adjList[curr][i]==0) continue;
    if(visited[i]) continue;
    
    visited[i] = true;
    path[nVisited] = i;

    dfs(i,nVisited+1,path,visited,succeed);

    visited[i] = false;
  }
  
}

void work(){
  
  bool visited[MAX_SIZE], succeed=false;
  int path[MAX_SIZE];
  
  fill(visited,visited+nNode,false);

  visited[0]=true;
  path[0] = 0;

  dfs(0,1,path,visited,succeed);
  
  if(!succeed) 
    cout << "no walk of length " << nVisit << endl;

}

int main(){

  for(int i=0;read();i++){
    if(i!=0) cout << endl;
      
    work();
    
    int dummy;
    cin >> dummy;
  }

  return 0;
}
