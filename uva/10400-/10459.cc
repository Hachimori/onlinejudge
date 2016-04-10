#include<iostream>
#include<vector>
#include<algorithm>
#define BUF 5005
#define INF (1<<20)
using namespace std;

int nNode;
vector<int> adj[BUF];

bool read(){
  for(int i=0;i<BUF;i++) adj[i].clear();

  if(!(cin >> nNode)) return false;

  for(int i=0;i<nNode;i++){
    int nEdge;
    cin >> nEdge;
    for(int j=0;j<nEdge;j++){
      int dst; cin >> dst;
      adj[i].push_back(dst-1);
    }
  }
  
  return true;
}

void dfs(int curr, int dist[BUF]){
  for(int i=0;i<adj[curr].size();i++){
    int next = adj[curr][i];
    if(dist[next]!=INF) continue;
    dist[next] = dist[curr]+1;
    dfs(next,dist);
  }
}

void work(){
  vector<int> best, worst;

  // calc worst
  for(int i=0;i<2;i++){
    int dist[BUF], init = (i==0?0:worst[0]);
    for(int j=0;j<nNode;j++) dist[j] = INF;
    dist[init] = 0;
    
    dfs(init,dist);
    
    int maxV = *max_element(dist,dist+nNode);
    for(int j=0;j<nNode;j++)
      if(maxV==dist[j])
        worst.push_back(j);
  }

  sort(worst.begin(),worst.end());
  worst.erase(unique(worst.begin(),worst.end()),worst.end());
  
  // calc best
  int maxV[BUF];
  for(int i=0;i<nNode;i++) maxV[i] = 0;
  
  for(int i=0;i<worst.size();i++){
    int dist[BUF];
    for(int j=0;j<nNode;j++) dist[j] = INF;
    dist[worst[i]] = 0;

    dfs(worst[i],dist);

    for(int j=0;j<nNode;j++)
      maxV[j] = max(maxV[j],dist[j]);
  }
  
  int minV = *min_element(maxV,maxV+nNode);
  for(int i=0;i<nNode;i++)
    if(minV==maxV[i])
      best.push_back(i);
  
  cout << "Best Roots  :";
  for(int i=0;i<best.size();i++)
    cout << ' ' << best[i]+1;
  cout << endl;

  cout << "Worst Roots :";
  for(int i=0;i<worst.size();i++)
    cout << ' ' << worst[i]+1;
  cout << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
