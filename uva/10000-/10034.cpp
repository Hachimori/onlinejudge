#include<iostream>
#include<stdio.h>
#include<queue>
#include<math.h>
#include<vector>

#define MAX 104

class Point{
 public:

  double x,y;
};

class Node{
 public:

  int target;
  double distance;

  Node(){}

  Node(int t, double d){
    target = t, distance = d;
  }

  bool operator< (Node const &n) const {
    if(distance>n.distance) return true;
    else return false;
  }

};


class Graph{
 public:

  vector< vector<Node> > adjList;
  vector< vector<Node>::iterator > pos;
  vector<int> visited;

  Graph(){}
  
  Graph(int n){
    adjList.assign(n,vector<Node>());
    pos.assign(n,vector<Node>::iterator());
    visited.assign(n,false);
  }

  void reset(int n){
    for(int i=0;i<n;i++)
      pos[i] = adjList[i].begin();
  }

  void insert(int source, int target, double s_x, double s_y, double t_x, double t_y){
    double dis = sqrt((s_x-t_x)*(s_x-t_x)+(s_y-t_y)*(s_y-t_y));
    adjList[source].push_back(Node(target,dis));
  }

  Node next(int n){
    if(pos[n]!=adjList[n].end()) return *pos[n]++;
    else return Node(-1,-1);
  }

};

int num_node;
double sum;
Point list[MAX];
priority_queue<Node> Q;

void mst(Graph &g){
  
  int num_connect=0;

  while(!Q.empty()) Q.pop();

  Q.push(Node(0,0));

  g.reset(num_node);

  while(num_connect!=num_node){
    
    Node curr = Q.top();
    Q.pop();

    if(g.visited[curr.target]==true) continue;
    else g.visited[curr.target]=true;

    while(true){
      Node next = g.next(curr.target);
      
      if(next.target==-1) break;
      else if(g.visited[next.target]==true) continue;
      else{
	Q.push(next);
      }
    }
    //cout << curr.target <<" "<< curr.distance << endl;
    sum+=curr.distance;
    num_connect++;

  }

}

class Solver{
 public:

  void read(Graph &g){

    cin >> num_node;
    g = Graph(num_node); 

    for(int i=0;i<num_node;i++)
      cin >> list[i].x >> list[i].y;  


    for(int i=0;i<num_node;i++){
      for(int j=i+1;j<num_node;j++){
	g.insert(i,j,list[i].x,list[i].y,list[j].x,list[j].y);
	g.insert(j,i,list[i].x,list[i].y,list[j].x,list[j].y);
      }
    }

  }

  void work(Graph &g){

    sum=0;

    mst(g);

    printf("%.2lf\n",sum);

  }

};

main(){

  int cases;
  Solver solver;
  Graph g;
  
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    solver.read(g);
    solver.work(g);
  }
  
}
