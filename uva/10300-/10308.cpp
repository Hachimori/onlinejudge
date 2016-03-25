#include<iostream>
#include<string>
#include<vector>
#include<queue>

#define MAX 10001

class Node{
 public:

  int target,weight;

  Node(){}

  Node(int t, int w){
    target = t, weight = w;
  }

};

class Node_list{
 public:

  int source,target,weight;

  Node_list(){}

  Node_list(int s, int t, int w){
    source = s, target = t, weight = w;
  }

};

class Graph{
 public:

  vector< vector<Node> > adjList;
  vector< vector<Node>::iterator > pos;
  vector<int> visited;
  vector<int> distance;
  

  Graph(){}

  Graph(int n){
    adjList.assign(n+1,vector<Node>());
    pos.assign(n+1,vector<Node>::iterator());
    visited.assign(n+1,false);
    distance.assign(n+1,0);
  }

  void reset(int n){
    for(int i=0;i<n+1;i++)
      pos[i] = adjList[i].begin();
    
    visited.assign(n+1,false);
    distance.assign(n+1,0);    
  }

  void insert(int source, int target, int weight){
    adjList[source].push_back(Node(target,weight));
  }

  Node next(int n){
    if(pos[n]!=adjList[n].end()) return *pos[n]++;
    else return Node(-1,-1);
  }

};

Node_list list[MAX];
int max_distance1,max_distance2,num_village,num_node;
int num_path;

void dfs_rec(Graph &g, int arg, int weight){

  g.visited[arg]=true;

  while(true){ 
    Node next = g.next(arg);
    
    if(next.target==-1){
      if(num_path==0){
	max_distance1 = weight;
      }
      else if(num_path==1){
	if(max_distance1>weight){
	  max_distance2 = weight;
	}
	else{
	  max_distance2 = max_distance1;
	  max_distance1 = weight;
	}
      }
      if(max_distance<weight) max_distance = weight;
      num_path++;
      return;
    }
    else if(g.visited[next.target]==true) continue;
    else{
      dfs_rec(g,next.target,weight+next.weight);
    }

  }

}

class Solver{
 public:

  bool read_node(){
    
    max_distance = 0;
    num_village = 0;

    for(num_node=0;;num_node++){
      string str;

      if(cin.eof()) return false;

      getline(cin,str);

      
      if(str.length()==0) return true;
      

      int arg,source=0,target=0,weight=0;
      for(arg=0;;arg++){
	if(str[arg]==' ') break;
	source*=10; 
	source+=str[arg]-'0';
      }
      for(;;arg++) if(str[arg+1]!=' '){ arg++; break; }
      
      for(;;arg++){
	if(str[arg]==' ') break;
	target*=10; 
	target+=str[arg]-'0';
      }
      for(;;arg++) if(str[arg+1]!=' '){ arg++; break; }

      for(;arg<str.length();arg++){
	if(str[arg]<'0' || str[arg]>'9') break;
	weight*=10; 
	weight+=str[arg]-'0';	
      }

      if(num_village<source) num_village=source;
      if(num_village<target) num_village=target;
      list[num_node] = Node_list(source,target,weight);
    }

  }

  void make_graph(Graph &g){

    g = Graph(num_village);

    for(int i=0;i<num_node;i++){
      g.insert(list[i].source,list[i].target,list[i].weight);
      g.insert(list[i].target,list[i].source,list[i].weight);
    }

  }

  void work(Graph &g){
    
    num_path = 0;

    g.reset(num_village);
    dfs_rec(g,1,0);    

    cout << max_distance << endl; 

  }

};

main(){
  Solver solver;
  Graph g;
  
  while(true){
    if(solver.read_node()==false) break;
    solver.make_graph(g);
    solver.work(g);
  }

}
