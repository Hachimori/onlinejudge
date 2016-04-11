#include<iostream>
#include<vector>
#include<climits>
#include<map>

#define MAX_SIZE 500

using namespace std;

int adjList[MAX_SIZE][MAX_SIZE];
int nNode, nSpace, start1, start2, goal1, goal2;
map<int,int> id;
map<int,int> rev;

bool read(){

  cin >> nSpace;
  if(nSpace==0) return false;

  rev.clear();
  id.clear();
  nNode=0;
  
  for(int i=0;i<MAX_SIZE;i++)
    fill(adjList[i],adjList[i]+MAX_SIZE,0);
  
  
  int nEdge;
  cin >> nEdge;      
  
  for(int i=0;i<2;i++){
    
    int source, target;
    cin >> source >>  target;
  
    if(id.find(source)==id.end()){
      id[source]=nNode;
      rev[nNode] = source;
      nNode++;
    }
    
    if(id.find(target)==id.end()){
      id[target]=nNode;
      rev[nNode] = target;
      nNode++;
    }
    
    if(i==0){ 
      start1=id[source];
      start2=id[target];
    }
    if(i==1){ 
      goal1=id[source];
      goal2=id[target];
    }

    adjList[id[source]][id[target]]++;

  }


  for(int i=0;i<nEdge;i++){
    int source, target;
    cin >> source >>  target;
  
    if(id.find(source)==id.end()){
      id[source]=nNode;
      rev[nNode] = source;
      nNode++;
    }
    
    if(id.find(target)==id.end()){
      id[target]=nNode;
      rev[nNode] = target;
      nNode++;
    }

     adjList[id[source]][id[target]]++;
     adjList[id[target]][id[source]]++; 
  }

  return true;
}

bool dfs(int curr, int prev, int nVisited){
  
  
  if(curr==goal2 && prev==goal1 && nVisited-1>=nSpace) return true;
  

  for(int i=0;i<nNode;i++){
    
    if(adjList[curr][i]<=0) continue;
    
    adjList[curr][i]--;
    adjList[i][curr]--;
    
    if(dfs(i,curr,nVisited+1)) return true;
    
    adjList[curr][i]++;
    adjList[i][curr]++;
    
  }
  
  return false;

}

void work(){
  /*
  for(int i=0;i<nNode;i++){
    for(int j=0;j<nNode;j++){
      cout << adjList[i][j] << ' ';
    }cout << endl;
  }cout << endl;
  */
  
  adjList[start1][start2]--;
  
  
  if(dfs(start2,start1,0)) cout << "YES" << endl;
  else cout << "NO" << endl;
  
}

int main(){

  while(read())
    work();

  return 0;

}
