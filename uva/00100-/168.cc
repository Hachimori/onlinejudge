#include<iostream>
#include<vector>
#include<numeric>
#define BUF 26
using namespace std;

int initMino, initThes, kth;
vector<int> adj[BUF];

bool read(){
  for(int i=0;i<BUF;i++) adj[i].clear();
  
  while(true){
    char src;
    cin >> src;
    if(src=='#') return false;

    char dst; cin >> dst; // dummy
    while(true){
      cin >> dst;
      if(dst==';') break;
      if(dst=='.') goto _finish;
      adj[src-'A'].push_back(dst-'A');
    }
  }
  _finish:

  char ch1, ch2;
  cin >> ch1 >> ch2 >> kth;
  initMino = ch1-'A';
  initThes = ch2-'A';

  return true;
}

void rec(int cur, int pre, int nVisited, bool trap[BUF]){
  bool trapped = true;
  for(int i=0;i<adj[cur].size();i++)
    if(adj[cur][i]!=pre && !trap[adj[cur][i]])
      trapped = false;

  if(nVisited%kth==0 && !trapped){
    if(nVisited!=kth) cout << ' ';
    cout << (char)(cur+'A');
    trap[cur] = true;
  }

  for(int i=0;i<adj[cur].size();i++)
    if(adj[cur][i]!=pre && !trap[adj[cur][i]]){
      rec(adj[cur][i],cur,nVisited+1,trap);
      return;
    }

  if(accumulate(trap,trap+BUF,0)!=0) cout << ' ';
  cout << "/" << (char)(cur+'A') << endl;
}

void work(){
  bool trap[BUF];
  for(int i=0;i<BUF;i++) trap[i] = false;

  rec(initMino,initThes,1,trap);
}

int main(){
  while(read())
    work();
  
  return 0;
}
