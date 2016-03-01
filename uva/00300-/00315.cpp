#include<iostream>
#include<vector>
#include<string>

class Graph{
 public:

  vector< vector<int> > adjList;
  vector< vector<int>::iterator > pos;
  vector<int> visited;

  Graph(){}

  Graph(int n){
    adjList.assign(n+1,vector<int>());
    pos.assign(n+1,vector<int>::iterator());
  }

  
  void reset(int n){
    visited.assign(n+1,false);
    for(int i=0;i<n+1;i++)
      pos[i]=adjList[i].begin();
  }

  void insert(int source, int target){
    adjList[source].push_back(target);
  }

  int next(int n){
    if(pos[n]!=adjList[n].end()) return *pos[n]++;
    else return -1;
  }
  
};

int num_node;
int num_critical;

void dfs_rec(Graph &g, int arg){

  g.visited[arg]=true;

  while(true){

    int next = g.next(arg);
    
    if(next==-1) break;
    else if(g.visited[next]==true) continue;

    dfs_rec(g,next);

  }

} 

class Solver{
 public:

  bool read(Graph &g){
    
    cin >> num_node;
    if(num_node==0) return false;
    
    g = Graph(num_node);

    string str;
    getline(cin,str);
    
    while(true){
      
      int tmp_target;
      cin >> tmp_target;
      if(tmp_target==0) break;

      getline(cin,str);
      
      
      for(int i=0;i<str.length();i++){
	if(str[i]>='1' && str[i]<='9'){
	  int num=0;
	  for(;str[i]>='0' && str[i]<='9' && i<str.length();i++){
	    num *= 10;
	    num += str[i]-'0';
	  }
	  
	  g.insert(tmp_target,num);
	  g.insert(num,tmp_target);
	}	
      }

    }

    return true;
  }

  void work(Graph &g){
    
    num_critical=0;

    for(int i=1;i<=num_node;i++){
      g.reset(num_node);
      
      if(i!=1){ 
	g.visited[i]=true;
	dfs_rec(g,1);
      }
      else if(i==1){ 
	g.visited[i]=true;
	dfs_rec(g,2);
      }

      for(int j=1;j<=num_node;j++) 
	if(g.visited[j]==false){
	  num_critical++;
	  break;
	}
      
    }

    cout << num_critical << endl;

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
