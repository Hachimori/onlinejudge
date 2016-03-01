#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define MAX 100

class Key_vector{
 public:
  int Key;
  vector<int> nodelist;
};

class Key_iterator{
  public:
  int Key;
  vector<int>::iterator arg;
};

class Key_distance{
  public:
  int Key;
  int dis;
};

class Graph{
  
 public:

  vector<Key_vector> adjList;
  vector<Key_iterator> pos;
  vector<int> visited;
  vector<Key_distance> distance;
  queue<int> Q;
  int num_vertex;
  int num_visited;
  int num_distance;
  
  //int adjArray[MAX][MAX];


  Graph(){};

  Graph(int n){
    num_vertex=0;
    distance.resize(n);
    visited.resize(n);
    pos.resize(n);
    adjList.resize(n);

  }
  
  void insert(int source , int target){
    int finder,chk=0;

    for(finder=0;finder<adjList.size();finder++){
      if(adjList[finder].Key==source){ 
	chk=1;
	break;
      }
    }
    if(chk==1) adjList[finder].nodelist.push_back(target);
    else{
      adjList[num_vertex].Key = source;
      adjList[num_vertex].nodelist.push_back(target);
      num_vertex++;
    }

  }

  int next(int u){
    
    int finder,chk=0;
    
    for(finder=0;finder<adjList.size();finder++){
      if(adjList[finder].Key==u){ 
	if(pos[finder].arg!=adjList[finder].nodelist.end()) return *pos[finder].arg++;
	else return -1;
      }
    }

   
  }

  void reset(){
    for(int i=0;i<adjList.size();i++){
      pos[i].arg=adjList[i].nodelist.begin();
      pos[i].Key=adjList[i].Key;
    }
  }



};

int TTL,num_reachable,num_node,cases=0;

int Input(void);
int Work(Graph);

void bfs_rec(Graph &g){
  
  int tmp,tmp_dist;
  int adj_node;
  int chk_visit,chk_dist;
 
  while(!g.Q.empty()){

    adj_node = g.Q.front();
    g.Q.pop();

    while((tmp=g.next(adj_node)) != -1){
     
      chk_visit=0;
      chk_dist=0;

      for(int i=0;i<g.num_visited;i++) if(g.visited[i]==tmp){ chk_visit=1; break; }
      for(tmp_dist=0;tmp_dist<g.num_distance;tmp_dist++) if(g.distance[tmp_dist].Key==adj_node){chk_dist=1; break;}
      
      //cout << "tmp = " << tmp << "  tmp_dist = "<< tmp_dist << "  Key = " << g.distance[tmp_dist].Key << "  dis = " << g.distance[tmp_dist].dis <<endl;

      if( chk_visit==0 && g.distance[tmp_dist].dis+1<=TTL){
	
	g.Q.push(tmp);
	g.distance[g.num_distance].dis=g.distance[tmp_dist].dis+1;
	g.distance[g.num_distance].Key=tmp;
	g.visited[g.num_visited]=tmp;

	num_reachable++;
	g.num_visited++;
	g.num_distance++;
	//cout << "tmp = "<< tmp << "  distance = " << g.distance[tmp_dist].dis <<endl;
	
      }

    }

  }

  return;

}

void bfs(Graph g,int source){

  g.reset();

  g.num_distance=0;
  g.num_visited=0;
  g.distance[g.num_distance].Key=source;
  g.distance[g.num_distance].dis=0;
  g.Q.push(source);
  g.visited[g.num_visited]=source;
  g.num_visited++;
  g.num_distance++;
  bfs_rec(g);

  return;

}

main()
{
  while(1){
    num_node=0;
    if(Input()==false) break;
  }
}

int Input(void){

  int num_case,source;
  int tmp,tmp2;
  set<int> tmp_set;
  Graph g(MAX);

 
  cin >> num_case;
  if(num_case==0) return false;
  
  for(int i=0;i<num_case;i++){
    cin >> tmp >> tmp2;
    //assert(tmp<MAX); assert(tmp2<MAX);
    if(tmp==0 && tmp2==0) break;
    else{
      g.insert(tmp,tmp2);
      g.insert(tmp2,tmp);
    }
    tmp_set.insert(tmp);
    tmp_set.insert(tmp2);
  }
  
  num_node = tmp_set.size();


  /*
  for(int i=0;i<g.adjList.size();i++){
    for(int j=0;j<g.adjList[i].nodelist.size();j++){
      cout << "Key = " << g.adjList[i].Key << "  node = " << g.adjList[i].nodelist[j] << endl;
    }   
  }cout << endl;
  */

  while(1){
    num_reachable=0;
    if( Work(g)==false ) break;
  }
  
  return true;

}

int Work(Graph g){

  int source;
  
  cases++;

  cin >> source >> TTL;
  if(source ==0 && TTL==0){cases--; return false; }
  bfs(g,source);
//cout << "node " << num_node << "  reachable " <<num_reachable << endl << endl;
  cout << "Case " << cases << ": " << num_node-num_reachable-1 << " nodes not reachable from node "
       << source << " with TTL = " << TTL <<'.' << endl;

  return true;
}
