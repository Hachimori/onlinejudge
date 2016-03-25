#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstdio>
using namespace std;
const int BUF = 26, INF = 1<<20;

class Route{
public:
  int startTime, cost;
  set< pair<int,int> > path; //(node,train's departure time)
  Route(){}
  Route(int s, int c, set< pair<int,int> > p): startTime(s), cost(c), path(p){}
};

class Edge{
public:
  int src, dst, startTime, cost;
  Edge(){}
  Edge(int src, int d, int s, int c): src(src), dst(d), startTime(s), cost(c){}
};

int get(map<string,int> &n2i, string &s){
  if(!n2i.count(s)){
    int sz = n2i.size();
    n2i[s] = sz;
  }
  return n2i[s];
}

int cnv(string &s){
  int h = atoi(s.substr(0,s.find(':')).c_str());
  int m = atoi(s.substr(s.find(':')+1).c_str());
  return h*60+m;
}

int nNode, start, goal;
vector<Edge> adj[BUF];

void read(){
  for(int i=0;i<BUF;i++) adj[i].clear();
  map<string,int> n2i;
  int nLine;
  cin >> nLine;
  for(int i=0;i<nLine;i++){
    int nAdj;
    cin >> nAdj;
    string time, src;
    cin >> time >> src;
    int curTime = cnv(time);
    for(int j=0;j+1<nAdj;j++){
      string cost, dst;
      cin >> cost >> dst;
      adj[get(n2i,src)].push_back(Edge(get(n2i,src),get(n2i,dst),curTime%1440,cnv(cost)));
      swap(dst,src);
      curTime += cnv(cost);
    }
  }
  nNode = n2i.size();
  string startS, goalS;
  cin >> startS >> goalS;
  start = get(n2i,startS);
  goal = get(n2i,goalS);
}

Route dijkstra(int startTime){
  vector<Edge> pi[BUF];
  bool visited[BUF];
  int cost[BUF];

  for(int i=0;i<nNode;i++){
    pi[i].clear();
    visited[i] = false;
    cost[i] = INF;
  }
  cost[start] = startTime;

  for(int k=0;k<nNode;k++){
    int minCost = INF, minPos;
    for(int i=0;i<nNode;i++)
      if(minCost>cost[i] && !visited[i]){
        minCost = cost[i];
        minPos = i;
      }
    if(minCost==INF) break;
    visited[minPos] = true;
    
    for(int i=0;i<adj[minPos].size();i++){
      Edge &e = adj[minPos][i];
      int nexCost;
      if(e.startTime<cost[minPos]%1440)
        nexCost = (1440+e.startTime-cost[minPos]%1440)+cost[minPos]+e.cost;
      else
        nexCost = (e.startTime-cost[minPos]%1440)+cost[minPos]+e.cost;
      if(cost[e.dst]==nexCost)
        pi[e.dst].push_back(e);
      else if(cost[e.dst]>nexCost){
        pi[e.dst].clear();
        pi[e.dst].push_back(e);
        cost[e.dst] = nexCost;
      }
    }
  }

  Route r;
  r.startTime = startTime;
  r.cost = cost[goal]-startTime;
  memset(visited,0,sizeof(visited));
  vector<int> stack;
  stack.push_back(goal);
  while(!stack.empty()){
    int cur = stack.back();
    stack.pop_back();
    if(visited[cur]) continue;
    visited[cur] = true;
    for(int i=0;i<pi[cur].size();i++){
      int pre = pi[cur][i].src;
      r.path.insert(make_pair(pre,pi[cur][i].startTime));
      stack.push_back(pre);
    }
  }

  return r;
}

void work(){
  set<int> startTime;
  for(int i=0;i<adj[start].size();i++){
    Edge &e = adj[start][i];
    if(startTime.count(e.startTime)) continue;
    startTime.insert(e.startTime);
  }

  vector<Route> ans;
  for(set<int>::iterator i=startTime.begin();i!=startTime.end();i++){
    ans.push_back(dijkstra(*i));
    if(ans.back().cost==INF-*i) ans.pop_back();
  }

  for(int i=ans.size()-1;i>=0;i--){
    if(i==ans.size()-1) continue;
    if(ans[i].startTime+ans[i].cost>=ans[i+1].startTime+ans[i+1].cost){
      ans.erase(ans.begin()+i);
      i++;
    }
  }

  for(int i=ans.size()-1;i>=0;i--){
    for(int j=0;j<i;j++){
      set<pair<int,int> > t = ans[i].path;
      t.insert(ans[j].path.begin(),ans[j].path.end());
      if(t.size()!=ans[i].path.size()+ans[j].path.size()){
        ans.erase(ans.begin()+i);
        break;
      }
    }
  }

  for(int i=0;i<ans.size();i++)
    printf("%02d:%02d %d:%02d\n",ans[i].startTime/60,ans[i].startTime%60,
                                 ans[i].cost/60,ans[i].cost%60);
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
