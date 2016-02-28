#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
const int BUF = 1000, YET = -1, VISITED = -2, ERROR = -3;

int nNode, limit, cost[BUF];
char type[BUF];
vector<int> adj[BUF];

void read(){
  for(int i=0;i<BUF;i++)
    adj[i].clear();

  cin >> limit >> nNode;
  for(int i=0;i<nNode;i++)
    cin >> type[i] >> cost[i];

  int nEdge;
  cin >> nEdge;

  for(int i=0;i<nEdge;i++){
    int s, t;
    cin >> s >> t;
    adj[s].push_back(t);
  }
}

int rec(int curr, int visited[BUF], bool &cycle){
  int &ret = visited[curr];
  if(ret==VISITED){
    cycle = true;
    return -(1<<20);
  }
  if(ret!=YET) return ret;
  ret = VISITED;
  int maxV = 0;
  for(int i=0;i<adj[curr].size();i++)
    if(type[adj[curr][i]]=='a')
      maxV = max(maxV,rec(adj[curr][i],visited,cycle));
  return ret = maxV+cost[curr];
}

void work(){
  bool cycle = false;
  int ans = 0, visited[BUF];
  for(int i=0;i<nNode;i++) visited[i] = YET;

  for(int i=0;i<nNode;i++)
    ans = max(ans,rec(i,visited,cycle));
  
  if(cycle)
    cout << "Circuit contains cycle." << endl;
  else if(ans>limit)
    cout << "Clock period exceeded." << endl;
  else
    cout << "Synchronous design. Maximum delay: " << ans << '.' << endl;
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
