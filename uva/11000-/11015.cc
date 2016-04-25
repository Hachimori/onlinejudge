#include<iostream>
#include<string>
#include<numeric>
#include<algorithm>
#define NODE 30
#define INF (1<<29)
using namespace std;

int nNode, adj[NODE][NODE];
string name[NODE];

bool read(){
  int nEdge;
  cin >> nNode >> nEdge;
  if(nNode==0 && nEdge==0) return false;

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adj[i][j] = INF;

  for(int i=0;i<nNode;i++)
    cin >> name[i];

  for(int i=0;i<nEdge;i++){
    int s, t, c;
    cin >> s >> t >> c;
    s--, t--;
    adj[s][t] = min(adj[s][t],c);
    adj[t][s] = min(adj[t][s],c);
  }
      
  return true;
}

void warshall(int cost[][NODE]){
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      cost[i][j] = adj[i][j];

  for(int i=0;i<nNode;i++)
    cost[i][i] = 0;

  for(int k=0;k<nNode;k++)
    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
	cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
}

void work(int cases){
  int cost[NODE][NODE];
  warshall(cost);

  int minV = INF, ans;
  for(int i=0;i<nNode;i++){
    int sum = accumulate(cost[i],cost[i]+nNode,0);

    if(minV>sum){
      minV = sum;
      ans = i;
    }
  }

  cout << "Case #" << cases << " : " << name[ans] << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
