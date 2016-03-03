#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<cctype>
#define BUF 26
using namespace std;

vector<int> node;
vector<int> adj[BUF];

void read(){
  node.clear();
  for(int i=0;i<BUF;i++)
    adj[i].clear();

  while(true){
    string s; cin >> s;
    if(s[0]!='(') break;
    char b, e;
    sscanf(s.c_str(),"(%c,%c)",&b,&e);

    adj[b-'A'].push_back(e-'A');
    adj[e-'A'].push_back(b-'A');
  }
  
  string s; cin >> s;
  for(int i=0;i<s.size();i++)
    if(isalpha(s[i]))
      node.push_back(s[i]-'A');
}

void dfs(int curr, bool visited[BUF]){
  visited[curr] = true;
  for(int i=0;i<adj[curr].size();i++){
    if(visited[adj[curr][i]]) continue;
    dfs(adj[curr][i],visited);
  }
}

void work(){
  int tree = 0, acorn = 0;

  bool visited[BUF];
  for(int i=0;i<node.size();i++) visited[node[i]] = false;
  
  for(int i=0;i<node.size();i++){
    if(visited[node[i]]) continue;
    if(adj[node[i]].size()==0){
      acorn++;
      continue;
    }
    dfs(node[i],visited);
    tree++;
  }

  cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s)." << endl;
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
