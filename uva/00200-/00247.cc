// uva 247
// strongly connected component
// 
// http://www.hgc.jp/~tshibuya/classes/shibuya20050225.pdf

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

#define SIZE 30

using namespace std;

int nNode;
string i2s[SIZE];
bool adj[SIZE][SIZE];

bool read(){
  for(int i=0;i<SIZE;i++)
    for(int j=0;j<SIZE;j++)
      adj[i][j] = false;

  map<string,int> s2i;  
  int nEdge;
  cin >> nNode >> nEdge;
  if(nNode==0 && nEdge==0) return false;
  
  for(int i=0;i<nEdge;i++){
    string src, dst;
    cin >> src >> dst;

    if(!s2i.count(src)){
      int size = s2i.size();
      s2i[src] = size;
      i2s[size] = src;
    }
    
    if(!s2i.count(dst)){
      int size = s2i.size();
      s2i[dst] = size;
      i2s[size] = dst;
    }

    adj[s2i[src]][s2i[dst]] = true;
  }
  
  return true;
}

void dfs(int curr, bool visited[], vector<int> &vec){
  visited[curr] = true;

  for(int i=0;i<nNode;i++){
    if(visited[i] || !adj[curr][i]) continue;
    dfs(i,visited,vec);
  }

  vec.push_back(curr);
}

vector< vector<int> > scc(){
  vector<int> order;
  bool visited[SIZE];

  fill(visited,visited+nNode,false);
  
  for(int i=0;i<nNode;i++){
    if(visited[i]) continue;
    dfs(i,visited,order);
  }
  
  reverse(order.begin(),order.end());
  
  for(int i=0;i<nNode;i++)
    for(int j=i+1;j<nNode;j++)
      swap(adj[i][j],adj[j][i]);
  
  fill(visited,visited+nNode,false);
  
  vector< vector<int> > ret;
  for(int i=0;i<nNode;i++){
    if(visited[order[i]]) continue;
    ret.push_back(vector<int>());
    dfs(order[i],visited,ret.back());
  }

  for(int i=0;i<nNode;i++)
    for(int j=i+1;j<nNode;j++)
      swap(adj[i][j],adj[j][i]);

  return ret;
}

void work(int cases){
  vector< vector<int> > ans = scc();

  cout << "Calling circles for data set " << cases << ":" << endl;

  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      if(j) cout << ", ";
      cout << i2s[ans[i][j]];
    }
    cout << endl;
  }
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work(i+1);
  }
  
  return 0;
}
