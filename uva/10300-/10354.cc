#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

#define MAX_SIZE 105

using namespace std;

int adjList[MAX_SIZE][MAX_SIZE];
int nNode, myStart, myGoal, bossStart, bossGoal;

bool read(){

  int nEdge;
  if(!(cin >> nNode >> nEdge >> bossStart >> bossGoal >> myStart >> myGoal))
    return false;


  for(int i=0;i<=nNode;i++)
    fill(adjList[i],adjList[i]+nNode+1,INT_MAX);
  
  
  for(int i=0;i<nEdge;i++){
    int source, target, cost;
    cin >> source >> target >> cost;

    adjList[source][target] = cost;
    adjList[target][source] = cost;
    
  }

  return true;
}

void colorPath(int curr, vector<int> &path, bool bossPassedEdge[MAX_SIZE][MAX_SIZE], vector<int> pi[MAX_SIZE], bool visited[MAX_SIZE]){
  
  visited[curr]=true;
  path.push_back(curr);

  for(int i=0;i<pi[curr].size();i++){
  
    bossPassedEdge[curr][pi[curr][i]]=true;
    bossPassedEdge[pi[curr][i]][curr]=true;
  
    if(visited[pi[curr][i]]) continue;

    colorPath(pi[curr][i],path,bossPassedEdge,pi,visited);
  }

}

void dijkstra(int start, int goal, vector<int> &path, bool bossPassed[MAX_SIZE], int &sum, bool bossPassedEdge[MAX_SIZE][MAX_SIZE]){

  vector<int> pi[MAX_SIZE];
  int cost[MAX_SIZE], nVisited;
  bool visited[MAX_SIZE];
  
  fill(visited,visited+nNode+1,false);
  fill(cost,cost+nNode+1,INT_MAX);
  fill(pi,pi+nNode+1,vector<int>());

  if(!bossPassed[start])
    cost[start] = 0;
  nVisited=0;

  while(nVisited!=nNode){
    
    int minPos, minVal=INT_MAX;

    for(int i=1;i<=nNode;i++){
      if(minVal>cost[i] && !visited[i]){
	minVal = cost[i];
	minPos = i;
      }
    }

    if(minVal==INT_MAX) break;

    nVisited++;
    visited[minPos] = true;

    for(int i=1;i<=nNode;i++){
      if(visited[i]) continue;
      if(bossPassed[i]) continue;
      if(bossPassedEdge[minPos][i]) continue;
      if(adjList[minPos][i]==INT_MAX) continue;
      
      if(cost[i]>cost[minPos]+adjList[minPos][i]){
	cost[i] = cost[minPos]+adjList[minPos][i];
	
	pi[i].clear();
	pi[i].push_back(minPos);
      }
      else if(cost[i]==cost[minPos]+adjList[minPos][i])
	pi[i].push_back(minPos);
    }
    
  }
   
  fill(visited,visited+nNode+1,false);
  colorPath(goal,path,bossPassedEdge,pi,visited);
  
/*
  for(int i=goal;i!=-1;i=pi[i]){ 
    path.push_back(i);
    if(pi[i]!=-1){
      bossPassedEdge[i][pi[i]]=true;
      bossPassedEdge[pi[i]][i]=true;
    }
  }
  */

  if(start==goal && bossPassed[start]) sum=INT_MAX;
  else sum = cost[goal];

}

void work(){
  /*
  for(int i=1;i<=nNode;i++){
    cout << i << " -> ";
    for(int j=1;j<=nNode;j++){
      if(adjList[i][j]!=INT_MAX)
	cout << j << " ";
    }cout << endl;
  }cout << endl;
  */
  
  int ans;
  bool visited[MAX_SIZE];  
  bool visitedEdge[MAX_SIZE][MAX_SIZE];
  vector<int> path;

  fill(visited,visited+nNode+1,false);
  for(int i=0;i<=nNode;i++)
    fill(visitedEdge[i],visitedEdge[i]+nNode+1,false);

  dijkstra(bossStart,bossGoal,path,visited,ans,visitedEdge);
  
  for(int i=0;i<path.size();i++){
    visited[path[i]] = true;

  }

  dijkstra(myStart,myGoal,path,visited,ans,visitedEdge);

  if(ans==INT_MAX) cout << "MISSION IMPOSSIBLE." << endl;
  else cout << ans << endl;

}

int main(){

  while(read())
    work();

  return 0;
}
