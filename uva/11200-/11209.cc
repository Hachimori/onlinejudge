#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define NODE 205
#define INF (1<<20)
using namespace std;

int nNode;

class Data{
public:
  int nVisit, order[NODE], cost, curr;
  bool visited[NODE];
  
  bool operator< (const Data &d) const {
    return cost>d.cost;
  }
};

int src, dst;
int adj[NODE][NODE];

bool read(){
  for(int i=0;i<NODE;i++)
    for(int j=0;j<NODE;j++)
      adj[i][j] = INF;

  int nEdge;
  if(!(cin >> nNode >> nEdge >> src >> dst)) return false;
  src--, dst--;

  for(int i=0;i<nEdge;i++){
    int s, t, c;
    cin >> s >> t >> c;
    s--, t--;
    adj[s][t] = adj[t][s] = min(adj[s][t],c);
  }
  
  return true;
}

Data dijkstra(){
  priority_queue<Data> Q;
  Data init;
  
  init.nVisit = 1;
  init.order[0] = src;
  init.curr = src;
  init.cost = 0;
  for(int i=0;i<nNode;i++) init.visited[i] = false;
  init.visited[src] = true;
  
  Q.push(init);
  
  while(!Q.empty()){
    Data curr = Q.top();
    Q.pop();
    
    if(curr.curr==dst){
      if(curr.cost%2==1) continue;

      for(int i=0,sum=0;sum<=curr.cost/2;i++){
	sum += adj[curr.order[i]][curr.order[i+1]];
	if(sum==curr.cost/2)
	  return curr;
      }
      continue;
    }
    
    for(int i=0;i<nNode;i++){
      if(Q.size()>=10000) continue;
      if(adj[curr.curr][i]==INF) continue;
      if(curr.visited[i]) continue;

      Data next = curr;
      next.curr = i;
      next.visited[i] = true;
      next.cost += adj[curr.curr][i];
      next.order[next.nVisit++] = i;

      Q.push(next);
    }
  }
}

void work(int cases){
  Data ret = dijkstra();

  cout << "Case " << cases << ": " << ret.cost/2 << endl;
  
  vector<int> A, B;
  for(int i=0,sum=0;i<ret.nVisit;i++){
    if(sum<=ret.cost/2){
      A.push_back(ret.order[i]);
      if(sum==ret.cost/2) B.push_back(ret.order[i]);
      sum += adj[ret.order[i]][ret.order[i+1]];
    }
    else 
      B.push_back(ret.order[i]);
  }
  
  reverse(B.begin(),B.end());

  cout << A.size();
  for(int i=0;i<A.size();i++)
    cout << ' ' << A[i]+1;
  cout << endl;

  cout << B.size();
  for(int i=0;i<B.size();i++)
    cout << ' ' << B[i]+1;
  cout << endl;
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work(i+1);
  }
  
  return 0;
}
