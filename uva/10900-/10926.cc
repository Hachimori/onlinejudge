#include<iostream>
#include<numeric>
using namespace std;
const int BUF = 105;


int nNode, adj[BUF][BUF];

bool read(){
  memset(adj,0,sizeof(adj));
  cin >> nNode;
  if(nNode==0) return false;
  for(int i=0;i<nNode;i++){
    int t;
    cin >> t;
    for(int j=0;j<t;j++){
      int dst;
      cin >> dst;
      adj[i][dst-1] = 1;
    }
  }
  return true;
}


void work(){
  for(int k=0;k<nNode;k++)
    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
        adj[i][j] |= adj[i][k]&adj[k][j];

  int maxV = -1, maxP;
  for(int i=0;i<nNode;i++)
    if(maxV<accumulate(adj[i],adj[i]+nNode,0)){
      maxV = accumulate(adj[i],adj[i]+nNode,0);
      maxP = i;
    }
  cout << maxP+1 << endl;
}


int main(){
  while(read()) work();
  return 0;
}
