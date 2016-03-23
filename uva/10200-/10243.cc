// minimum vertex cover in a tree
//
// IHIのライブラリを参照した。

#include<iostream>
#include<set>
#define BUF 1005
using namespace std;

int nNode, degree[BUF];
set<int> adj[BUF];

bool read(){
  cin >> nNode;
  if(nNode==0) return false;
  
  for(int i=0;i<nNode;i++) adj[i].clear();
  
  for(int i=0;i<nNode;i++){
    int nEdge;  cin >> nEdge;
    for(int j=0;j<nEdge;j++){
      int t;
      cin >> t;
      adj[i].insert(t-1);
    }
  }
  
  return true;
}

typedef set<int>::iterator iter;

void eraseVec(int v, int &nDel){
  for(iter i=adj[v].begin();i!=adj[v].end();i++){
    adj[*i].erase(v);
    if(adj[*i].size()==0) nDel++;
  }
  adj[v].clear();
  nDel++;
}

void work(){
  int cnt = 0, nDel = 0;

  if(nNode==1){
     cout << 1 << endl;
     return;
  }

  while(nNode-nDel>0){
    for(int i=0;i<nNode;i++){
      if(adj[i].size()!=1) continue;
      eraseVec(*adj[i].begin(),nDel);
      cnt++;
    }
  }

  cout << cnt << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
