#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<math.h>
#include<limits.h>
#include<float.h>

#define MAX 203


class Point{
 public:
  int x,y;
  
  double distance(Point p){
    return sqrt((double)((p.x-x)*(p.x-x)) + (double)((p.y-y)*(p.y-y)));
  }

};

class Node{
 public:

  int target;
  double weight;

  Node(){}

  Node(int t, double w) {
     target=t , weight=w;
  }

  bool operator< ( const Node &node) const {
    if(weight > node.weight) return true;
    else return false;
  }

};


class Graph{
public:

  vector< vector<Node> > adjList;
  vector< vector<Node>::iterator > pos;
  vector<int> visited;
  vector<double> distance;

  Graph(){}

  Graph(int n){
    adjList.assign(n+1,vector<Node>());
    pos.assign(n+1,vector<Node>::iterator());
  }

  void reset(int n){
    for(int i=0;i<n+1;i++)
      pos[i] = adjList[i].begin();
    visited.assign(n+1,false);
    distance.assign(n+1,DBL_MAX);
  }
  
  void insert(int source , Node node){
    adjList[source].push_back(node);
  }

  Node next(int n){
    if(pos[n]!=adjList[n].end()) return *pos[n]++;
    else return Node(-1,-1);
  }

};

int num_node;

void dijkstra(Graph &g){

  priority_queue<Node> Q;
  
  Q.push(Node(0,0));

  g.reset(num_node);
  g.distance[0] = 0;

      
  while(!Q.empty()){

    Node curr = Q.top();
    Q.pop();

    if(g.visited[curr.target]==true) continue;
    else g.visited[curr.target] = true;
    
    
    while(true){
      
      Node next = g.next(curr.target);


      if(next.target==-1) break;
      else if(g.distance[curr.target] >= next.weight && g.distance[next.target] > g.distance[curr.target]){
	g.distance[next.target] = g.distance[curr.target];
	Q.push(Node(next.target,g.distance[next.target]));
      }
      else if(next.weight > g.distance[curr.target]  &&  g.distance[next.target] > next.weight ){
	g.distance[next.target] = next.weight;
	Q.push(Node(next.target,g.distance[next.target]));
      }      

    }

  }


}

class Solver{
 public:

  
  bool read(Graph &g){
    Point P[MAX];

    cin >> num_node;
    if(num_node==0) return false;
    g = Graph(num_node);

    for(int i=0;i<num_node;i++){
      Point curr;
      
      cin >> curr.x >> curr.y;
      
      P[i] = curr;
    }

    for(int i=0;i<num_node;i++){
      for(int j=i+1;j<num_node;j++){
	g.insert(i,Node(j,P[i].distance(P[j])));
	g.insert(j,Node(i,P[j].distance(P[i])));
      }
    }

    return true;

  }

  void work(int cases, Graph &g){
    
    dijkstra(g);

    cout << "Scenario #" << cases << endl;
    printf("Frog Distance = %.3lf\n",g.distance[1]);
    cout << endl;

  }


};

int main(){
  Solver solver;
  Graph g;

  

  for(int cases=1;;cases++){
    if(solver.read(g)==false) break;
    solver.work(cases,g);
  }

}
