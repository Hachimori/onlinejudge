#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>

#define MAX_SIZE 21

using namespace std;

class Graph{
public:

  bool adjList[MAX_SIZE+1][MAX_SIZE+1];

  Graph(){}
  Graph(int n){
    for(int i=0;i<=n;i++)
      for(int j=0;j<=n;j++)
	adjList[i][j]=false;
  }

  void insert(int source, int target){
    adjList[source][target]=true;
  }

};


Graph g;
vector< vector<int> > pathList;
int goal, cntPath;

bool read(){

  if(scanf("%d",&goal)==EOF) return false;

  g = Graph(MAX_SIZE);

  while(true){
    int source, target;
    scanf("%d%d",&source,&target);

    if(source==0 && target==0) break;
    
    g.insert(source,target);
    g.insert(target,source);
  }

  /*
  for(int i=1;i<=MAX_SIZE;i++){
    cout << i << ": ";
    for(int j=1;j<=MAX_SIZE;j++){
      if(g.adjList[i][j]) cout << " " << j;
    }cout << endl;
  }
  */

  return true;
}

bool isReachAble(int curr, bool visited[MAX_SIZE+1]){
  
  queue<int> Q;
  bool visitedTmp[MAX_SIZE+1];

  for(int i=0;i<=MAX_SIZE;i++)
    visitedTmp[i] = visited[i];

  Q.push(curr);

  while(!Q.empty()){
    
    int next = Q.front();
    Q.pop();

    if(visitedTmp[next]) continue;
    else visitedTmp[next]=true;

    for(int i=1;i<=MAX_SIZE;i++){      
      if(!g.adjList[next][i]) continue;

      if(i==goal) return true;      

      if(!visitedTmp[i]) Q.push(i);
    }

  }


  return false;
}

void dfs(int curr, int nWalk, int currPath[MAX_SIZE+1], bool visited[MAX_SIZE+1]){
  
  if(curr==goal){
    for(int i=0;i<nWalk;i++){
      if(i!=0) printf(" %d",currPath[i]);
      else printf("%d",currPath[i]);
    }
    if(nWalk>0)
      printf(" %d\n",goal);
    else
      printf("%d\n",goal);

    cntPath++;
    return;
  }

  
  for(int i=1;i<=MAX_SIZE;i++){
    if(!g.adjList[curr][i]) continue;
    if(!isReachAble(curr,visited)) continue;

    if(!visited[i]){
      visited[curr] = true;
      currPath[nWalk] = curr;

      dfs(i,nWalk+1,currPath,visited);

      visited[curr] = false;
    }
  }

}

void work(int cases){
  
  bool visited[MAX_SIZE+1];
  int currPath[MAX_SIZE+1];

  cntPath=0;
  for(int i=0;i<MAX_SIZE;i++)
    visited[i] = false;
  
  printf("CASE %d:\n",cases);
  dfs(1,0,currPath,visited);

  printf("There are %d routes from the firestation to streetcorner %d.\n",cntPath,goal);


}

int main(){
  
  for(int cases=1;read();cases++){
    //if(cases>1) cout << endl;
    work(cases); 
  }

  return 0;
}
