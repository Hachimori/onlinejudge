#include<iostream>
#include<vector>
#include<queue>
#define BUF 105
#define dst first
#define cost second
using namespace std;
typedef pair<int,int> Edge;

class Data{
public:
  int pos, cost;

  Data(){}
  Data(int p, int c): pos(p), cost(c){}

  bool operator< (const Data &d) const {
    return cost>d.cost;
  }
};

int nNode, src, dst, kth;
vector<Edge> adj[BUF];

bool read(){
  int nEdge;
  cin >> nNode >> nEdge;
  if(nNode==0 && nEdge==0) return false;
  
  for(int i=0;i<nNode;i++)
    adj[i].clear();

  cin >> src >> dst >> kth; 
  src--, dst--;
  
  for(int i=0;i<nEdge;i++){
    int s, t, c;
    cin >> s >> t >> c;
    adj[s-1].push_back(Edge(t-1,c));
  }
  
  return true;
}

int dijkstra(){
  priority_queue<Data> Q;
  int nth[BUF];
  
  Q.push(Data(src,0));
  for(int i=0;i<nNode;i++) nth[i] = 1;
  
  while(!Q.empty()){
    Data curr = Q.top();
    Q.pop();

    if(nth[curr.pos]==kth && curr.pos==dst) return curr.cost;
    if(nth[curr.pos]>kth) continue;

    nth[curr.pos]++;

    for(int i=0;i<adj[curr.pos].size();i++){
      Edge &e = adj[curr.pos][i];
      Q.push(Data(e.dst,curr.cost+e.cost));
    }
  }

  return -1;
}

void work(){
  cout << dijkstra() << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
