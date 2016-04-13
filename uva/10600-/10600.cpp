#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<limits.h>
#define MAX 103

class Node_info{
 
 public:
  int weight;
  int target;
  int source;
  
  Node_info(){}
  
  Node_info(int s,int t,int w){
    source = s,target = t, weight = w;
  }
  
  bool operator < (const Node_info &node) const {
    if(node.weight<weight) return true;
    else return false;
  } 

};

priority_queue<Node_info> Q;

class Graph{
  
 public:

  vector<vector<Node_info>::iterator> pos;
  vector<Node_info> PI;
  vector<int> visited;
  vector<int> separated;

  int adjArray[MAX][MAX];
  int total_weight;
  int num_node;

  Graph(){};

  Graph(int n){
    for(int i=0;i<=n;i++)
      for(int j=0;j<=n;j++)
	adjArray[i][j]=0;
    pos.assign(n,vector<Node_info>::iterator());
    visited.assign(n,0);
    separated.assign(n,0);
    while(!Q.empty()) Q.pop();
    total_weight=0;
    num_node = n-1;
  }
  
  void insert(int source , int target , int weight){
    adjArray[source][target]=weight;
  }

  Node_info next(int u){
    for(int i=0;i<=num_node;i++)
      if(adjArray[u][i]!=0) return Node_info(u,i,adjArray[u][i]);
    else return Node_info(-1,-1,-1);
  }

  void separate(Graph &g, int source, Node_info Edge){

    g.separated[source]=1;
    
    //cout << source << " ";
    
    for(int i=1;i<=g.num_node;i++){
      if( (source == Edge.source && i == Edge.target) || (source == Edge.target && i == Edge.source) ) continue;
      
      if(adjArray[source][i]!=0 && g.separated[i]==0)
	for(int j=0;j<g.PI.size();j++){
	  if((source == g.PI[j].source && i == g.PI[j].target) || (source == g.PI[j].target && i == g.PI[j].source)) separate(g,i,Edge);
	}
      
    }
    
  }
  
}; 

void mst(Graph &g,int source){

  int num_edge=0;
  Node_info curr;

  for(int i=0;i<=g.num_node;i++){
    if(g.adjArray[source][i]!=0){
      Q.push(Node_info(source,i,g.adjArray[source][i]));
    }
  }

  g.visited[source]=true;
  

  while(num_edge<g.num_node-1){
    
    curr = Q.top();
    Q.pop();
    
    if(g.visited[curr.target]==true) continue;
    
    for(int i=0;i<=g.num_node;i++){
      if(g.adjArray[curr.target][i]!=0){
	Q.push(Node_info(curr.target,i,g.adjArray[curr.target][i]));
      }
    }

    num_edge++;
    g.visited[curr.target]=true;
    g.total_weight += curr.weight;
    g.PI.push_back(curr);

  }

  return;

}

class Solver{
  
 public:

  void read(Graph &g){

    int source,target,cost;
    int num_node,num_case;
    
    cin >> num_node >> num_case;
    
    g = Graph(num_node+1);

    for( int i=0; i<num_case; i++){
      cin >> source >> target >> cost;
      g.adjArray[source][target]=cost;
      g.adjArray[target][source]=cost;
    }

  }

  void work(Graph &g){
   
    mst(g,1);
    
    cout << g.total_weight;
    int min=INT_MAX;
    /*
    for(int i=0;i<g.PI.size();i++)
      cout << "source = " << g.PI[i].source << "  target = " << g.PI[i].target << "  weight = " << g.PI[i].weight << endl;
      */
    
    for(int i=0;i<g.PI.size();i++){
      g.separate(g,g.PI[i].source,g.PI[i]);
      
      /*
	cout << "end ";
	for(int j=1;j<=g.num_node;j++){
	cout << g.separated[j] << ' ';
	}
	cout << endl;
	*/
      
      for(int j=1;j<=g.num_node;j++) {
	if(g.separated[j]==0){
	  for(int k=1;k<=g.num_node;k++){
	    if(g.adjArray[j][k]==0) continue;
	    if( (j==g.PI[i].source && k==g.PI[i].target) || (j==g.PI[i].target && k==g.PI[i].source) || g.separated[k]==0) continue;
	    if(g.adjArray[j][k]-g.PI[i].weight < min) min = g.adjArray[j][k]-g.PI[i].weight;
	  }
	}
	else if(g.separated[j]==1){
	  for(int k=1;k<=g.num_node;k++){
	    if(g.adjArray[j][k]==0) continue;
	    if( (j==g.PI[i].source && k==g.PI[i].target) || (j==g.PI[i].target && k==g.PI[i].source) || g.separated[k]==1) continue;
	    if(g.adjArray[j][k]-g.PI[i].weight < min) min = g.adjArray[j][k]-g.PI[i].weight;
	  }	
	}
	if(min==0) break;
      }
     
      if(min==0) break;
      
      for(int j=1;j<=g.num_node;j++) g.separated[j]=0;
    }
   
    cout << ' ' << g.total_weight+min << endl;

  }
  
};



main()
{
  Solver solver;
  Graph g;
  int cases;

  cin >> cases;

  for(int i=0;i<cases;i++){
    solver.read(g);
    solver.work(g);
  }

}

