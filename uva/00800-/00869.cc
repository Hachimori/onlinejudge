#include<iostream>
using namespace std;
const int BUF = 128;

int adj[2][BUF][BUF];

void read(){
  memset(adj,0,sizeof(adj));
  for(int k=0;k<2;k++){
    int nEdge;
    cin >> nEdge;
    for(int i=0;i<nEdge;i++){
      char s, t;
      cin >> s >> t;
      adj[k][s][t] = true;
    }
  }
}

void work(){
  for(int l=0;l<2;l++)
    for(int k=0;k<BUF;k++)
      for(int i=0;i<BUF;i++)
        for(int j=0;j<BUF;j++)
          adj[l][i][j] |= adj[l][i][k]&adj[l][k][j];

  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      if(adj[0][i][j]!=adj[1][i][j]){
        cout << "NO" << endl;
        return;
      }
  cout << "YES" << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
