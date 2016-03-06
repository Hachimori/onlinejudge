#include<iostream>
#include<queue>
#include<algorithm>

#define INF 2000000000
#define NODE 105

using namespace std;

int nNode, SRC, DST;
int capacity[NODE][NODE];

bool read(){
  cin >> nNode;
  if(nNode==0) return false;

  SRC = nNode;
  DST = nNode+1;
  nNode = nNode+2;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      capacity[i][j] = 0;

  int start, goal, nEdge;
  cin >> start >> goal >> nEdge;
  
  start--, goal--;
  
  for(int i=0;i<nEdge;i++){
    int src, dst, cap;
    cin >> src >> dst >> cap;

    src--, dst--;
    capacity[src][dst] += cap;
    capacity[dst][src] += cap;
  }
  
  capacity[SRC][start] = INF;
  capacity[start][SRC] = 0;
  capacity[goal][DST] = INF;
  capacity[DST][goal] = 0;

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

int maximumFlow(){
  int pi[NODE], total=0;
  
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
  
  return total;
}

void work(int cases){
  cout << "Network " << cases << endl;
  cout << "The bandwidth is " << maximumFlow() << "." << endl;
}

int main(){
  for(int cases=1;read();cases++){
    work(cases);
    cout << endl;
  }

  return 0;
}
