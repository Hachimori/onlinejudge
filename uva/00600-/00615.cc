#include<iostream>
#include<map>
#include<vector>

#define MAX_SIZE 10000

using namespace std;

class Graph{
public:

  vector< vector<int> > adjList;

  Graph(){}
  Graph(int n){
    adjList.assign(n+1,vector<int>());
  }

  void insert(int source, int target){
    adjList[source].push_back(target);
  }
  
  vector<int> &operator[] (int n) {
    return adjList[n];
  }
  
};

int nNode;
int degree[MAX_SIZE];
map<int,int> id;
Graph g;

bool read(){
  
  nNode=0;
  id.clear();
  g = Graph(MAX_SIZE);
  for(int i=0;i<MAX_SIZE;i++)
    degree[i] = 0;

  while(true){    
    int target, source;
    cin >> source >> target;
    
    if(target==0 && source==0) break;
    if(target==-1 && source==-1) return false;

    if(id.find(target)==id.end())
      id[target]=nNode++;
    
    if(id.find(source)==id.end())
      id[source]=nNode++;
    
    g.insert(id[source],id[target]);
    degree[id[target]]++;    
  }

  return true;
}

bool existCycle(int curr, int &nVisited, bool visited[MAX_SIZE], bool &succeed){  
  
  nVisited++;
  visited[curr]=true;
  
  for(int i=0;i<g[curr].size();i++){
    
    int next=g[curr][i];

    if(visited[next]){ 
      succeed=false;
      return false;
    }

    if(existCycle(next,nVisited,visited,succeed)) return true;
  }

  if(nVisited==nNode) return true;

  return false;
}

void work(int cases){
  
  cout << "Case " << cases << ' '; 

  if(nNode==0){
    cout << "is a tree." << endl;
    return;
  }
  
  for(int i=0;i<nNode;i++)
    if(degree[i]>1){
      cout << "is not a tree." << endl;
      return;
    }
  
  for(int i=0;i<nNode;i++){
    bool visited[MAX_SIZE];
    for(int j=0;j<nNode;j++)
      visited[j] = false;
    
    bool succeed=true;
    
    int nVisited=0;
    
    if(existCycle(i,nVisited,visited,succeed) && succeed){        
      cout << "is a tree." << endl;
      return;
    }
  }
  
  cout << "is not a tree." << endl;
  
}

int main(){
  
  for(int cases=1;read();cases++)
    work(cases);

  return 0;
}
