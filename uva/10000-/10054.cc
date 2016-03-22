// uva 10054
// Euler Circuit
// http://www.graph-magics.com/articles/euler.php

#include<iostream>
#include<stack>
#include<algorithm>
#include<numeric>

#define EDGE 1005
#define NODE 101

using namespace std;

class Edge{
public:
  int bgn, end;
  
  Edge(){}
  Edge(int b, int e): bgn(b), end(e){}
};

int nEdge;
int adj[NODE][NODE];  // nEdge

void read(){
  for(int i=0;i<NODE;i++)
    for(int j=0;j<NODE;j++)
      adj[i][j] = 0;
  
  cin >> nEdge;

  for(int i=0;i<nEdge;i++){
    int start, end;
    cin >> start >> end;
    start--, end--;

    adj[start][end]++;
    adj[end][start]++;
  }
}

void dfs(int curr, bool visited[], int &nVisited){
  visited[curr] = true;
  
  for(int i=0;i<NODE;i++){
    nVisited += adj[curr][i];
    if(visited[i]) continue;
    if(adj[curr][i]==0) continue;
    dfs(i,visited,nVisited);
  }
}
 
void findEuler(int curr, int cursor, stack<int> &S, Edge order[]){
  for(int i=0;i<NODE;i++){
    if(adj[curr][i]==0) continue;
    adj[curr][i]--;
    adj[i][curr]--;
    S.push(curr);
    findEuler(i,cursor,S,order);
    return;
  }
  
  if(S.empty()) return;
  int next = S.top();
  S.pop();
  
  order[cursor++] = Edge(curr,next);

  findEuler(next,cursor,S,order);
}

void work(int cases){
  cout << "Case #" << cases << endl;
  
  for(int i=0;i<NODE;i++)
    if(accumulate(adj[i],adj[i]+NODE,0)%2==1){
      cout << "some beads may be lost" << endl;
      return;
    }
  
  int startPos;
  for(int i=0;i<NODE;i++)
    for(int j=0;j<NODE;j++)
      if(adj[i][j]!=0)
	startPos=i;
  
  int nVisited = 0;
  bool visited[NODE];
  
  fill(visited,visited+NODE,false);
  
  dfs(startPos,visited,nVisited);
  
  if(nVisited/2!=nEdge){
    cout << "some beads may be lost" << endl;
    return;
  }
  
  int cursor=0;
  stack<int> S;
  Edge order[EDGE];
  findEuler(startPos,cursor,S,order);

  for(int i=0;i<nEdge;i++)
    cout << order[i].bgn+1 << ' ' << order[i].end+1 << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work(i+1);
  }
  
  return 0;
}
