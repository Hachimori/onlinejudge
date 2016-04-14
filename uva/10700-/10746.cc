// min cost flow

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cfloat>

#define EPS FLT_EPSILON
#define NODE 43
#define INF 10000000

using namespace std;

int nNode, SINK, SRC;
int cap[NODE][NODE];
double cost[NODE][NODE];
int nLeft;

bool read(){
  for(int i=0;i<NODE;i++)
    for(int j=0;j<NODE;j++)
      cost[i][j] = cap[i][j] = 0;
  
  int nRight;
  cin >> nLeft >> nRight;
  if(nLeft==0 && nRight==0) return false;

  SINK = nLeft+nRight;  
  SRC = nLeft+nRight+1;
  nNode = nLeft+nRight+2;
  
  for(int i=0;i<nLeft;i++)
    cap[SRC][i] = 1;
  
  for(int i=0;i<nRight;i++)
    cap[i+nLeft][SINK] = 1;

  for(int i=0;i<nLeft;i++)
    for(int j=0;j<nRight;j++){
      double c;
      cin >> c;

      cost[i][j+nLeft] = c;
      cost[j+nLeft][i] = -c;
      cap[i][j+nLeft] = 1;
    }
  
  return true;
}

bool dijkstra(int pi[], double pre[]){
  double dist[NODE];
  bool visited[NODE];
  
  for(int i=0;i<nNode;i++){
    pi[i] = -1;
    dist[i] = INF;
    visited[i] = false;
  }
  
  dist[SRC] = 0;
  
  for(int i=0;i<nNode;i++){
    int minPos = -1;
    double minVal = INF;
    
    for(int j=0;j<nNode;j++)
      if(minVal>dist[j] && !visited[j]){
	minVal = dist[j];
	minPos = j;
      }
    
    if(minPos==-1) break;
    visited[minPos] = true;
    
    for(int j=0;j<nNode;j++){
      if(cap[minPos][j]==0) continue;
      if(dist[j]>dist[minPos]+cost[minPos][j]+pre[minPos]-pre[j]){
	dist[j] = dist[minPos]+cost[minPos][j]+pre[minPos]-pre[j];
	pi[j] = minPos;
      }
    }
  }    
  
  for(int i=0;i<nNode;i++)
    pre[i] += dist[i];
  
  return pi[SINK]!=-1;
}

double minCostFlow(){
  int pi[NODE];
  double pre[NODE], sum = 0;

  for(int i=0;i<nNode;i++)
    pre[i] = 0;
  
  while(dijkstra(pi,pre)){
    int flow = INF;
    
    for(int i=SINK;pi[i]!=-1;i=pi[i])
      flow = min(flow,cap[pi[i]][i]);
    
    for(int i=SINK;pi[i]!=-1;i=pi[i]){
      cap[pi[i]][i] -= flow;
      cap[i][pi[i]] += flow;
    }
    
    for(int i=SINK;pi[i]!=-1;i=pi[i])
      sum += cost[pi[i]][i]*flow;
  }
  
  return sum;
}

void work(){
  printf("%.2lf\n",minCostFlow()/nLeft+EPS);
}

int main(){
  while(read())
    work();
  
  return 0;
}
