// Bellman Ford
// 558 

#include<iostream>
#include<climits>
#include<vector>

#define MAX_SIZE 1005

using namespace std;

class Edge{
public:

  int target, cost;

  Edge(){}
  Edge(int target, int cost): target(target), cost(cost) {}
};

class Graph{
public:

  vector< vector<Edge> > adjList;

  Graph(){}
  Graph( int n ) {
    adjList.assign(n+1,vector<Edge>());
  }

  void insert(int source, int target, int cost){
    adjList[source].push_back(Edge(target,cost));
  }

  vector<Edge> &operator[](int n){
    return adjList[n];
  }

};

int nNode;
Graph g;

void read(){
  
  int nEdge;

  cin >> nNode >> nEdge;
  
  g = Graph(nNode);

  for(int i=0;i<nEdge;i++){
    int source, target, cost;
    cin >> source >> target >> cost;
    
    g.insert(source,target,cost);
  }
    
}

bool cycleExist(int curr, bool visited[MAX_SIZE], int pi[MAX_SIZE]){

  if(visited[curr]) return true;
  else visited[curr] = true;

  if(pi[curr]==-1) return false;
  
  return cycleExist(pi[curr],visited,pi);
}

void bellman(){
    
  int cost[MAX_SIZE], pi[MAX_SIZE];
  
  for(int i=0;i<nNode;i++){
    cost[i] = INT_MAX;
    pi[i] = -1;
  }

  cost[0] = 0;

  for(int i=0;i<nNode-1;i++){
    
    for(int j=0;j<nNode;j++){
      for(int k=0;k<g[j].size();k++){
	
	if(cost[j]==INT_MAX) continue;

	if(cost[g[j][k].target]>cost[j]+g[j][k].cost){
	  cost[g[j][k].target]=cost[j]+g[j][k].cost;
	  pi[g[j][k].target]=j;
	}
	
      }
    }

  }
  

  for(int i=0;i<nNode;i++){

    bool visited[MAX_SIZE];
    for(int j=0;j<nNode;j++)
      visited[j] = false;

    if(cycleExist(i,visited,pi)){
      cout << "possible" << endl;
      return;
    }
  }

  cout << "not possible" << endl;
}

void work(){

  bellman();

}

int main(){
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
