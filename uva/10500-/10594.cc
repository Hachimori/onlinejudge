#include<iostream>
#include<algorithm>
#include<cstdio>
#define NODE 210
#define EDGE 5005
#define INF (1LL<<60)
using namespace std;
typedef long long integer;

int nNode, SRC, DST;
integer cap[NODE][NODE], cost[NODE][NODE];

bool read(){
  int nIn, nEdge;
  if(!(cin >> nIn >> nEdge)) return false;
  
  SRC = nIn*2;
  DST = nIn*2+1;
  nNode = nIn*2+2;
  
  for(int i=0;i<NODE;i++)
    for(int j=0;j<NODE;j++)
      cap[i][j] = cost[i][j] = 0;
  
  integer e[EDGE][3];
  for(int i=0;i<nEdge;i++){
    cin >> e[i][0] >> e[i][1] >> e[i][2];
    e[i][0]--, e[i][1]--;
  }
  
  integer toSend, capacity;
  cin >> toSend >> capacity;
  
  for(int i=0;i<nEdge;i++){
    integer s = e[i][0], t = e[i][1], c = e[i][2];
    cost[s+nIn][t] =  c;
    cost[t+nIn][s] =  c;
    cost[t][s+nIn] = -c;
    cost[s][t+nIn] = -c;
    cap[s+nIn][t] = capacity;
    cap[t+nIn][s] = capacity;
  }
  
  for(int i=0;i<nIn;i++)
    cap[i][i+nIn] = INF;
  cap[SRC][0] = cap[nIn-1+nIn][DST] = toSend;
  
  return true;
}

bool bellman(integer pi[], integer pre[]){
  integer dist[NODE];
  bool visited[NODE];
  
  fill(dist,dist+nNode,INF);
  fill(visited,visited+nNode,false);
  fill(pi,pi+nNode,-1);
  dist[SRC] = 0;
  
  for(int k=0;k<nNode;k++){
    integer minPos = -1, minV = INF;

    for(int i=0;i<nNode;i++)
      if(minV>dist[i] && !visited[i]){
        minV = dist[i];
        minPos = i;
      }

    if(minPos==-1) break;
    visited[minPos] = true;

    for(int i=0;i<nNode;i++){
      if(cap[minPos][i]==0) continue;
      if(dist[i]>dist[minPos]+cost[minPos][i]+pre[minPos]-pre[i]){
        dist[i] = dist[minPos]+cost[minPos][i]+pre[minPos]-pre[i];
        pi[i] = minPos;
      }
    }
  }

  for(int i=0;i<nNode;i++)
    pre[i] += dist[i];
  
  return pi[DST]!=-1;
}

integer minCostFlow(){
  integer pi[NODE], pre[NODE];
  integer ret = 0;
  fill(pre,pre+nNode,0);
  
  while(bellman(pi,pre)){
    integer flow = INF;
    for(int i=DST;pi[i]!=-1;i=pi[i]) 
      flow = min(flow,cap[pi[i]][i]);

    for(int i=DST;pi[i]!=-1;i=pi[i]){
      cap[pi[i]][i] -= flow;
      cap[i][pi[i]] += flow;
      ret += cost[pi[i]][i]*flow;
    }
  }

  return (cap[SRC][0]>0 ? -1 : ret);
}

void work(){
  integer ans = minCostFlow();

  if(ans<0)
    cout << "Impossible." << endl;
  else
    cout << ans << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
