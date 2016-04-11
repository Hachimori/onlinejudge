#include<iostream>
#include<string>
#include<vector>
#include<map>


class Graph{
 public:

  vector< vector<int> > adjList;
  vector< vector<int>::iterator > pos;
  vector<int> awake;
  
  Graph(){}

  Graph(int n){
    adjList.assign(n+1,vector<int>());
    pos.assign(n+1,vector<int>::iterator());
    awake.assign(n+1,false);
  }

  void reset(int n){
    for(int i=0;i<=n;i++)
      pos[i] = adjList[i].begin();
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
int num_year;
map<char,int> name_list;
map<int,char> num_list;


bool check_brain(Graph &g){
  for(int i=0;i<num_node;i++)
    if(g.awake[i]==false) return false;
  
  return true;
}

void search(Graph &g){
  
  bool flg;
  vector<int> backup_awake;

  while(check_brain(g)==false){
    backup_awake.assign(num_node+1,false);
    g.reset(num_node);
    
    for(int i=0;i<num_node;i++)
      backup_awake[i] = g.awake[i];

    flg=false;
    for(int i=0;i<num_node;i++){
      if(g.awake[i]==true) continue;

    
      int counter=0;
      while(true){
	int next = g.next(i);
	if(next==-1) break;
	else if(g.awake[next]==true) counter++;
      }
      
      if(counter>=3){ 
	backup_awake[i]=true;
	flg=true;
      }

    }
    
    if(flg==false){ num_year=-1; return; }
    
    for(int i=0;i<num_node;i++)
      g.awake[i] = backup_awake[i];

    num_year++;
  }
  
}

class Solver{
 public:

  void init(){
    name_list.clear();
    num_list.clear();
  }

  bool read(Graph &g){
    
    string str;
    int num_connection;
    int curr_num_node=0;

    cin >> num_node;
    if(cin.eof()) return false;
    

    g = Graph(num_node);

    cin >> num_connection;
    cin >> str;
    
    if(name_list.find(str[0])==name_list.end()){ 
      name_list[str[0]]=curr_num_node;
      num_list[curr_num_node] = str[0];
      curr_num_node++;
    }
    if(name_list.find(str[1])==name_list.end()){ 
      name_list[str[1]]=curr_num_node;
      num_list[curr_num_node] = str[1];
      curr_num_node++;
    }
    if(name_list.find(str[2])==name_list.end()){ 
      name_list[str[2]]=curr_num_node;
      num_list[curr_num_node] = str[2];
      curr_num_node++;
    }
    
    g.awake[name_list[str[0]]]=true;
    g.awake[name_list[str[1]]]=true;
    g.awake[name_list[str[2]]]=true;

    for(int i=0;i<num_connection;i++){
      int source,target;
      cin >> str;
      
      if(name_list.find(str[0])==name_list.end()){ 
	name_list[str[0]]=curr_num_node;
	num_list[curr_num_node] = str[0];
	curr_num_node++;
      }
      if(name_list.find(str[1])==name_list.end()){ 
	name_list[str[1]]=curr_num_node;
	num_list[curr_num_node] = str[1];
	curr_num_node++;
      }      
      

      source=name_list[str[0]], target=name_list[str[1]];
      g.insert(source,target);
      g.insert(target,source);
    }

    return true;
  }

  void work(Graph &g){
    
    num_year=0;
    
    search(g);

    if(num_year==-1) cout << "THIS BRAIN NEVER WAKES UP" << endl;
    else cout << "WAKE UP IN, " << num_year << ", YEARS" << endl;
  }

};

main(){

  Solver solver;
  Graph g;

  while(true){
    solver.init();
    if(solver.read(g)==false) break;
    solver.work(g);
  }

}
