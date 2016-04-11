// uva 10510
// 有向グラフがcactusかどうかの判定
//
// 1, グラフは強連結であり、
// 2, それぞれの頂点のindegreeとoutdegreeの数が等しく、
// 3, forward edgeとcross edgeが無く、
// 4, 最大で1つのback edgeを持つ。
// 
//
//
// 有向グラフがcactusかどうかの判定
// http://online-judge.uva.es/board/viewtopic.php?t=3362&highlight=10510
//
// forward edge, cross edge, back edge の見つけ方
// http://www.cs.unc.edu/~plaisted/comp122/20-graph2.ppt

#include<iostream>
#include<vector>
#include<algorithm>

#define YET 0
#define VISITED 1
#define FINISHED 2
#define SIZE 10005

using namespace std;

int nNode, nEdge;
vector< vector<int> > adj;

void read(){
  cin >> nNode >> nEdge;
  
  adj.assign(nNode,vector<int>());

  for(int i=0;i<nEdge;i++){
    int src, dst;
    cin >> src >> dst;

    adj[src].push_back(dst);
  }
}

void dfs(int curr, bool visited[], vector<int> &vec){
  visited[curr] = true;

  for(int i=0;i<adj[curr].size();i++){
    if(visited[adj[curr][i]]) continue;
    dfs(adj[curr][i],visited,vec);
  }

  vec.push_back(curr);
}

vector< vector<int> > scc(){
  vector<int> order;
  bool visited[SIZE];

  fill(visited,visited+nNode,false);
  
  for(int i=0;i<nNode;i++){
    if(visited[i]) continue;
    dfs(i,visited,order);
  }
  
  reverse(order.begin(),order.end());
  
  vector< vector<int> > next;
  next.assign(nNode,vector<int>());
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<adj[i].size();j++)
      next[adj[i][j]].push_back(i);
  
  swap(next,adj);
  
  fill(visited,visited+nNode,false);
  
  vector< vector<int> > ret;
  for(int i=0;i<nNode;i++){
    if(visited[order[i]]) continue;
    vector<int> toPush;
    dfs(order[i],visited,toPush);
    ret.push_back(toPush);
  }
  
  swap(next,adj);

  return ret;
}

bool isCactus(int curr, int stat[]){
  stat[curr] = VISITED;

  int nBack = 0;
  for(int i=0;i<adj[curr].size();i++){
    if(nBack==2) return false;
    
    switch(stat[adj[curr][i]]){
    case YET:
      // E(curr,adj[curr][i]) is tree edge
      if(!isCactus(adj[curr][i],stat)) return false;
      break;

    case VISITED:
      // E(curr,adj[curr][i]) is back edge
      nBack++;
      break;

    case FINISHED:
      // E(curr,adj[curr][i]) is forward edge or cross edge
      return false;
    }
  }

  stat[curr] = FINISHED;
  
  return true;
}

void work(){
  vector< vector<int> > ret = scc();
  
  if(ret.size()==0 || nNode==1)
    cout << "YES" << endl;
  else if(ret.size()>1)
    cout << "NO" << endl;
  else {
    int nParent[SIZE], nChild[SIZE];
    fill(nParent,nParent+nNode,0);
    fill(nChild,nChild+nNode,0);
    
    for(int i=0;i<nNode;i++)
      for(int j=0;j<adj[i].size();j++){
	nParent[adj[i][j]]++;
	nChild[i]++;
      }
    
    for(int i=0;i<nNode;i++)
      if(nParent[i]!=nChild[i]){
	cout << "NO" << endl;
	return;
      }
    
    int stat[SIZE];
    fill(stat,stat+nNode,YET);

    if(isCactus(0,stat))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
