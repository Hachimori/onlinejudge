#include<iostream>
#include<vector>
#include<climits>

#define MAX_NODE 101

using namespace std;

class Node{
public:

  int connected;
  int cost;

  Node(){}
  Node(int co, int cost) : connected(co), cost(cost){}
};

int nNode,nQuery;
int adjList[MAX_NODE][MAX_NODE];
int mstCost[MAX_NODE][MAX_NODE];

bool read(){
  
  int nEdge;

  cin >> nNode >> nEdge >> nQuery;
  if(nNode==0 && nEdge==0 && nQuery==0) return false;


  for(int i=0;i<=nNode;i++)
    for(int j=0;j<=nNode;j++)
      adjList[i][j] = INT_MAX;
  

  for(int i=0;i<nEdge;i++){
    int source, target, cost;
    cin >> source >> target >> cost;
    
    adjList[source][target] = cost;
    adjList[target][source] = cost;
  }
 
  return true;
}

void mst(){

  bool visited[MAX_NODE];
  Node connecting[MAX_NODE];
  int nConnected=0;

  for(int i=0;i<=nNode;i++)
    visited[i] = false;
  for(int i=0;i<=nNode;i++)
    connecting[i] = Node(0,INT_MAX-1);

  connecting[1] = Node(0,0);

  
  while(nConnected+1!=nNode){
    
    int minPos, minVal=INT_MAX;
    for(int i=1;i<=nNode;i++){
      if(!visited[i] && minVal>connecting[i].cost){
	minVal = connecting[i].cost;
	minPos = i;
      }
    }
    
    visited[minPos] = true;
    nConnected++;
    
    for(int i=1;i<=nNode;i++){
      if(visited[i]) continue;
      
      if(connecting[i].cost>adjList[minPos][i])
	connecting[i] = Node(minPos,adjList[minPos][i]);
      
    }

  }

  //construct mst Graph
  for(int i=1;i<=nNode;i++)
    for(int j=1;j<=nNode;j++)
      mstCost[i][j] = INT_MAX;

  for(int i=1;i<=nNode;i++){
    if(connecting[i].connected!=0){
      mstCost[i][connecting[i].connected] = connecting[i].cost;
      mstCost[connecting[i].connected][i] = connecting[i].cost;
    }
  }
  
  /*
  for(int i=1;i<=nNode;i++){
    for(int j=1;j<=nNode;j++){
      if(mstCost[i][j]==INT_MAX) cout << "### " ;
      else cout << mstCost[i][j] << ' ';
    }cout << endl;
  }cout << endl;
  */

}

int dfs(int curr, int target, int maximum, bool visited[MAX_NODE]){
  
  if(curr==target) return maximum;

  visited[curr] = true;

  for(int i=1;i<=nNode;i++){
    if(visited[i] || mstCost[curr][i]==INT_MAX) continue;

    if(maximum<mstCost[curr][i]) {
      int tmp = dfs(i,target,mstCost[curr][i],visited);
      if(tmp!=-1) return tmp;
    }
    else {
      int tmp = dfs(i,target,maximum,visited);
      if(tmp!=-1) return tmp;
    }
  }

  return -1;
}

void work(int cases){

  mst();
  

  cout << "Case #" << cases << endl;
  for(int i=0;i<nQuery;i++){
    int source, target, ans;
    cin >> source >> target;

    bool visited[MAX_NODE];
    for(int j=1;j<=nNode;j++)
      visited[j] = false;
    
    ans = dfs(source,target,-1,visited);
    if(ans==-1) cout << "no path" << endl;
    else cout << ans << endl;
  }

}

int main(){

  for(int cases=1;read();cases++){
    if(cases!=1) cout << endl;
    work(cases);
  }

  return 0;
}
