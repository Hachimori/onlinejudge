#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#define BUF 25
#define INF (INT_MAX)
using namespace std;

int nNode, nEdge, val[4];
bool adj[BUF][BUF];

bool read(){
  cin >> nNode;
  if(nNode==0) return false;

  cin >> nEdge;
  for(int i=0;i<4;i++) cin >> val[i];

  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      adj[i][j] = false;
  
  for(int i=0;i<nEdge;i++){
    int s, t; 
    cin >> s >> t; 
    s--, t--;
    adj[s][t] = adj[t][s] = true;
  }
  
  return true;
}

void rec(int curr, int sum, int tail, int group[BUF], int &maxV, int color[BUF]){
  for(int i=0;i<4;i++){
    int toAdd = 0;
    for(int j=0;j<tail;j++){
      int next = group[j];
      if(adj[group[curr]][next] && color[next]==i) goto finish;
      if(adj[group[curr]][next] && color[next]>=0)
        toAdd += (val[color[next]]-val[i])*(val[color[next]]-val[i]);
    }
    color[group[curr]] = i;
    
    if(curr==tail-1)
      maxV = max(maxV,sum+toAdd);
    else 
      rec(curr+1,sum+toAdd,tail,group,maxV,color);
      
    color[group[curr]] = -1;
  finish:;  
  }
}

void dfs(int curr, bool visited[BUF], int &tail, int group[BUF]){
  group[tail++] = curr;
  visited[curr] = true;

  for(int i=0;i<nNode;i++)
    if(!visited[i] && adj[curr][i])
      dfs(i,visited,tail,group);
}

void work(){
  int nGroup = 0, tail[BUF], group[BUF][BUF];
  bool visited[BUF];

  for(int i=0;i<nNode;i++){
    visited[i] = false;
    tail[i] = 0;
  }

  for(int i=0;i<nNode;i++){
    if(visited[i]) continue;
    dfs(i,visited,tail[nGroup],group[nGroup]);
    nGroup++;
  }


  int sum = 0, color[BUF];
  
  for(int i=0;i<nNode;i++) color[i] = -1;
    
  for(int i=0;i<nGroup;i++){
    int maxV = -1;
    rec(0,0,tail[i],group[i],maxV,color);
    sum += maxV;
  }

  cout << sum << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
