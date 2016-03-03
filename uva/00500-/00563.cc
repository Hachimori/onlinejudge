// queue をつかうと 2.252
// stack をつかうと 1.000

#include<iostream>
#include<vector>
#include<stack>
#define NODE 5010
#define EDGE 2000000
using namespace std;

class Edge{
public:
  int dst, cap;
  
  Edge(){}
  Edge(int d, int c): dst(d), cap(c){}
};

int nNode, row, col, nSrc, SRC, DST;
vector<Edge> adj[NODE];

void read(){
  int nEdge;
  cin >> col >> row >> nSrc;

  for(int i=0;i<NODE;i++)
    adj[i].clear();
  
  int SHIFT = row*col;
  SRC = row*col*2;
  DST = row*col*2+1;
  nNode = row*col*2+2;
  
  const static int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      int cur = i*col+j;
      adj[cur].push_back(Edge(SHIFT+cur,1));
      adj[SHIFT+cur].push_back(Edge(cur,0));
      
      for(int k=0;k<4;k++){
	int next = (i+dr[k])*col+(j+dc[k]);
	if(!(0<=i+dr[k] && i+dr[k]<row && 0<=j+dc[k] && j+dc[k]<col)){
	  adj[SHIFT+cur].push_back(Edge(DST,1));
	  adj[DST].push_back(Edge(SHIFT+cur,0));
	}
	else{
	  adj[SHIFT+cur].push_back(Edge(next,1));
	  adj[next].push_back(Edge(SHIFT+cur,0));
	}
      }
    }
  
  for(int i=0;i<nSrc;i++){
    int c, r, cur;
    cin >> c >> r;
    cur = (r-1)*col+(c-1);
    
    adj[SRC].push_back(Edge(cur,1));
    adj[cur].push_back(Edge(SRC,0));
  }
}

bool augment(int pi[]){
  stack<int> Q;
  
  fill(pi,pi+nNode,-1);
  pi[SRC] = -2;
  Q.push(SRC);

  while(!Q.empty() && pi[DST]==-1){
    int curr = Q.top();
    Q.pop();
    for(int i=0;i<adj[curr].size();i++){
      Edge &e = adj[curr][i];
      if(e.cap<=0) continue;
      if(pi[e.dst]!=-1) continue;
      Q.push(e.dst);
      pi[e.dst] = curr;
    }
  }
  
  return pi[DST]!=-1;
}

int maxFlow(){
  int sum = 0, pi[NODE];

  while(augment(pi)){
    for(int cur=DST;pi[cur]>=0;cur=pi[cur]){
      for(int j=0;j<adj[cur].size();j++)
	if(adj[cur][j].dst==pi[cur]){
	  adj[cur][j].cap++;
	  break;
	}
      
      for(int j=0;j<adj[pi[cur]].size();j++)
	if(adj[pi[cur]][j].dst==cur){
	  adj[pi[cur]][j].cap--;
	  break;
	}
    }
    sum++;
  }
  
  return sum;
}

void work(){
  cout << (maxFlow()==nSrc ? "possible" : "not possible") << endl;
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
