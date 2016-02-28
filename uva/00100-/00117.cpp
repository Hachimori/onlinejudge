#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cassert>
#include<climits>

class Node{
 public:

  int target;
  int weight;
  
  Node(){}
  Node(int t, int w) : target(t), weight(w) {}

  bool operator < (const Node &node) const {
    if(weight>node.weight) return true;
    else return false;
  }

};

class Graph{
 public:

  vector< vector<Node> > adjList;
  vector< vector<Node>::iterator > pos;
  vector< int > distance;
  vector< int > visited;
  
  
  Graph(){}
  Graph(int n){
    adjList.assign(n+1,vector<Node>());
    pos.assign(n+1,vector<Node>::iterator());
    distance.assign(n+1,0);
    visited.assign(n+1,false);
  }
  
  void reset(int n){
    for(int i=0;i<=n;i++)
      pos[i] = adjList[i].begin();
    
    distance.assign(n+1,INT_MAX);
    visited.assign(n+1,false);
  }

  void insert(int source, int target, int weight){
    adjList[source].push_back(Node(target,weight));
  }

  Node next(int n){
    if(pos[n]!=adjList[n].end()) return *pos[n]++;
    else return Node(-1,-1);
  }

};

int total_length;
int pos_odd1, pos_odd2;

void dijkstra(Graph &g){
  
  int num_odd=0;
  priority_queue<Node> Q;
  vector<int> isOdd;

  isOdd.assign('z'-'a',false);
  g.reset('z'-'a');
  pos_odd1=-1;

  for(int i='a'-'a';i<='z'-'a';i++){
    if(g.adjList[i].size()%2==1){
      num_odd++;
      isOdd[i]=true;
      if(pos_odd1==-1) pos_odd1 = i;
      else pos_odd2 = i;
    }
  }

  if(num_odd==1 || num_odd>2) assert(false);
  else if(num_odd==0) return;
  
  g.distance[pos_odd1] = 0;
  Q.push(Node(pos_odd1,0));

  while(!Q.empty()){
    
    Node curr = Q.top();
    Q.pop();

    if(g.visited[curr.target] == true) continue;
    else g.visited[curr.target] = true;

    while(true){
      
      Node next = g.next(curr.target);
      
      if(next.target==-1) break;
      else if(g.distance[next.target]>g.distance[curr.target]+next.weight){
	g.distance[next.target]=g.distance[curr.target]+next.weight;
	Q.push(Node(next.target,g.distance[next.target]));
      }

    }

  }

  total_length += g.distance[pos_odd2];

}

class Solver{
 public:

  bool read(Graph &g){
    
    total_length = 0;
    g = Graph('z'-'a');


    while(true){
      string name;

      if(!(cin >> name)) return false;
      else if(name.compare("deadend")==0) break;
      
      total_length += name.length();
      g.insert(name[0]-'a',name[name.length()-1]-'a',name.length());
      g.insert(name[name.length()-1]-'a',name[0]-'a',name.length());
    }


    return true;
  }


  void work(Graph &g){

    dijkstra(g);

    cout << total_length << endl;

  }

};

int main(){
  Solver solver;
  Graph g;

  while(true){
    if(solver.read(g)==false) break;
    solver.work(g);
  }

  return 0;
}
