#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>

#define INF 10000000
#define BUF 300

using namespace std;

int nNode, SRC, DST;
int capacity[BUF][BUF];

bool read(){
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      capacity[i][j] = 0;
  
  int nReg;
  if(!(cin >> nReg)) return false;
  
  SRC = nReg*2;
  DST = nReg*2+1;
  nNode = nReg*2+2;
  
  for(int i=0;i<nReg;i++){
    int amt;
    cin >> amt;
    capacity[i][i+nReg] = amt;
    capacity[i+nReg][i] = 0;
  }
  
  
  int nEdge;
  cin >> nEdge;

  for(int i=0;i<nEdge;i++){
    int src, dst, amt;
    cin >> src >> dst >> amt;
    src--, dst--;
    capacity[src+nReg][dst] = amt;
    capacity[dst][src+nReg] = 0;
  }

  int nSource, nSink;
  cin >> nSource >> nSink;

  for(int i=0;i<nSource;i++){
    int id;
    cin >> id;
    id--;
    capacity[SRC][id] = INF;
    capacity[id][SRC] = 0;
  }
  
  for(int i=0;i<nSink;i++){
    int id;
    cin >> id;
    id--;
    capacity[id+nReg][DST] = INF;
    capacity[DST][id+nReg] = 0;
  }

  return true;
}

bool addFlow(int pi[]){
  static int visited[BUF];  
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

    for(int i=0;i<nNode;i++){
      int nextFlow = min(visited[curr],capacity[curr][i]);
      if(nextFlow==0) continue;
      
      if(visited[i]>=nextFlow) continue;
      visited[i] = nextFlow;
      pi[i] = curr;
      
      Q.push(i);
    }
  }

  return false;
}

void maximumFlow(){
  int pi[BUF], total=0;
  
  while(addFlow(pi)){
    int curr = DST, flow = INF;
    
    while(pi[curr]!=-1){
      flow = min(flow,capacity[pi[curr]][curr]);
      curr = pi[curr];
    }
    
    curr = DST;
    
    while(pi[curr]!=-1){
      capacity[pi[curr]][curr] -= flow;
      capacity[curr][pi[curr]] += flow;
      curr = pi[curr];
    }
    
    total += flow;
  }
  
  cout << total << endl;
}

void work(){
  maximumFlow();
}

int main(){
  while(read())
    work();
  
  return 0;
}
