#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>

int num_word;
int source_pos,target_pos;
string source,target;
queue<int> Q;

map<int,string> list;

class Graph{
 public:

  vector< vector<int> > adjList;
  vector< vector<int>::iterator > pos;
  vector<int> visited;
  vector<int> distance;

  Graph(){}

  Graph(int n){
    adjList.assign(n+1,vector<int>());
    pos.assign(n+1,vector<int>::iterator());
    visited.assign(n+1,0);
    distance.assign(n+1,0);
  }

  void reset(){

    for(int i=0;i<=num_word;i++)
      pos[i] = adjList[i].begin();
    
    visited.assign(num_word+1,0);
    distance.assign(num_word+1,0);    

  }

  void insert(int s, int t){
    adjList[s].push_back(t);
  }

  int next(int n){
    if(pos[n]!=adjList[n].end()) return *pos[n]++;
    else return -1;
  }

};

bool word_cmp(int a, int b){

  int counter=0;

  if(list[a].length()!=list[b].length()) return false;
  else{

    for(int i=0;i<list[a].length();i++){
      if(list[a][i]!=list[b][i]) counter++;;
    }

  }

  if(counter==1) return true;
  else return false;

}

void bfs(Graph &g){
  
  while(!Q.empty()) Q.pop();

  g.reset();
  g.distance[source_pos]=0;
  g.visited[source_pos]=1;
  Q.push(source_pos);

  while(true){

    int curr;

    curr = Q.front();
    Q.pop();
    g.visited[curr] = 1;


    while(true){

      int next=g.next(curr);

      if(next==-1) break;
      else if(g.visited[next]==1) continue;
      else if(next == target_pos){
	cout << source << " " << target << " " << g.distance[curr] + 1 << endl;
	return;
      }
      else{
	g.distance[next] = g.distance[curr] + 1;
	Q.push(next);
	g.visited[next] = 1;
      }

    }
  
  }


}

class Solver{

 public:

  void read_dic(){

    num_word=0;

    while(true){
      string word;

      cin >> word;
      if(word.compare("*")==0) break;
      else list[num_word] = word;

      num_word++;

    }

  }

  bool read_word(){
    
    int arg;
    string str;
    
    getline(cin,str);
    if(str.length()==0) return false;
    
    source.erase(source.begin(),source.end());
    target.erase(target.begin(),target.end());

    for(arg=0;str[arg]!=' ';arg++){
      source+=str[arg];
    }arg++;
    for(;arg!=str.length();arg++){
      target+=str[arg];
    }

    for(int i=0;i<list.size();i++){
      if(list[i].compare(source)==0){
	source_pos = i;
	break;
      }
    }
    for(int i=0;i<list.size();i++){
      if(list[i].compare(target)==0){
	target_pos = i;
	break;
      }
    }

    return true;
  }

  void make_node(Graph &g){

    for(int i=0;i<num_word;i++){
      for(int j=i+1;j<num_word;j++){
	if(word_cmp(i,j)==true){
	  g.insert(i,j);
	  g.insert(j,i);
	}
      }
    }

  }

  void work(Graph &g){
    bfs(g);
  }

};

main(){

  Solver solver;
  int cases;
  string str;
  Graph g;

  cin >> cases;
  
  for(int i=0;i<cases;i++){

    if(i!=0) cout << endl;

    solver.read_dic();

    g = Graph(num_word);

    solver.make_node(g);
    
    getline(cin,str);

    while(true){
      if(solver.read_word()==false) break;
      solver.work(g);
    }

  }

}
