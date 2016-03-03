#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<limits.h>

class Node{
 public:

  int target,cost;

  Node(){}
  
  Node(int t, int c){
    target = t, cost = c;
  }

  bool operator< (Node const &n) const {
    if(cost>n.cost) return true;
    else return false;
  }

};

class Graph{
 public:

  vector< vector<Node> > adjList;
  vector< vector<Node>::iterator > pos;
  vector<int> cost;
  vector<int> visited;
  

  Graph(){}

  Graph(int n){
    adjList.assign(n+1,vector<Node>());
    pos.assign(n+1,vector<Node>::iterator());
  }
  
  void reset(int n){
    for(int i=0;i<n;i++)
      pos[i] = adjList[i].begin();
    cost.assign(n+1,0);
    visited.assign(n+1,false);
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
int start,goal;
map<string,int> name_list;
map<int,string> num_list;
priority_queue<Node> Q;


void dijkstra(Graph &g){
  
  g.reset(num_city);

  g.cost[start] = INT_MAX;
  Q.push(Node(start,0));


  while(!Q.empty()){
    
    Node curr = Q.top();
    Q.pop();

    if(g.visited[curr.target]==true) continue;
    else g.visited[curr.target]=true;


    while(true){
      
      Node next = g.next(curr.target);
      
      if(next.target==-1) break;
      else if(g.cost[curr.target]<next.cost && g.cost[next.target]<g.cost[curr.target]){
	g.cost[next.target]=g.cost[curr.target];
	Q.push(Node(next.target,g.cost[curr.target]));
      }
      else if(g.cost[curr.target]>=next.cost && g.cost[next.target]<next.cost){
	g.cost[next.target]=next.cost;
	Q.push(Node(next.target,next.cost));
      }

    }

  }

}


class Solver{
 public:

  void init(){
    name_list.clear();
    num_list.clear();
  }

  bool read(Graph &g){
    
    int num_node;

    cin >> num_city >> num_node;
    if(num_city==0 && num_node==0) return false;

    g = Graph(num_city);

    
    for(int i=0,curr_num_city=0;i<num_node;i++){
      int cost;
      string source, target;
    
      cin >> source >> target >> cost;
      
      if(name_list.find(source)==name_list.end()){ 
	name_list[source] = curr_num_city;
	num_list[curr_num_city] = source;
	curr_num_city++;
      }
      if(name_list.find(target)==name_list.end()){ 
	name_list[target] = curr_num_city;
	num_list[curr_num_city] = target;
	curr_num_city++;
      }
      
      g.insert(name_list[source],name_list[target],cost);
      g.insert(name_list[target],name_list[source],cost);
    }

    string tmp_start, tmp_goal;
    cin >> tmp_start >> tmp_goal;

    start=name_list[tmp_start], goal=name_list[tmp_goal];
    
    return true;
  }

  void work(Graph &g){
    dijkstra(g);
    
    cout << "Scenario #" << cases << endl;
    cout << g.cost[goal] << " tons" << endl;
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
