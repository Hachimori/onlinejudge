#include<iostream>
#include<vector>

using namespace std;

class Graph{
public:
  
  vector< vector<int> > adjList;

  Graph(){}
  Graph(int n){
    adjList.assign(n+1,vector<int>());
  }
  
  void insert(int source, int destination){
    adjList[source].push_back(destination);
  }

  vector<int> operator[](int n){
    return adjList[n];
  }

};

Graph g;

void input(){

  g = Graph(5);

  g.insert(1,2);
  g.insert(1,3);
  g.insert(1,5);

  g.insert(2,1);
  g.insert(2,3);
  g.insert(2,5);

  g.insert(3,1);
  g.insert(3,2);
  g.insert(3,4);
  g.insert(3,5);
  
  g.insert(4,3);
  g.insert(4,5);
  
  g.insert(5,1);
  g.insert(5,2);
  g.insert(5,3);
  g.insert(5,4); 
    
}

void dfs(int nVisited, int curr, bool visited[6][6], vector<int> pi){

  if(nVisited==8) {
    for(int i=0;i<pi.size();i++)
      cout << pi[i];
    cout << curr;
    cout << endl;
  }




  for(int i=0;i<g[curr].size();i++){
    
    int next = g[curr][i];

    if(visited[curr][next]) continue;
    else {
      
      pi.push_back(curr);
      visited[curr][next] = true;
      visited[next][curr] = true;
 
      dfs(nVisited+1,next,visited,pi);
      
      pi.pop_back();
      visited[curr][next] = false;
      visited[next][curr] = false;

    }    

  }

}

void work(){

  vector<int> pi;
  bool visited[6][6];

  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      visited[i][j] = false;
  

  dfs(0,1,visited,pi);

}

int main(){

  input();
  work();

  return 0;
}
