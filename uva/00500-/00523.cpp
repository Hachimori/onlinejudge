#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<string>
#include<cstdio>

#define MAX 600

class Node{
 public:

  int target;
  int weight;

  Node(){}

  Node(int t, int w): target(t), weight(w){}

  bool operator< (const Node &node) const{
    if(weight>node.weight) return true;
    else return false;
  }
 
};

class Graph{
 public:

  vector< vector<Node> > adjList;
  vector< vector<Node>::iterator > pos;
  vector<int> visited;
  vector<int> distance;
  vector<int> PI;
  vector<int> tax;

  Graph(){}
  Graph(int n){
    tax.assign(n+1,0);
    adjList.assign(n+1,vector<Node>());
    pos.assign(n+1,vector<Node>::iterator());
  }

  void reset(int n){
    for(int i=1;i<=n;i++)
      pos[i] = adjList[i].begin();
    visited.assign(n+1,false);
    distance.assign(n+1,INT_MAX);
    PI.assign(n+1,-1);
  }

  void insert(int source, int target, int weight){
    adjList[source].push_back(Node(target,weight));
  }

  Node next(int n){
    if(pos[n]!=adjList[n].end()) return *pos[n]++;
    else return Node(-1,-1);
  }

};


int num_node;

void dijkstra(Graph &g, int start){
  
  priority_queue<Node> Q;

  g.reset(num_node);
  g.distance[start] = 0;

  Q.push(Node(start,g.distance[start]));

  
  while(!Q.empty()){
    
    Node curr = Q.top();
    Q.pop();

    if(g.visited[curr.target]==true) continue;
    else g.visited[curr.target]=true;


    while(true){
      
      Node next = g.next(curr.target);
      
      if(next.target==-1) break;
      else if(g.distance[next.target]>g.distance[curr.target]+next.weight+g.tax[next.target]){
	g.distance[next.target] = g.distance[curr.target]+next.weight+g.tax[next.target];
	g.PI[next.target] = curr.target;
	
	Q.push(Node(next.target,g.distance[next.target]));
      }

    }
    
  }

}

class Solver{
 public:

  void read(Graph &g){

    string str;
    getline(cin,str);

    queue<int> Q;    

    int arg=0;
    for(num_node=0;arg<str.length();arg++,num_node++){
      bool isMinus=false;
      
      while(str[arg]==' ' && arg<str.length()) arg++;
      
      if(str[arg]=='-'){ 
	isMinus=true;
	arg++;
      }
      int num=0;
      for(;str[arg]!=' ' && arg<str.length();arg++){
	num*=10;
	num+=str[arg]-'0';
      }
      if(isMinus==true) num*=(-1);
      Q.push(num);

      while(str[arg]==' ' && arg<str.length()) arg++;
      arg--;
    }

    g = Graph(num_node);

    for(int i=1;i<=num_node;i++){
      int cost = Q.front();
      Q.pop();
      if(cost!=-1) g.insert(1,i,cost);
    }

    for(int i=2;i<=num_node;i++){
      for(int j=1;j<=num_node;j++){
	int cost;
	cin >> cost;
	if(cost!=-1) g.insert(i,j,cost);
      }
    }
    

    for(int i=1;i<=num_node;i++)
      cin >> g.tax[i];

  }

  void work(Graph &g){
    
    string str;
    int start,goal;
    int PI_list[MAX][MAX];
    int answer_list[MAX][MAX];

    for(int i=1;i<=num_node;i++){
      dijkstra(g,i);
      for(int j=1;j<=num_node;j++){
	answer_list[i][j] = g.distance[j];
	PI_list[i][j] = g.PI[j];
      }
    }

    while(true){
      getline(cin,str);
      if(str.length()==0) break;
      
      sscanf(str.c_str(),"%d%d",&start,&goal);
      
      cout << "From " << start << " to " << goal << " :" << endl;
      
      if(start==goal){
	cout << "Path: " << start << "-->" << goal << endl;
	cout << "Total cost : " << 0 << endl;
	cout << endl;
	continue;
      }

      int arg=goal;
      int cource[MAX];
      int num_visited;
      for(num_visited=0;arg!=start;num_visited++){
	cource[num_visited] = arg;
	int tmp = PI_list[start][arg];
	arg = tmp;
      }
      
      cout << "Path: " << start << "-->";
      for(num_visited--;num_visited>=0;num_visited--){
	if(num_visited!=0) cout << cource[num_visited] << "-->";
	else cout << cource[num_visited] << endl;
      }

      cout << "Total cost : " << answer_list[start][goal]-g.tax[goal] << endl;
      cout << endl;
    }

    return;
  }

};

int main(){
  Solver solver;
  Graph g;
  int cases;

  cin >> cases;

  string str;
  getline(cin,str); 
  getline(cin,str);

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;

    solver.read(g);
    getline(cin,str);
    solver.work(g);
    
  }
  

}
