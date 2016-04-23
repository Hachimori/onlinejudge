#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define INF (1<<30)
#define NODE 125
using namespace std;

int nNode;
bool adj[NODE][NODE];

void read(){
  int nEdge;
  cin >> nNode >> nEdge;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adj[i][j] = false;
  
  for(int i=0;i<nEdge;i++){
    int s, t;
    cin >> s >> t;
    adj[s][t] = adj[t][s] = true;
  }
}

void bfs(int src, vector<int> pi[]){
  int visited[NODE];
  queue<int> Q;
  
  for(int i=0;i<nNode;i++)
    visited[i] = INF;
  visited[src] = 0;
  Q.push(src);
  
  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();
  
    for(int i=0;i<nNode;i++){
      if(!adj[curr][i]) continue;
      
      if(visited[i]>visited[curr]+1){
	Q.push(i);
	visited[i] = visited[curr]+1;
	pi[i].push_back(curr);
      }
      else if(visited[i]==visited[curr]+1)
	pi[i].push_back(curr);
    }
  }
}

int getRope(int dst, vector<int> pi[]){
  bool visited[NODE];
  queue<int> Q;
  int sum = 0;
  
  for(int i=0;i<nNode;i++)
    visited[i] = false;
  Q.push(dst);
  
  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();

    for(int i=0;i<pi[curr].size();i++){
      int next = pi[curr][i];
      sum++;
      if(!visited[next]) Q.push(next);
      visited[next] = true;
    }
  }
  
  return sum;
}

void work(int cases){
  int maxV = 0;
  
  for(int i=0;i<nNode;i++){
    vector<int> pi[NODE];
    bfs(i,pi);
    for(int j=i+1;j<nNode;j++)
      maxV = max(maxV,getRope(j,pi));
  }

  cout << "Case #" << cases << ": " << maxV << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  
  return 0;
}
