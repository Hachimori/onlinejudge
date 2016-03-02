#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<limits.h>

class Node{
 public:

  int target,cost;

  Node(){}

  Node(int t, int c){
    target = t, cost = c;
  }
  
  bool operator< (Node const &n) const{
    if(cost>n.cost) return true;
    else return false;
  }

};

class Graph{
 public:

  vector< vector<Node> > adjList;
  vector< vector<Node>::iterator > pos;
  vector<int> distance;
  vector<int> visited;

  Graph(){}

  Graph(int n){
    adjList.assign(n+1,vector<Node>());
    pos.assign(n+1,vector<Node>::iterator());
    distance.assign(n+1,INT_MAX);
    visited.assign(n+1,false);
  }

  void insert(int source, int target, int cost){
    adjList[source].push_back(Node(target,cost));
  }

  void reset(int num){
    for(int i=0;i<=num;i++)
      pos[i]=adjList[i].begin();
  }
  
  Node next(int n){
    if(pos[n]!=adjList[n].end()) return *pos[n]++;
    else return Node(-1,-1);
  }

};

int max_cost;
int num_node;
priority_queue<Node> Q;

void dijkstra(int start, Graph &g){
  
  Q.push(Node(start,0));
  g.distance[start]=0;


  while(!Q.empty()){
    
    Node curr = Q.top();
    Q.pop();
    
    if(g.visited[curr.target]==true) continue;
    g.visited[curr.target]=true;
    
    while(true){
      
      Node next = g.next(curr.target);
      
      if(next.target==-1) break;
      else if(g.distance[next.target]>g.distance[curr.target]+next.cost){
	g.distance[next.target]=g.distance[curr.target]+next.cost;
	Q.push(Node(next.target,g.distance[next.target]));
      }

    }
    
  }

}

int myatoi(string str){
  
  int num=0;

  for(int i=0;i<str.length();i++){
    num*=10;
    num+=str[i]-'0';
  }

  return num;

}

class Solver{
 public:

  bool read(Graph &g){
    
    cin >> num_node;
    g = Graph(num_node);

    if(cin.eof()) return false;

    for(int i=2;i<=num_node;i++){
      for(int j=1;j<i;j++){
	string cost;

	cin >> cost;

	if(cost.compare("x")==0) continue;
	
	int num=myatoi(cost);

	g.insert(i,j,num);
	g.insert(j,i,num);
      }
    }
    
    return true;

  }

  void work(Graph &g){
    
    max_cost=0;

    g.reset(num_node);
    
    dijkstra(1,g);
   
    for(int i=1;i<=num_node;i++)
      if(max_cost<g.distance[i])
	max_cost = g.distance[i];
 
    cout << max_cost << endl;

  }

};

main(){
  Solver solver;
  Graph g;


  while(true){
    
    if(solver.read(g)==false) break;
    solver.work(g);
    
  }


}
