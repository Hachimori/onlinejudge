// uva 10731
// strongly connected component
// 
// http://www.hgc.jp/~tshibuya/classes/shibuya20050225.pdf

#include<iostream>
#include<vector>
#include<algorithm>

#define SIZE 126

using namespace std;

bool adj[SIZE][SIZE], avail[SIZE];

bool read(){
  int nQ;
  cin >> nQ;

  if(nQ==0) return false;

  for(int i=0;i<SIZE;i++)
    for(int j=0;j<SIZE;j++)
      adj[i][j] = avail[i] = false;
  
  for(int i=0;i<nQ;i++){
    char choice[5], ans;

    for(int j=0;j<5;j++)
      cin >> choice[j];
    cin >> ans;

    for(int j=0;j<5;j++){
      adj[ans][choice[j]] = true;
      avail[choice[j]] = true;
    }
    avail[ans] = true;
  }
  
  return true;
}

void dfs(int curr, bool visited[], vector<int> &vec){
  visited[curr] = true;

  for(int i=0;i<SIZE;i++){
    if(visited[i]) continue;
    if(!adj[curr][i]) continue;

    dfs(i,visited,vec);
  }

  vec.push_back(curr);
}

vector< vector<int> > scc(){
  vector<int> order;
  bool visited[SIZE];

  fill(visited,visited+SIZE,false);
  
  for(int i=0;i<SIZE;i++){
    if(visited[i] || !avail[i]) continue;
    dfs(i,visited,order);
  }
  
  reverse(order.begin(),order.end());
  
  for(int i=0;i<SIZE;i++)
    for(int j=i+1;j<SIZE;j++)
      swap(adj[i][j],adj[j][i]);
  
  fill(visited,visited+SIZE,false);
  
  vector< vector<int> > ret;
  for(int i=0;i<order.size();i++){
    if(visited[order[i]]) continue;
    vector<int> toPush;

    dfs(order[i],visited,toPush);
    
    ret.push_back(toPush);
  }

  return ret;
}

void work(){
  vector< vector<int> > ans = scc();
  
  for(int i=0;i<ans.size();i++)
    sort(ans[i].begin(),ans[i].end());
  sort(ans.begin(),ans.end());

  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      if(j!=0) cout << ' ';
      cout << (char)ans[i][j];
    }
    cout << endl;
  }
}

int main(){
  for(int i=0;read();i++){
    if(i!=0) cout << endl;
    work();
  }

  return 0;
}
