#include<iostream>
#include<queue>
#include<map>
#include<string>
#include<vector>
using namespace std;
const int BUF = 1005;

map<string,int> n2i;
map<int,string> i2n;
int nNode, src, dst;
bool adj[BUF][BUF];

bool read(){
  memset(adj,0,sizeof(adj));
  n2i.clear();
  i2n.clear();
  nNode = 0;

  int nEdge;
  if(!(cin >> nEdge)) return false;
  
  for(int i=0;i<=nEdge;i++){
    string s, t;
    cin >> s >> t;
    if(!n2i.count(s)){
      n2i[s] = nNode;
      i2n[nNode] = s;
      nNode++;
    }
    if(!n2i.count(t)){
      n2i[t] = nNode;
      i2n[nNode] = t;
      nNode++;
    }
    if(i<nEdge)
      adj[n2i[s]][n2i[t]] = adj[n2i[t]][n2i[s]] = true;
    else
      src = n2i[s], dst = n2i[t];
  }
  nNode = n2i.size();

  return true;
}

void work(){
  int pi[BUF];
  queue<int> Q;

  memset(pi,-1,sizeof(pi));
  
  pi[src] = -2;
  Q.push(src);
  
  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();
    for(int i=0;i<nNode;i++)
      if(pi[i]==-1 && adj[curr][i]){
        pi[i] = curr;
        Q.push(i);
      }
  }

  if(pi[dst]==-1)
    cout << "No route" << endl;
  else{
    vector<int> path;
    for(int i=dst;i>=0;i=pi[i]) path.push_back(i);
    for(int i=path.size()-1;i>0;i--)
      cout << i2n[path[i]] << ' ' << i2n[path[i-1]] << endl;
  }
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  return 0;
}
