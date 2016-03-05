#include<iostream>
#include<queue>
#include<string>
#include<map>

#define INF 10000000
#define MAX_SIZE 505

using namespace std;

class Flow{
public:

  int dst, flow;

  Flow(){}
  Flow(int d, int f): dst(d), flow(f){}
};

int nNode, SRC, SINK, nProd;
int capacity[MAX_SIZE][MAX_SIZE];

void read(){
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++)
      capacity[i][j] = 0;
  
  
  int nPlug, nConnect;
  string plug[MAX_SIZE], prod[MAX_SIZE][2], connect[MAX_SIZE][2]; 
  map<string,int> left, right;
  
  cin >> nPlug;
  for(int i=0;i<nPlug;i++){
    cin >> plug[i];

    if(!left.count(plug[i])){
      int size = left.size();
      left[plug[i]] = size;
    }
  }

  cin >> nProd;
  for(int i=0;i<nProd;i++){
    cin >> prod[i][0] >> prod[i][1];
  
    if(!right.count(prod[i][0])){
      int size = right.size();
      right[prod[i][0]] = size;
    }

    if(!left.count(prod[i][1])){
      int size = left.size();
      left[prod[i][1]] = size;
    }
  }

  cin >> nConnect;
  for(int i=0;i<nConnect;i++){
    cin >> connect[i][0] >> connect[i][1];
    
    for(int j=0;j<2;j++)
      if(!left.count(connect[i][j])){
	int size = left.size();
	left[connect[i][j]] = size;
      }
  }

  
  nNode = left.size()+right.size()+2;
  SINK = left.size()+right.size()+1;
  SRC = left.size()+right.size();
  
  for(int i=0;i<nPlug;i++)
    capacity[SRC][i] = 1;

  for(int i=0;i<nProd;i++)
    capacity[i+left.size()][SINK] = 1;

  
  for(int i=0;i<nProd;i++){
    int prodId = right[prod[i][0]], plugId = left[prod[i][1]];
    
    capacity[plugId][prodId+left.size()] = INF;
  }
  
  for(int i=0;i<nConnect;i++){
    int plug1 = left[connect[i][0]], plug2 = left[connect[i][1]];

    capacity[plug2][plug1] = INF;
  }
}

void addFlow(int pi[], int &flow){
  int visited[MAX_SIZE];  
  queue<Flow> Q;
  
  for(int i=0;i<nNode;i++)
    visited[i] = 0;
  visited[SRC] = 1;
  
  Q.push( Flow(SRC,INF) );
  
  
  while(!Q.empty()){
    Flow curr = Q.front();
    Q.pop();

    if(visited[curr.dst]>curr.flow) continue;
    
    if(curr.dst==SINK){
      flow = curr.flow;
      break;
    }
        
    for(int i=0;i<nNode;i++){
      if(capacity[curr.dst][i]<=0) continue;
      
      Flow next;
      next.flow = min(curr.flow,capacity[curr.dst][i]);
      next.dst = i;

      if(visited[next.dst]>=next.flow) continue;
      visited[next.dst] = next.flow;
      pi[next.dst] = curr.dst;
      
      Q.push(next);
    }
  }
}

int maxMatch(){
  int total=0;
  
  while(true){
    int pi[MAX_SIZE], flow = 0;
    pi[SRC] = -1;
    
    addFlow(pi,flow);
    if(flow==0) break;
    
    int curr = SINK;
    while(pi[curr]!=-1){
      capacity[pi[curr]][curr] -= flow;
      capacity[curr][pi[curr]] += flow;
      curr = pi[curr];
    }
    
    total += flow;
  }
  
  return total;
}

void work(){
  cout << nProd-maxMatch() << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }
  
  return 0;
}
