#include<iostream>
#include<algorithm>
#define NODE 205
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

bool bicolor(int curr, bool visited[], bool color[], int &b, int &w){
  visited[curr] = true;
  (color[curr]? b : w)++;
  
  for(int i=0;i<nNode;i++){
    if(!adj[curr][i] || i==curr) continue;
    if(visited[i]){
      if(color[i]==color[curr]) return false;
      continue;
    }
    color[i] = !color[curr];
    
    if(!bicolor(i,visited,color,b,w)) return false;
  }

  return true;
}

void work(){
  int sum = 0;
  bool visited[NODE], color[NODE];
  
  fill(visited,visited+nNode,false);
  
  for(int i=0;i<nNode;i++){
    if(visited[i]) continue;
    color[i] = true;
    int b = 0, w = 0;
    if(!bicolor(i,visited,color,b,w)) {
      cout << -1 << endl;
      return;
    }
    sum += min(b,w);
    if(min(b,w)==0) sum++;
  }
  cout << sum << endl;
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
