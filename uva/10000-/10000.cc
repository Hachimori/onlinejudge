#include<iostream>
#include<queue>

#define MAX_NODE 103

using namespace std;

int nNode;
int start;

bool adjList[MAX_NODE][MAX_NODE];

bool read(){

  cin >> nNode;
  if(nNode==0) return false;
  
  for(int i=1;i<=nNode;i++)
    for(int j=1;j<=nNode;j++)
      adjList[i][j] = false;


  cin >> start;

  while(true){

    int source, target;
    cin >> source >> target;
    if(source==0 && target==0) break;

    adjList[source][target] = true;
  }

  return true;
}

void bfs(int cases){

  queue<int> Q;
  int visited[MAX_NODE];

  for(int i=1;i<=nNode;i++)
    visited[i] = -1;

  visited[start] = 0;
  Q.push(start);

  while(!Q.empty()){
    
    int curr = Q.front();
    Q.pop();

    for(int i=1;i<=nNode;i++){
      if(!adjList[curr][i]) continue;

      if(visited[i]<visited[curr]+1){
	visited[i] = visited[curr]+1;
	Q.push(i);
      }
      else if(visited[i]==visited[curr]+1 && curr<i){
	visited[i] = visited[curr]+1;
	Q.push(i);	
      }
    }

  }

  int maxVal=-1, maxPos;
  for(int i=1;i<=nNode;i++)
    if(maxVal<visited[i] || (maxVal==visited[i] && maxPos>i) ){
      maxVal = visited[i];
      maxPos = i;
    }
  
  cout << "Case " << cases << ": The longest path from " << start 
       << " has length " << maxVal << ", finishing at " << maxPos << '.' << endl; 
  cout << endl;

}

void work(int cases){


  bfs(cases);

}

int main(){

  for(int cases=1;read();cases++)
    work(cases);

  return 0;
}
