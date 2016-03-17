#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
const int BUF = 125;


int nNode, adj[BUF][BUF];
map<string,int> n2i;
map<int,string> i2n;

void read(){
  memset(adj,0,sizeof(adj));
  n2i.clear();
  i2n.clear();

  cin >> nNode;
  for(int i=0;i<nNode;i++){
    string s;
    cin >> s;
    n2i[s] = i;
    i2n[i] = s;
  }

  int nEdge;
  cin >> nEdge;
  for(int i=0;i<nEdge;i++){
    string srcS;
    cin >> srcS;
    int nAdj;
    cin >> nAdj;
    for(int j=0;j<nAdj;j++){
      string dstS;
      cin >> dstS;
      adj[n2i[srcS]][n2i[dstS]] = 1;
    }
  }
}


void work(){
  for(int k=0;k<nNode;k++)
    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
        adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);

  map<string,set<string> > ans;
  for(int self=0;self<nNode;self++)
    for(int opp=0;opp<nNode;opp++){
      if(!adj[self][opp]) continue;
      bool ok = true;
      for(int mid=0;mid<nNode;mid++)
        if(adj[self][mid] && adj[mid][opp])
          ok = false;

      if(ok){
        if(!ans.count(i2n[self])) ans[i2n[self]] = set<string>();
        ans[i2n[self]].insert(i2n[opp]);
      }
    }
  
  for(map<string,set<string> >::iterator ai=ans.begin();ai!=ans.end();ai++){
    cout << ai->first << ' ' << ai->second.size();
    for(set<string>::iterator si=ai->second.begin();si!=ai->second.end();si++)
      cout  << ' ' << *si;
    cout << endl;
  }
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
