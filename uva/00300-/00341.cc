#include<iostream>
#include<vector>
#include<algorithm>

#define INF 10000000
#define MAX_SIZE 15

using namespace std;

class Edge{
public:

  int target, delay;

  Edge(){}
  Edge(int t, int d): target(t), delay(d){}
};

int nNode, start, goal;
vector<Edge> adjList[MAX_SIZE];

bool read(){
  for(int i=0;i<MAX_SIZE;i++)
    adjList[i].clear();
  
  cin >> nNode;
  if(nNode==0) return false;

  for(int i=0;i<nNode;i++){
    int nEdge;
    cin >> nEdge;

    for(int j=0;j<nEdge;j++){
      Edge toPush;
      cin >> toPush.target >> toPush.delay;
      toPush.target--;

      adjList[i].push_back(toPush);
    }
  }
  
  cin >> start >> goal;
  start--, goal--;
  
  return true;
}

void dijkstra(){
  int pi[MAX_SIZE], cost[MAX_SIZE];
  bool visited[MAX_SIZE];
  
  for(int i=0;i<MAX_SIZE;i++){
    pi[i] = -1;
    cost[i] = INF;
    visited[i] = false;
  }
 
  cost[start] = 0;

  for(int i=0;i<nNode;i++){
    int minVal=INF, minPos;
    for(int j=0;j<nNode;j++)
      if(minVal>cost[j] && !visited[j]){
	minVal = cost[j];
	minPos = j;
      }
    
    if(minVal==INF) break;
    visited[minPos] = true;
    
    for(int j=0;j<adjList[minPos].size();j++)
      if(cost[adjList[minPos][j].target]>minVal+adjList[minPos][j].delay){
	cost[adjList[minPos][j].target] = minVal+adjList[minPos][j].delay;
	pi[adjList[minPos][j].target] = minPos;
      }
  }
  

  int curr=goal;
  vector<int> path;
  while(curr!=-1){
    path.push_back(curr);
    curr = pi[curr];
  }

  reverse(path.begin(),path.end());
  
  cout << "Path =";
  for(int i=0;i<path.size();i++)
    cout << ' ' << path[i]+1;
  
  cout << "; " << cost[goal] << " second delay" << endl;
}

void work(int cases){
  cout << "Case " << cases << ": ";

  dijkstra();
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
