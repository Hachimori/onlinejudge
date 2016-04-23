#include<iostream>
#include<queue>
#define NODE 1005
#define INF (1<<30)
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

void bfs(int cost[]){
  queue<int> Q;
  
  for(int i=0;i<nNode;i++)
    cost[i] = INF;
  cost[0] = 0;
  Q.push(0);

  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();

    for(int i=0;i<nNode;i++){
      if(!adj[curr][i] || cost[i]!=INF) continue;
      cost[i] = cost[curr]+1;
      Q.push(i);
    }
  }
}

void work(){
  int cost[NODE];
  bfs(cost);
  
  for(int i=1;i<nNode;i++)
    cout << cost[i] << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  
  return 0;
}
