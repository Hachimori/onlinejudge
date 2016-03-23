// chinese postman problem
//
// 
// 1,度数が奇数の頂点を全て列挙する。
// 2,奇数の頂点間の最短距離を調べる。
// 3,奇数の頂点間に辺を加えて、全ての頂点の度数を偶数にする。
//   この時、加える辺の重みの和が最小となるようにする。
// 4,Fleuryのアルゴリズムを使ってオイラー回路を作る。
//
//
// V<=15 E<1000 で 2.092秒

#include<iostream>
#include<vector>
#include<algorithm>

#define INF 100000000
#define MAX_SIZE 20

using namespace std;

class Data{
public:
  int a,b,cost;
  
  Data(){}
  Data(int a, int b, int c): a(a), b(b), cost(c){}
};

int nNode, ans;
int degree[MAX_SIZE];
int adjList[MAX_SIZE][MAX_SIZE];

bool read(){
  int nEdge;

  ans = 0;
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++){
      degree[j] = 0;
      adjList[i][j] = INF;
    }
  
  cin >> nNode;
  if(nNode==0) return false;

  cin >> nEdge;


  for(int i=0;i<nEdge;i++){
    int s, t, c;
    cin >> s >> t >> c;
    s--,t--;
    
    if(adjList[s][t]>c){
      adjList[s][t] = c;
      adjList[t][s] = c;
    }
    
    ans += c;
    degree[s]++, degree[t]++;
  }
  
  return true;
}

void floyd(int adjList[][MAX_SIZE], int cost[][MAX_SIZE]){
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      cost[i][j] = adjList[i][j];

  for(int i=0;i<nNode;i++)
    cost[i][i] = 0;

  for(int k=0;k<nNode;k++)
    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
	if(cost[i][j]>cost[i][k]+cost[k][j])
	  cost[i][j] = cost[i][k]+cost[k][j];
}

void rec(int idx, int curr, bool oddDegree[], const vector<Data> &set,
	 int &toAdd, int cost[][MAX_SIZE]){
  if(count(oddDegree,oddDegree+nNode,true)==0){
    toAdd = min(toAdd,curr);
    return;
  }
  
  if(toAdd<=curr) return;
  
  for(int i=idx;i<set.size();i++){
    if(!oddDegree[set[i].a] || !oddDegree[set[i].b]) continue;
    
    oddDegree[set[i].a] = false;
    oddDegree[set[i].b] = false;
    
    rec(i+1,curr+cost[set[i].a][set[i].b],oddDegree,set,toAdd,cost);

    oddDegree[set[i].a] = true;
    oddDegree[set[i].b] = true;
  }
}

void work(){
  bool oddDegree[MAX_SIZE];
  for(int i=0;i<nNode;i++)
    if(degree[i]%2==1) 
      oddDegree[i] = true;
    else
      oddDegree[i] = false;
  
  int cost[MAX_SIZE][MAX_SIZE];
  floyd(adjList,cost);
  
  vector< Data > set;
  for(int i=0;i<nNode;i++)
    for(int j=i+1;j<nNode;j++)
      if(i!=j && oddDegree[i] && oddDegree[j])
	set.push_back(Data(i,j,cost[i][j]));
  
  int toAdd = INF;
  rec(0,0,oddDegree,set,toAdd,cost);
  
  cout << ans+toAdd << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
