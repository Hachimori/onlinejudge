#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define LEFT 105
#define RIGHT 505
using namespace std;

class Edge{
public:
  int src, dst;
  
  Edge(){}
  Edge(int src, int dst): src(src), dst(dst){}
};

int nNode, nEdge;
vector<Edge> dir, undir;

void read(){
  cin >> nNode >> nEdge;
  
  dir.clear(),undir.clear();

  for(int i=0;i<nEdge;i++){
    int s, t;
    char c;
    cin >> s >> t >> c;
    s--, t--;
    (c=='D'?dir:undir).push_back(Edge(s,t));
  }
}

bool augment(int curr, int R2L[], bool visited[], bool adj[][RIGHT]){
  if(curr==-1) return true;
  
  for(int i=0;i<undir.size();i++){
    if(!adj[curr][i] || visited[i]) continue;
    visited[i] = true;
    if(augment(R2L[i],R2L,visited,adj)){
      R2L[i] = curr;
      return true;
    }
  }
  
  return false;
}

// ’H‚Á‚½ƒm[ƒh‚ª‹tŒü‚«‚É•Û‘¶‚³‚ê‚Ä‚¢‚é‚±‚Æ‚É’ˆÓ
void findEuler(int curr, vector<int> &order, int adj[][LEFT]){
  for(int i=0;i<nNode;i++){
    while(adj[curr][i]>0){
      adj[curr][i]--;
      findEuler(i,order,adj);
    }
  }
  order.push_back(curr);
}

bool connected(){
  bool dp[LEFT][LEFT];
  
  for(int i=0;i<nNode;i++){
    for(int j=0;j<nNode;j++)
      dp[i][j] = false;
    dp[i][i] = true;
  }

  for(int i=0;i<dir.size();i++)
    dp[dir[i].src][dir[i].dst] = true;
  
  for(int i=0;i<undir.size();i++){
    dp[undir[i].src][undir[i].dst] = true;
    dp[undir[i].dst][undir[i].src] = true;
  }

  for(int k=0;k<nNode;k++)
    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
	dp[i][j] = (dp[i][j] || (dp[i][k]&&dp[k][j]));

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      if(!dp[i][j]) return false;

  return true;
}

void work(){
  if(!connected()) {
    cout << "No euler circuit exist" << endl;
    return;
  }
  
  int degree[LEFT];
  fill(degree,degree+nNode,0);
  for(int i=0;i<dir.size();i++){
    degree[dir[i].src]++;
    degree[dir[i].dst]++;
  }
  for(int i=0;i<undir.size();i++){
    degree[undir[i].src]++;
    degree[undir[i].dst]++;
  }
  
  for(int i=0;i<nNode;i++)
    if(degree[i]%2==1){
      cout << "No euler circuit exist" << endl;
      return;    
    }
  
  int need[LEFT];
  for(int i=0;i<nNode;i++)
    need[i] = degree[i]/2;

  for(int i=0;i<dir.size();i++)
    if(--need[dir[i].dst]<0){
      cout << "No euler circuit exist" << endl;
      return;
    }

  
  bool adj[LEFT][RIGHT]; // ¶node, ‰Eedge ‚Ì“ñ•”ƒOƒ‰ƒt
  for(int i=0;i<nNode;i++)
    for(int j=0;j<undir.size();j++)
      adj[i][j] = false;

  for(int i=0;i<undir.size();i++){
    adj[undir[i].src][i] = true;
    adj[undir[i].dst][i] = true;
  }
  
  int R2L[RIGHT];
  fill(R2L,R2L+undir.size(),-1);

  for(int i=0;i<nNode;i++){
    for(int j=0;j<need[i];j++){
      bool visited[RIGHT];
      fill(visited,visited+undir.size(),false);
      if(!augment(i,R2L,visited,adj)){
	cout << "No euler circuit exist" << endl;
	return;
      }
    }
  }
  

  int cnt[LEFT][LEFT];
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      cnt[i][j] = 0;

  for(int i=0;i<dir.size();i++)
    cnt[dir[i].src][dir[i].dst]++;
  
  for(int i=0;i<undir.size();i++)
    if(R2L[i]==undir[i].dst)
      cnt[undir[i].src][undir[i].dst]++;
    else
      cnt[undir[i].dst][undir[i].src]++;

  vector<int> order; 
  findEuler(0,order,cnt);
  reverse(order.begin(),order.end());
  
  for(int i=0;i<order.size();i++){
    if(i) cout << ' ';
    cout << order[i]+1;
  }cout << endl;
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
