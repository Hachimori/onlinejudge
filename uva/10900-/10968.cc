#include<iostream>
#include<queue>
#include<algorithm>
#define NODE 1005
#define INF (1<<30)
using namespace std;

int nNode, degree[NODE];
bool adj[NODE][NODE];

bool read(){
  int nEdge;
  cin >> nNode >> nEdge;
  if(nNode==0 && nEdge==0) return false;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adj[i][j] = false, degree[i] = 0;
  
  for(int i=0;i<nEdge;i++){
    int s, t;
    cin >> s >> t;
    s--, t--;
    adj[s][t] = adj[t][s] = true;
    degree[s]++;
    degree[t]++;
  }

  return true;
}

int bfs(int src, int dst, bool avail[]){
  int cost[NODE];
  queue<int> Q;
  
  fill(cost,cost+nNode,INF);
  cost[src] = 0;
  if(avail[src]) Q.push(src);
  
  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();
    
    if(curr==dst) return cost[curr];
    
    for(int i=0;i<nNode;i++){
      if(!avail[i] || cost[i]!=INF || !adj[curr][i]) continue;
      cost[i] = cost[curr]+1;
      Q.push(i);
    }
  }
  
  return INF;
}

void work(){
  if(count(degree,degree+nNode,0)){
    cout << "Poor Koorosh" << endl;
    return;
  }  

  int src = -1, dst = -1;
  for(int i=0;i<nNode;i++)
    if(degree[i]%2==1)
      (src==-1 ? src : dst) = i;

  if(src==-1 && dst==-1){
    cout << 0 << endl;
    return;
  }
  
  bool avail[NODE];
  for(int i=0;i<nNode;i++)
    avail[i] = (degree[i]>=3);

  int ret = bfs(src,dst,avail);
  if(ret==INF) cout << "Poor Koorosh" << endl;
  else cout << ret << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
