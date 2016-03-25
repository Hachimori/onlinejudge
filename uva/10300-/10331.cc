#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

#define MAX_EDGE 500000
#define MAX_SIZE 105

using namespace std;

class Edge{
public:
  
  int target, cost, id;

  Edge(){}
  Edge(int t, int c, int i): target(t), cost(c), id(i) {}
};

class Graph{

public:

  vector< vector< Edge > > adjList;

  Graph(){}
  Graph(int n){
    adjList.assign(n+1,vector< Edge > ());
  }
  
  void insert(int source, int target, int cost, int id){
    adjList[source].push_back(Edge(target,cost,id));
  }

  vector< Edge > &operator[] (int n){
    return adjList[n];
  }

};

int nNode, nEdge;
pair<int,int> edgeList[MAX_EDGE];
Graph g;

bool read(){
  
  
  if(!(cin >> nNode >> nEdge)) return false;
  
  g = Graph(nNode);

  for(int i=0;i<nEdge;i++){
    int source, target, cost;
    cin >> source >> target >> cost;
    
    source--, target--;

    g.insert(source,target,cost,i);
    g.insert(target,source,cost,i);
    edgeList[i] = make_pair(source,target);
  }

  return true;
}

void dfs(int curr, vector<int> pi[MAX_SIZE], int cnt[MAX_EDGE], bool used[MAX_EDGE]){

  for(int i=0;i<pi[curr].size();i++){

    if(used[pi[curr][i]]) continue;
    
    if(edgeList[pi[curr][i]].first==curr){
      used[pi[curr][i]]++;
      cnt[pi[curr][i]]++;
      dfs(edgeList[pi[curr][i]].second,pi,cnt,used);
    }
    else if(edgeList[pi[curr][i]].second==curr){
      used[pi[curr][i]]++;
      cnt[pi[curr][i]]++;
      dfs(edgeList[pi[curr][i]].first,pi,cnt,used);
    }
  }

}

void dijkstra(int curr, int cnt[MAX_EDGE]){
  
  int cost[MAX_SIZE];
  vector<int> pi[MAX_SIZE];
  bool visited[MAX_SIZE];
  
  for(int i=0;i<nNode;i++){
    cost[i] = INT_MAX;
    visited[i] = false;
  }
  
  int nVisited=0;
  cost[curr] = 0;
  
  while(nVisited<nNode){

    int minPos, minVal=INT_MAX;

    for(int i=0;i<nNode;i++){
      if(minVal>cost[i] && !visited[i]){
	minPos = i;
	minVal = cost[i];
      }
    }
   
    if(minVal==INT_MAX) break;
    visited[minPos] = true;
    nVisited++;
    
    for(int i=0;i<g[minPos].size();i++){
      
      int nextNode = g[minPos][i].target;
      int nextCost = g[minPos][i].cost;

      if(cost[nextNode]>cost[minPos]+nextCost){
	cost[nextNode]=cost[minPos]+nextCost;	
	pi[nextNode].clear();
	pi[nextNode].push_back(g[minPos][i].id);
      }
      else if(cost[nextNode]==cost[minPos]+nextCost)
	pi[nextNode].push_back(g[minPos][i].id);
      
    }


  } 
  /*
  for(int i=0;i<nNode;i++){
    cout << i << ": ";
    for(int j=0;j<pi[i].size();j++){
      cout << pi[i][j] << ' ';
    }cout << endl;
  }cout << endl;
  */

  bool used[MAX_EDGE];

  for(int j=curr+1;j<nNode;j++){
    
    for(int i=0;i<nEdge;i++)
      used[i]=false;
    
    dfs(j,pi,cnt,used);
  }
  
  
}
  


void work(){

  int cnt[MAX_EDGE];
  
  for(int i=0;i<nEdge;i++)   
      cnt[i] = 0;

  for(int i=0;i<nNode;i++)
    dijkstra(i,cnt);


  int maxVal=0;
  vector< int > maxIndex;
  
  for(int i=0;i<nEdge;i++){
    if(maxVal<cnt[i]){
      maxVal = cnt[i];
      maxIndex.clear();
      maxIndex.push_back(i);
    }
    else if(maxVal==cnt[i]){
      maxIndex.push_back(i);
    }
  }
  
  sort(maxIndex.begin(),maxIndex.end());
  
  for(int i=0;i<maxIndex.size();i++){
    if(i==0) cout << maxIndex[i]+1;
    else cout << ' ' << maxIndex[i]+1;
  }
  cout << endl;
}

int main(){

  while(read())
    work();

  return 0;
}
