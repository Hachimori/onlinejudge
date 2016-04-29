#include<iostream>
#include<vector>
using namespace std;
const int BUF = 505, INF = 1<<28;

int nNode, src, dst, adj[2][BUF][BUF];

bool read(){
  if(!(cin >> nNode >> src >> dst)) return false;
  src--, dst--;
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      adj[0][i][j] = adj[1][i][j] = INF;
  for(int i=0;i<2;i++){
    int nEdge;
    cin >> nEdge;
    for(int j=0;j<nEdge;j++){
      int s, t, c;
      cin >> s >> t >> c;
      s--, t--;
      adj[i][s][t] = adj[i][t][s] = c;
    }
  }
  return true;
}

void work(){
  int cost[2][BUF];
  bool visited[2][BUF];
  pair<int,int> pi[2][BUF];

  for(int i=0;i<BUF;i++){
    cost[0][i] = cost[1][i] = INF;
    visited[0][i] = visited[1][i] = false;
  }

  cost[0][src] = 0;
  pi[0][src] = make_pair(-1,-1);

  while(1){
    int minV = INF;
    pair<int,int> minPos;
    for(int i=0;i<2;i++)
      for(int j=0;j<nNode;j++)
        if(minV>cost[i][j] && !visited[i][j]){
          minV = cost[i][j];
          minPos = make_pair(i,j);
        }

    if(minV==INF) break;
    visited[minPos.first][minPos.second] = true;
    
    for(int i=0;i<2;i++)
      if(!(minPos.first && i==1))
        for(int j=0;j<nNode;j++)
          if(cost[max(i,minPos.first)][j]>adj[i][minPos.second][j]+minV){
            cost[max(i,minPos.first)][j] = adj[i][minPos.second][j]+minV;
            pi[max(i,minPos.first)][j] = minPos;
          }
  }

  int ticketPos = -1;
  vector<int> path;
  pair<int,int> pos = make_pair(cost[0][dst]>cost[1][dst],dst);
  while(pos!=make_pair(-1,-1)){
    path.push_back(pos.second);
    if(ticketPos==-1 && pos.first!=pi[pos.first][pos.second].first) ticketPos = pi[pos.first][pos.second].second;
    pos = pi[pos.first][pos.second];
  }

  for(int i=path.size()-1;i>=0;i--){
    if(i!=path.size()-1) cout << ' ';
    cout << path[i]+1;
  }
  cout << endl;
  if(ticketPos==-1)
    cout << "Ticket Not Used" << endl;
  else
    cout << ticketPos+1 << endl;
  cout << min(cost[0][dst],cost[1][dst]) << endl;
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  return 0;
}
