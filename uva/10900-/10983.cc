// データ構造:
//
// ノードidを都市のID(cityId)と日付dateに拡大する。
// id = date*nCity+cityId とすると, 
// 何時、何処の都市にいるのか、という情報を重複することなく表せる。
//
// 
// 問題の概要:
// あるチケットを買うと、その値段より安いチケットを自由に利用できる。
// なるべく安いチケットを購入して全員を決まった都市に運ぶ。
//
//
// 解法:
// 買うべきチケットの値段を二分法で求める。
//
//
// stackで実装したmaxFlowはTLEだった。 

#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
#define NODE 350
#define EDGE 3005
#define INF (1<<30)
using namespace std;

class Edge{
public:
  int cap, cost;

  Edge(){}
  Edge(int cap, int cost): cap(cap), cost(cost){}
};

int nNode, SRC, DST, total;
Edge adj[NODE][NODE];

void read(){
  int nCity, nEdge, day;
  cin >> nCity >> day >> nEdge;
  
  total = 0;
  for(int i=0;i<NODE;i++)
    for(int j=0;j<NODE;j++)
      adj[i][j] = Edge(0,INF);
  
  SRC = nCity*(day+1);
  DST = nCity*(day+1)+1;
  nNode = nCity*(day+1)+2;
  
  for(int i=0;i<nEdge;i++){
    int s, t, cap, cost, flyDay;
    cin >> s >> t >> cap >> cost >> flyDay;
    s--, t--;

    int sId = nCity*flyDay+s, tId = nCity*(flyDay+1)+t;
    adj[sId][tId] = Edge(cap,cost);
    adj[tId][sId] = Edge(0,cost);
  }
  
  for(int i=0;i<nCity;i++){
    int nMen;
    cin >> nMen;
    adj[SRC][nCity*0+i] = Edge(nMen,0);
    adj[nCity*0+i][SRC] = Edge(0,0);
    total += nMen;
  }
  
  for(int i=0;i<=day;i++){
    adj[nCity*i+nCity-1][DST] = Edge(INF,0);
    adj[DST][nCity*i+nCity-1] = Edge(0,0);
  }

  for(int i=0;i<nCity;i++)
    for(int j=0;j+1<day;j++){
      adj[nCity*j+i][nCity*(j+1)+i] = Edge(INF,0);
      adj[nCity*(j+1)+i][nCity*j+i] = Edge(0,0);
    }
}

bool augment(int pi[], int limit){
  queue<int> Q;
  
  fill(pi,pi+nNode,-1);
  pi[SRC] = -2;
  Q.push(SRC);
  
  while(!Q.empty() && pi[DST]==-1){
    int curr = Q.front();
    Q.pop();
    
    for(int i=0;i<nNode;i++){
      if(pi[i]!=-1 || adj[curr][i].cap<=0 || adj[curr][i].cost>limit)
	continue;
      pi[i] = curr;
      Q.push(i);
    }
  }
  
  return pi[DST]!=-1;
}

int maxFlow(int limit){
  int sum = 0, pi[NODE];
  
  while(augment(pi,limit)){
    int flow = INF;
    for(int cur=DST;pi[cur]>=0;cur=pi[cur])
      flow = min(flow,adj[pi[cur]][cur].cap);

    for(int cur=DST;pi[cur]>=0;cur=pi[cur]){
      adj[pi[cur]][cur].cap -= flow;
      adj[cur][pi[cur]].cap += flow;
    }
    
    sum += flow;
  }

  return sum==total;
}

void work(int cases){
  int nCost = 0, cost[EDGE];
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      if(adj[i][j].cost!=0 && adj[i][j].cost!=INF)
	cost[nCost++]= adj[i][j].cost;

  sort(cost,cost+nCost);
  nCost = unique(cost,cost+nCost)-cost;
  
  Edge backup[NODE][NODE];
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      backup[i][j] = adj[i][j];

  int l = 0, r = nCost-1;
  while(l!=r){
    int mid = (l+r)/2;
    
    if(mid==l){
      if(maxFlow(cost[mid])) r--;
      else l++;
    }
    else{
      if(maxFlow(cost[mid])) r = mid;
      else l = mid;
    }

    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
	adj[i][j] = backup[i][j];
  }
  
  cout << "Case #" << cases << ": ";
  if(!maxFlow(cost[l])) cout << "Impossible" << endl;
  else cout << cost[l] << endl;
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
