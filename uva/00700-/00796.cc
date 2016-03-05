// 796
// bridge

#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

#define NODE 1000

using namespace std;

class Edge{
public:
  int src, dst;
  
  Edge(){}
  Edge(int s, int d): src(s), dst(d){}
  
  bool operator< (const Edge &e) const {
    if(src!=e.src) return src<e.src;
    return dst<e.dst;
  }
};

int nNode;
bool adjList[NODE][NODE];

bool read(){
  
  if(!(cin >> nNode)) return false;  

  for(int i=0;i<nNode;i++)
    fill(adjList[i],adjList[i]+nNode,false);
  
  
  for(int i=0;i<nNode;i++){
    char c;
    int source, nEdge;
    
    cin >> source >> c >> nEdge >> c;
    
    for(int j=0;j<nEdge;j++){
      int target;
      cin >> target;

      adjList[source][target] = true;
      adjList[target][source] = true;

    }
  }

  return true;
}

void dfs(int curr, int &nVisited, vector<Edge> &bridge,
	 int visited[], int back[], int prev){
  
  visited[curr] = back[curr] = nVisited++;

  for(int i=0;i<nNode;i++){
    if(i==prev) continue;
    if(!adjList[curr][i]) continue;
    
    if(visited[i]==-1){ 
      dfs(i,nVisited,bridge,visited,back,curr);
      back[curr] = min(back[curr],back[i]);
    }
    else if(visited[curr]>visited[i]){ 
      back[curr] = min(back[curr],back[i]);
    }
  }
  
  if(prev!=-1 && visited[curr]==back[curr])
    bridge.push_back(Edge(prev,curr));
}

void findBridge(vector<Edge> &bridge){
  int visited[NODE], back[NODE];
  int nVisited=0;

  fill(visited,visited+nNode,-1);

  for(int i=0;i<nNode;i++){
    if(visited[i]==-1)
      dfs(i,nVisited,bridge,visited,back,-1);
  }
}

void work(){
  vector<Edge> bridge;
  
  findBridge(bridge);

  for(int i=0;i<bridge.size();i++)
    if(bridge[i].src>bridge[i].dst)
      swap(bridge[i].src,bridge[i].dst);
  
  sort(bridge.begin(),bridge.end());
  
  cout << bridge.size() << " critical links" << endl;
  for(int i=0;i<bridge.size();i++){
    cout << bridge[i].src << " - " << bridge[i].dst << endl;
  }
  cout << endl;

}

int main(){
  while(read())
    work();

  return 0;
}
