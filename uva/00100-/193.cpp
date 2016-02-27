#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define BLACK 2
#define WHITE 3

class Graph{
public:
  
  vector< vector<int> > adjList;
  vector< vector<int>::iterator > pos;
  vector<int> color;

  Graph(){}

  Graph(int n){
    adjList.assign(n,vector<int>() );
    pos.assign(n,vector<int>::iterator() );
    color.assign(n,0);
  }

  void reset(){
    for(int i=0;i<adjList.size()+1;i++) pos[i]=adjList[i].begin();
  }

  int next(int n){
    if(pos[n]!=adjList[n].end()) return *pos[n]++;
    else return -1;
  }

  void insert(int source, int target){
    adjList[source].push_back(target);
  }

};

int num_node,max_black;
vector<int> backup;


int Count_black(Graph &g){

  int num_black=0;

  for(int i=1;i<=num_node;i++)
    if(g.color[i]==BLACK) num_black++;
  
  return num_black;

}

void search_graph_rec(Graph &g,int depth){
  
  int num_black;
  vector<int>::iterator j_ret;

  if(depth==num_node+1) return;
  
  /*
  for(j_ret=g.color.begin();j_ret!=g.color.end();j_ret++)
    cout << *j_ret << ' ';
  cout << endl;
  */

  for(int i=0;i<2;i++){
    if(i==0){ 
      g.color[depth]=WHITE;
      search_graph_rec(g,depth+1);
    
      num_black = Count_black(g);

      if(max_black<num_black){
	max_black = num_black;
	backup = g.color;
      }
    }    
    else {

      bool double_black=false;

      for(j_ret=g.adjList[depth].begin();j_ret!=g.adjList[depth].end();j_ret++)
	if(g.color[*j_ret]==BLACK && depth > *j_ret ) double_black = true;
	
      if(double_black==true) continue;
      
      g.color[depth]=BLACK;
      search_graph_rec(g,depth+1);

      num_black = Count_black(g);

      if(max_black<num_black){ 
	max_black = num_black;
	backup = g.color;
      }
      
    }

  }


}

class Solver{
 public:

  void read(Graph &g){

    int n,num_queue;
    int source,target;

    cin >> num_node >> num_queue;

    g = Graph(num_node+1);


    for( int i=0;i<num_queue;i++){
      cin >> source >> target;

      g.insert(source,target);
      g.insert(target,source);
    }
      
  }
  
  

  void work(Graph &g){

    int i,num_black=0;
    max_black=0;

    search_graph_rec(g,1);

    vector<int>::iterator i_ret;
    bool first=true;

    for(i_ret=backup.begin();i_ret!=backup.end();i_ret++)
      if(*i_ret==BLACK) num_black++;
    
    cout << num_black << endl;

    for(i_ret=backup.begin(),i=0;i_ret!=backup.end();i_ret++,i++){
      if(*i_ret==BLACK && first!=true) cout << ' ' << i;
      else if(*i_ret==BLACK && first==true){ 
	cout << i;
	first = false;
      }
    }
    cout << endl;

  }


};

main(){

  Solver solver;
  Graph g;

  int cases;

  cin >> cases;

  for(int i=0;i<cases;i++){
    //if(i!=0) cout << endl;
    solver.read(g);
    solver.work(g);
  }

}
