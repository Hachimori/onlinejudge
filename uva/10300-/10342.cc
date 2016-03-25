#include<iostream>
#include<queue>
#include<cassert>
using namespace std;
const int BUF = 105, INF = 1<<30, QUEUE = 1000;

int nNode, adj[BUF][BUF], nQuery, query[QUEUE][2];

bool read(){
  int nEdge;
  if(!(cin >> nNode >> nEdge)) return false;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adj[i][j] = INF;

  for(int i=0;i<nEdge;i++){
    int s, t, c;
    cin >> s >> t >> c;
    adj[s][t] = adj[t][s] = c;
  }

  cin >> nQuery;
  assert(nQuery<QUEUE);
  for(int i=0;i<nQuery;i++)
    cin >> query[i][0] >> query[i][1];
  
  return true;
}

void dijkstra(int s, int t){
  int cntNth[BUF];
  int ans[BUF][BUF]; // ans[nth][node]: the cost of $nth shortest path from $s to $node
  priority_queue<int,vector<int>,greater<int> > costs[BUF];

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      ans[i][j] = INF;
  
  memset(cntNth,0,sizeof(cntNth));
  costs[s].push(0);

  while(true){
    int minIdx, minV = INF;
    for(int i=0;i<nNode;i++)
      if(!costs[i].empty() && minV>costs[i].top()){
        minV = costs[i].top();
        minIdx = i;
      }

    if(minV==INF) break;
    costs[minIdx].pop();
    
    // delete following line, if the same nth minimum cost must be ommited
    while(!costs[minIdx].empty() && costs[minIdx].top()==minV) costs[minIdx].pop(); 

    if(cntNth[minIdx]==2) continue; // change "2" to $i to get $i th shortest path's cost (i>2)
    ans[cntNth[minIdx]][minIdx] = minV;
    cntNth[minIdx]++;

    for(int i=0;i<nNode;i++)
      if(adj[minIdx][i]!=INF && cntNth[i]<2) // change "2" to $i to get $i th shortest path's cost (i>2)
        costs[i].push(minV+adj[minIdx][i]);
  }

  if(ans[1][t]==INF)
    cout << '?' << endl;
  else
    cout << ans[1][t] << endl;
}

void work(int cases){
  cout << "Set #" << cases << endl;
  for(int i=0;i<nQuery;i++)
    dijkstra(query[i][0],query[i][1]);
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  return 0;
}

