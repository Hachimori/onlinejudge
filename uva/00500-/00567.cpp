#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>


class Graph{
 public:
  
  vector< vector<int> > adjList;
  vector< vector<int>::iterator > pos;
  vector<int> distance;
  vector<int> visited;
  
  Graph(){}
  
  Graph(int n){
    adjList.assign(n+1,vector<int>());
    pos.assign(n+1,vector<int>::iterator());
    distance.assign(n+1,0);
    visited.assign(n+1,0);
  }

  void insert(int source, int target){
    adjList[source].push_back(target);
  }

  void reset(){
    for(int i=0;i<=20;i++)
      pos[i] = adjList[i].begin();
  }

  int next(int n){
    if(pos[n] != adjList[n].end()) return *pos[n]++;
    else return -1;
  }

};

queue<int> Q;
int source,target,set;

void bfs(Graph &g){

  int curr;

  while(!(Q.empty())) Q.pop();

  g.reset();
  g.distance.assign(21,0);
  g.visited.assign(21,0);
  g.distance[source]=0;
  g.visited[source] = 1;
  Q.push(source);

  while(true){

    curr = Q.front();
    Q.pop();

    while(true){
      int next=g.next(curr);
      if(next==-1) break;
      else if(g.visited[next]==1) continue;
      else if(next==target){
	printf("%2d",source);
	cout << " to ";
	printf("%2d",target);
	cout << ": " << g.distance[curr]+1 << endl;
	return;
      }
      else {
	g.distance[next] = g.distance[curr]+1;
	g.visited[next] = 1;
	Q.push(next);
      }
    }

  }

}

class Solver{
 public:

  bool read_graph(Graph &g){

    g = Graph(20);

    for(int i=1;i<=19;i++){
      int num_connect;
      cin >> num_connect;
      if(cin.eof()) return false;

      for(int j=0;j<num_connect;j++){
	int tmp_target;
	cin >> tmp_target;
	g.insert(i,tmp_target);
	g.insert(tmp_target,i);
      }
    }


    return true;
  }


  void read(){
    cin >> source >> target;
  }

  void work(Graph &g){
    bfs(g);
  }

};

main(){

  Graph g;
  int cases;
  Solver solver;

  for(set=1;;set++){
    if(solver.read_graph(g)==false) break;
    cin >> cases;
    cout << "Test Set #" << set << endl;
    for(int i=0;i<cases;i++){
      solver.read();
      solver.work(g);
    }
    cout << endl;
  }

}
