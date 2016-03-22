#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>

class Node{
 public:
  int target;
  int cost;
  
  Node(){}

  Node(int t, int c){
    target = t;
    cost = c;
  }

  bool operator< (Node const &n) const {
    if(cost<n.cost) return true;
    else return false;
  }

};

class Graph{
 public:

  vector< vector<Node> > adjList;
  vector< vector<Node>::iterator > pos;
  vector<int> visited;
  vector<int> cost;

  Graph(){}

  Graph(int n){
    adjList.assign(n+1,vector<Node>());
    pos.assign(n+1,vector<Node>::iterator());
  }

  void reset(int n){
    for(int i=0;i<=n;i++)
      pos[i] = adjList[i].begin();
    visited.assign(n+1,false);
    cost.assign(n+1,0);
  }
  
  void insert(int source, int target, int cost){
    adjList[source].push_back(Node(target,cost));
  }

  Node next(int n){
    if(pos[n]!=adjList[n].end()) return *pos[n]++;
    else return Node(-1,-1);
  }

};

int cases;
int num_city;
int start, goal, num_passenger;
priority_queue<Node> Q;

void dijkstra(Graph &g){
  
  g.reset(num_city);

  g.cost[start]=INT_MAX;
  Q.push(Node(start,0));
  

  while(!Q.empty()){
    
    Node curr = Q.top();
    Q.pop();
    
    if(g.visited[curr.target]==true) continue;
    else g.visited[curr.target]=true;


    while(true){
      /*
	for(int i=1;i<=num_city;i++){
	cout << i << ":  " << g.cost[i] << endl;
	}
	cout << endl;
	*/      
      Node next = g.next(curr.target);
      
      if(next.target<0) break;
      else if(g.cost[curr.target]>next.cost && next.cost>g.cost[next.target] ){
	g.cost[next.target] = next.cost;
	Q.push(Node(next.target,next.cost));
      }
      else if(g.cost[curr.target]<=next.cost && g.cost[curr.target]>g.cost[next.target]){
	g.cost[next.target] = g.cost[curr.target];
	Q.push(Node(next.target,g.cost[curr.target]));
      }
      
    }
  
  }

}

class Solver{
 public:

  bool read(Graph &g){

    int num_node;

    cin >> num_city >> num_node;
    if(num_city==0 && num_node==0) return false;

    g = Graph(num_city);

    for(int i=0;i<num_node;i++){
      int source,target,cost;      
      cin >> source >> target >> cost;
      
      g.insert(source,target,cost);
      g.insert(target,source,cost);
    }
    
    
    cin >> start >> goal >> num_passenger;

    return true;
  }

  void work(Graph &g){

    dijkstra(g);
    /*
    for(int i=1;i<=num_city;i++){
      cout << i << ":  " << g.cost[i] << endl;
    }
    cout << endl;
    */
    cout << "Scenario #" << cases << endl;
    if(num_passenger%(g.cost[goal]-1)>0) 
      cout << "Minimum Number of Trips = " << num_passenger/(g.cost[goal]-1)+1 << endl;
    else 
      cout << "Minimum Number of Trips = " << num_passenger/(g.cost[goal]-1) << endl;
    cout << endl;
  }

};
 
main(){
  Solver solver;
  Graph g;

  for(cases=1;;cases++){
    if(solver.read(g)==false) break;
    solver.work(g);
  }

}
