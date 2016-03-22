#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>
#define INF (1<<30)
#define CITY 105
using namespace std;

class Data{
public:
  int pos, time, cost;

  Data(){}
  Data(int p, int t, int c): pos(p), time(t), cost(c){}

  bool operator< (const Data &d) const {
    return cost>d.cost;
  }
};

class Edge{
public:
  int dst, bgn, end;

  Edge(){}
  Edge(int d, int b, int e): dst(d), bgn(b), end(e){}
};

int init, goal;
vector<Edge> adj[CITY];
map<string,int> n2i;

void read(){
  for(int i=0;i<CITY;i++) adj[i].clear();
  n2i.clear();
  
  int nEdge;
  cin >> nEdge;

  for(int i=0;i<nEdge;i++){
    string s, t;
    int b, take;
    cin >> s >> t >> b >> take;

    b--;
    b %= 24;
    
    if((5<b && b<17) || (5<(b+take)%24 && (b+take)%24<17)){
      i--;
      nEdge--;
      continue;
    }
    
    if(take>12){
      i--;
      nEdge--;
      continue;
    }

    if(!n2i.count(s)){
      int sz = n2i.size();
      n2i[s] = sz;
    }
    if(!n2i.count(t)){
      int sz = n2i.size();
      n2i[t] = sz;
    }
    
    adj[n2i[s]].push_back(Edge(n2i[t],b,(b+take)%24));
  }

  string s, t;
  cin >> s >> t;

  if(!n2i.count(s)){
    int sz = n2i.size();
    n2i[s] = sz;
  }
  if(!n2i.count(t)){
    int sz = n2i.size();
    n2i[t] = sz;
  }

  init = n2i[s];
  goal = n2i[t];
}

int bfs(){
  int cost[CITY][24];
  priority_queue<Data> Q;
  
  for(int i=0;i<CITY;i++)
    for(int j=0;j<24;j++)
      cost[i][j] = INF;
  Q.push(Data(init,17,0));
  cost[init][17] = 0;
  
  while(!Q.empty()){
    Data curr = Q.top();
    Q.pop();
    
    if(curr.pos==goal) return curr.cost;
    
    for(vector<Edge>::iterator i=adj[curr.pos].begin();i!=adj[curr.pos].end();i++){
      Edge &e = *i;

      if(e.bgn!=curr.time) continue;
      if(cost[e.dst][e.end]<=cost[curr.pos][curr.time]) continue;
      cost[e.dst][e.end] = cost[curr.pos][curr.time];
      Q.push(Data(e.dst,e.end,cost[curr.pos][curr.time]));
    }

    int nextT = (curr.time+1)%24;
    int nextC = (curr.time==10 ? 1 : 0);

    if(cost[curr.pos][nextT]>cost[curr.pos][curr.time]+nextC){
      cost[curr.pos][nextT] = cost[curr.pos][curr.time]+nextC;
      Q.push(Data(curr.pos,nextT,cost[curr.pos][curr.time]+nextC));
    }
  }

  return -1; 
}

void work(int cases){
  int ans = bfs();

  cout << "Test Case " << cases << "." << endl;
  if(ans==-1)
    cout << "There is no route Vladimir can take." << endl;
  else
    cout << "Vladimir needs " << ans << " litre(s) of blood." << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
