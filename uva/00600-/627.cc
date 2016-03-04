#include<iostream>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;
const int BUF = 305, QUERY = 100000;

int nNode, adj[BUF][BUF], nQuery, query[QUERY][2];

bool read(){
  if(!(cin >> nNode)) return false;
  string dummy; getline(cin,dummy);

  memset(adj,0,sizeof(adj));
  for(int i=0;i<nNode;i++){
    string str; getline(cin,str);
    for(int i=0;i<str.size();i++) if(!isdigit(str[i])) str[i] = ' ';
    stringstream in(str);
    int src, dst;
    in >> src;
    while(in >> dst) adj[src-1][dst-1] = 1;
  }
 
  cin >> nQuery;
  for(int i=0;i<nQuery;i++){
    cin >> query[i][0] >> query[i][1];
    query[i][0]--, query[i][1]--;
  }
}


void bfs(int src, int dst){
  int pi[BUF]={};
  queue<int> Q;

  memset(pi,-1,sizeof(pi));
  pi[src] = -2;
  Q.push(src);

  while(!Q.empty()){
    int cur = Q.front();
    Q.pop();

    for(int i=0;i<nNode;i++){
      if(!adj[cur][i] || pi[i]!=-1) continue;
      pi[i] = cur;
      Q.push(i);
    }
  }

  if(pi[dst]==-1) 
    cout << "connection impossible" << endl;
  else{
    vector<int> ans(1,dst);
    int cur = dst;
    while(pi[cur]>=0){
      ans.push_back(pi[cur]);
      cur = pi[cur];
    }
    for(int i=0;i<ans.size();i++){
      if(i) cout << ' ';
      cout << ans[ans.size()-i-1]+1;
    }
    cout << endl;
  }
}


void work(){
  cout << "-----" << endl;
  for(int i=0;i<nQuery;i++)
    bfs(query[i][0],query[i][1]);
}


int main(){
  while(read()) work();
  return 0;
}
