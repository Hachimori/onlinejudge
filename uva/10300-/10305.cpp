#include<iostream>
#include<vector>
#include<cassert>

#define MAX 101

class Graph{
 public:

  vector< vector<int> > adjList;
  vector< vector<int>::iterator > pos;
  vector<int> visited;

  Graph(){}
  Graph(int n){
    adjList.assign(n+1,vector<int>());
    pos.assign(n+1,vector<int>::iterator());
    visited.assign(n+1,false);
  }

  void reset(int n){
    for(int i=0;i<=n;i++)
      pos[i] = adjList[i].begin();
  }

  int next(int n){
    if(pos[n]!=adjList[n].end()) return *pos[n]++;
    else return -1;
  }

  void insert(int source, int target){
    adjList[source].push_back(target);
  }
  
};

int numNode;
bool first;

void dfs_rec(Graph &g, int arg, vector<int> &answer){
  
  g.visited[arg] = true;

  while(true){
    int next = g.next(arg);
    
    if(next==-1){
      answer.push_back(arg);
      return;
    }
    else if(g.visited[next]) continue;
    else dfs_rec(g,next,answer);

  }

}

bool read(Graph &g){
  
  int numEdge;

  cin >> numNode >> numEdge;
  if(numNode==0 && numEdge==0) return false;
  
  g = Graph(numNode);

  for(int i=0;i<numEdge;i++){
    int source, target;
    cin >> source >> target;
    
    g.insert(source,target);
  }

  return true;

}

void work(Graph &g){

  first = true;
  vector<int> answer;
  vector<int>::reverse_iterator i_ret;

  for(int i=1;i<=numNode;i++){
    g.reset(numNode);

    if(!g.visited[i])
      dfs_rec(g,i,answer);
  }

  for(i_ret=answer.rbegin();i_ret!=answer.rend();i_ret++){
    if(i_ret!=answer.rbegin()) cout << ' ' << *i_ret;
    else cout << *i_ret;
  }
 
  cout << endl;

}

int main(){

  Graph g;

  while(read(g))
    work(g);

  return 0;
}
