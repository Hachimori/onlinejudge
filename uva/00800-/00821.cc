#include<iostream>
#include<cstdio>
using namespace std;
const int BUF = 105, INF = 1<<20;

bool nodeExist[BUF];
int nNode, adj[BUF][BUF];

bool read(){
  nNode = 0;
  memset(nodeExist,0,sizeof(nodeExist));
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      adj[i][j] = i==j ? 0 : INF;
  while(1){
    int a, b;
    cin >> a >> b;
    if(a==0 && b==0) break;
    adj[a-1][b-1] = 1;
    if(!nodeExist[a-1]) nodeExist[a-1] = true, nNode++;
    if(!nodeExist[b-1]) nodeExist[b-1] = true, nNode++;
  }
  return nNode>0;
}

void work(int cases){
  for(int k=0;k<BUF;k++)
    for(int i=0;i<BUF;i++)
      for(int j=0;j<BUF;j++)
        adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
  
  double ans = 0;
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      if(nodeExist[i] && nodeExist[j])
        ans += adj[i][j];

  printf("Case %d: average length between pages = %.3lf clicks\n",cases,ans/(nNode*(nNode-1)));
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  return 0;
}
