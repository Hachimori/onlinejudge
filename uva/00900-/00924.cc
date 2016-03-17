#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int BUF = 2505, QUERY = 65;

int nNode;
vector<int> adj[BUF];
int nQuery, query[QUERY];

void read(){
  cin >> nNode;
  for(int i=0;i<nNode;i++){
    int nEdge;
    cin >> nEdge;
    for(int j=0;j<nEdge;j++){
      int v;
      cin >> v;
      adj[i].push_back(v);
    }
  }
  cin >> nQuery;
  for(int i=0;i<nQuery;i++) cin >> query[i];
}

void bfs(int init){
  int visited[BUF];
  queue<int> Q;

  memset(visited,-1,sizeof(visited));
  Q.push(init);
  visited[init] = 0;
  
  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();
    for(int i=0;i<adj[curr].size();i++)
      if(visited[adj[curr][i]]==-1){
        visited[adj[curr][i]] = visited[curr]+1;
        Q.push(adj[curr][i]);
      }
  }

  int cnt[BUF]={0};
  for(int i=0;i<nNode;i++)
    if(visited[i]>=0)
      cnt[visited[i]]++;

  int maxV = 0, maxIdx;
  for(int i=1;i<nNode;i++)
    if(maxV<cnt[i]){
      maxV = cnt[i];
      maxIdx = i;
    }
  if(maxV==0)
    cout << 0 << endl;
  else
    cout << maxV << ' ' << maxIdx << endl;
}

void work(){
  for(int i=0;i<nQuery;i++) bfs(query[i]);
}

int main(){
  read();
  work();
  return 0;
}
