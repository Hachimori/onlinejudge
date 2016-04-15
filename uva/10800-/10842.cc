#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

#define MAX_NODE 105

using namespace std;

class Edge{
public:

  int target, cost;

  Edge(){ target=0; cost=-1; }
  Edge(int target, int cost) : target(target), cost(cost){}
};


class Graph{
public:
  
  Edge adjList[MAX_NODE][MAX_NODE];

  void insert(int source, int target, int cost){
    if(adjList[source][target].cost<cost)
      adjList[source][target] = Edge(target,cost);
  }
  

};

int nNode;
Graph g;

void read(){
  
  int nEdge;
  cin >> nNode >> nEdge;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      g.adjList[i][j] = Edge();

  for(int i=0;i<nEdge;i++){
    int source, target, cost;
  
    cin >> source >> target >> cost;

    g.insert(source,target,cost);
    g.insert(target,source,cost);
  }

}

void plim(int cases){
  
  int nConnected=0, maxList[MAX_NODE];
  bool visited[MAX_NODE];

  for(int i=0;i<nNode;i++){
    maxList[i] = -1;
    visited[i] = false;
  }

  maxList[0]=INT_MAX;

  
  while(nConnected+1<nNode){

    int currMax=-1, maxPos;
    for(int i=0;i<nNode;i++){
      if(!visited[i] && currMax<maxList[i]){
	currMax = maxList[i];
	maxPos = i;
      }
    }
    

    visited[maxPos] = true;
    nConnected++;


    for(int i=0;i<nNode;i++){
      Edge next = g.adjList[maxPos][i];

      if(!visited[next.target] && maxList[next.target]<next.cost)
	maxList[next.target]=next.cost;
    }
    

  }

  int minCost=INT_MAX;
  for(int i=0;i<nNode;i++)
    minCost = min(minCost,maxList[i]);  

  /*
  for(int i=0;i<nNode;i++)
    cout << maxList[i] << ' ';
  cout << endl;
  */

  cout << "Case #" << cases+1 << ": " << minCost << endl;

}

void work(int cases){
  
  plim(cases);

}


int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i);
  }

  return 0;
}
