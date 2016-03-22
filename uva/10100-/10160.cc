#include<iostream>
#include<vector>
#define BUF 40
#define INF (1<<20)
using namespace std;

int nNode;
vector<int> adj[BUF];

bool read(){
  int nEdge;
  cin >> nNode >> nEdge;
  if(nNode==0 && nEdge==0) return false;

  for(int i=0;i<nNode;i++)
    adj[i].clear();
  
  for(int i=0;i<nEdge;i++){
    int s, t;
    cin >> s >> t; s--; t--;
    adj[s].push_back(t);
    adj[t].push_back(s);
  }
  for(int i=0;i<nNode;i++)
    adj[i].push_back(i);
  
  return true;
}

void dfsSCC(int curr, bool visited[BUF], vector<int> &SCC){
  SCC.push_back(curr);
  visited[curr] = true;
  for(int i=0;i<adj[curr].size();i++){
    if(visited[adj[curr][i]]) continue;
    dfsSCC(adj[curr][i],visited,SCC);
  }
}

vector< vector<int> > getSCC(){
  vector< vector<int> > ret;
  bool visited[BUF];
  
  for(int i=0;i<nNode;i++) visited[i] = false;

  for(int i=0;i<nNode;i++){
    if(visited[i]) continue;
    ret.push_back(vector<int>());
    dfsSCC(i,visited,ret.back());
  }

  return ret;
}

void rec(int idx, int nPut, vector<int> &SCC, bool avail[BUF], int &minV){
  if(minV==nPut) return;

  if(idx==SCC.size()){
    minV = nPut;
    return;
  }

  bool need = true;
  for(int i=0;i<adj[SCC[idx]].size();i++)
    if(avail[adj[SCC[idx]][i]]){
      need = false;
      break;
    }


  if(need){
    for(int i=0;i<adj[SCC[idx]].size();i++){
      avail[adj[SCC[idx]][i]] = true;

      rec(idx+1,nPut+1,SCC,avail,minV);
      
      avail[adj[SCC[idx]][i]] = false;
    }
  }
  else
    rec(idx+1,nPut,SCC,avail,minV);
}

void work(){
  vector< vector<int> > SCC = getSCC();

  int ans = 0;
  for(int i=0;i<SCC.size();i++){
    int minV = INF;
    bool avail[BUF];
    for(int j=0;j<nNode;j++) avail[j] = false;
    rec(0,0,SCC[i],avail,minV);
    ans += minV;
  }

  cout << ans << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
