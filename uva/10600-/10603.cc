#include<iostream>
#include<algorithm>
#include<queue>
#define BUF 201
#define INF 2000000000
using namespace std;

int cap[3], dst;

class State{
public:
  int amt[3], cost;

  State(){}
  State(int _amt[], int _cost){
    for(int i=0;i<3;i++)
      amt[i] = _amt[i];
    cost = _cost;
  }

  bool operator< (const State &s) const {
    return cost>s.cost;
  }
};

void read(){
  for(int i=0;i<3;i++)
    cin >> cap[i];
  cin >> dst;
}

void dijkstra(int cost[][BUF][BUF]){
  int init[]={0,0,cap[2]};
  priority_queue<State> Q;

  Q.push(State(init,0));
  
  for(int i=0;i<=cap[0];i++)
    for(int j=0;j<=cap[1];j++)
      for(int k=0;k<=cap[2];k++)
	cost[i][j][k] = INF;
  cost[0][0][cap[2]] = 0;
  
  while(!Q.empty()){
    State curr = Q.top();
    Q.pop();
   
    for(int s=0;s<3;s++)
      for(int t=0;t<3;t++){
	if(s==t) continue;
	
	int nextT = min(cap[t],curr.amt[t]+curr.amt[s]);
	int added = nextT-curr.amt[t];
	int nextS = curr.amt[s]-added;
	
	State next = curr;
	next.amt[s] = nextS, next.amt[t] = nextT, next.cost+=added;
	
	if(cost[next.amt[0]][next.amt[1]][next.amt[2]]>next.cost){
	  cost[next.amt[0]][next.amt[1]][next.amt[2]] = next.cost;
	  Q.push(next);
	}
      }
  }
}

int calcDiff(int a, int b, int c){
  int ret = INF;
  if(ret>dst-a && dst>=a)
    ret = dst-a;
  if(ret>dst-b && dst>=b)
    ret = dst-b;
  if(ret>dst-c && dst>=c)
    ret = dst-c;
  return ret;
}

void work(){
  static int cost[BUF][BUF][BUF];

  dijkstra(cost);
  
  int minV = INF, minDiff = INF;
  for(int i=0;i<=cap[0];i++){
    for(int j=0;j<=cap[1];j++){
      for(int k=0;k<=cap[2];k++){
	if(cost[i][j][k]==INF) continue;
	
	if(minDiff==calcDiff(i,j,k))
	  minV = min(minV,cost[i][j][k]);
	else if(minDiff>calcDiff(i,j,k)){
	  minV = cost[i][j][k];
	  minDiff = calcDiff(i,j,k);
	}
      }
    }
  }
  
  cout << minV << ' ' << dst-minDiff << endl;
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
