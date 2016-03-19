#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define INF 2000000000
#define NODE 1025

using namespace std;

int nNode, SRC, DST, nType, nProb;
vector<int> adj[NODE];
int capacity[NODE][NODE];

bool read(){
  cin >> nType >> nProb;
  if(nType==0 && nProb==0) return false;
  
  SRC = nType+nProb;
  DST = nType+nProb+1;
  nNode = nType+nProb+2;
  
  for(int i=0;i<nNode;i++)
    adj[i].clear();
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      capacity[i][j] = 0;
  
  for(int i=0;i<nType;i++){
    int cap;
    cin >> cap;
    adj[SRC].push_back(i);
    adj[i].push_back(SRC);
    capacity[SRC][i] = cap;
    capacity[i][SRC] = 0;
  }

  for(int i=0;i<nProb;i++){
    int nEdge;
    cin >> nEdge;
    for(int j=0;j<nEdge;j++){
      int id; 
      cin >> id;  
      id--;
      adj[id].push_back(i+nType);
      adj[i+nType].push_back(id);
      capacity[id][i+nType] = 1;
      capacity[i+nType][id] = 0;
    }
  }
  
  for(int i=0;i<nProb;i++){
    adj[i+nType].push_back(DST);
    adj[DST].push_back(i+nType);
    capacity[i+nType][DST] = 1;
    capacity[DST][i+nType] = 0;
  }
    
  return true;
}

bool addFlow(int pi[]){
  static int visited[NODE];
  queue<int> Q;
  
  for(int i=0;i<nNode;i++)
    visited[i] = 0;
  visited[SRC] = INF;
  pi[SRC] = -1;
  
  Q.push(SRC);
  
  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();

    if(curr==DST) return true;

    for(int i=0;i<adj[curr].size();i++){
      int next = adj[curr][i];
      int nextFlow = min(visited[curr],capacity[curr][next]);
      if(nextFlow==0) continue;
      
      if(visited[next]>=nextFlow) continue;
      visited[next] = nextFlow;
      pi[next] = curr;
      
      Q.push(next);
    }
  }

  return false;
}

void maximumFlow(){
  static int pi[NODE], total, flow[NODE][NODE];
  
  total = 0;
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      flow[i][j] = 0;

  while(addFlow(pi)){
    int curr = DST, toAdd = INF;
    
    while(pi[curr]!=-1){
      toAdd = min(toAdd,capacity[pi[curr]][curr]);
      curr = pi[curr];
    }
    
    curr = DST;
    
    while(pi[curr]!=-1){
      capacity[pi[curr]][curr] -= toAdd;
      capacity[curr][pi[curr]] += toAdd;
      flow[pi[curr]][curr] += toAdd;
      flow[curr][pi[curr]] -= toAdd;
      curr = pi[curr];
    }
  }
  
  for(int i=0;i<nType;i++)
    if(capacity[SRC][i]!=0){
      cout << 0 << endl;
      return;
    }
  
  cout << 1 << endl;
  for(int i=0;i<nType;i++){
    bool first = true;
    for(int j=0;j<nProb;j++){
      if(flow[i][j+nType]<=0) continue;
      if(first) first = false;
      else cout << ' ';
      cout << j+1;
    }
    cout << endl;
  }
}


void work(){
  maximumFlow();
}

int main(){
  while(read())
    work();

  return 0;
}
