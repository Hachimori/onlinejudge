#include<iostream>
#include<vector>
#include<queue>
#include<climits>

#define MAX 105

using namespace std;

class Node{
public:
  int r;
  int e;  

  Node(){}
  Node(int room, int energy) : r(room), e(energy) {}

  bool operator< (const Node &n) const {
     return (e>n.e);
  }

};

class Graph{
public:

  vector< vector<int> > adjList;

  Graph(){}
  Graph(int n){
    adjList.assign(n+1,vector<int>());
  }

  void insert(int source, int target){
    adjList[source].push_back(target);
  }

  vector<int> operator[] (int n) const {
    return adjList[n];
  }

};

Graph g;
int room[MAX];
int nRoom;
bool succeed;
int limit;

void dijkstra(){
  
  int visited[MAX];
  
  for(int i=1;i<=nRoom;i++)
    visited[i]=INT_MIN;


  visited[1] = 100;
  priority_queue<Node> Q;
  Q.push(Node(1,100));


  while(!Q.empty()){
    
    Node curr = Q.top();
    Q.pop();
    

    for(int i=0;i<g.adjList[curr.r].size();i++){
      
      int nextR = g.adjList[curr.r][i];
      int nextE = curr.e+room[nextR];

      if(nextE<=0) continue;
      if(nextR==nRoom){
	succeed=true;
	return;
      }
      if(nextE>=limit+10000) continue;

      if(nextE>visited[nextR]){
	visited[nextR]=nextE;
	Q.push(Node(nextR,nextE));
      }
	 
    }

  }
  
  //for(int i=1;i<=nRoom;i++) cout << visited[i] << ' '; cout << endl;

}

bool read(){
  
  cin >> nRoom;
  if(nRoom==-1) return false;

  g = Graph(nRoom);
  limit = 0;

  for(int i=1;i<=nRoom;i++){
    int energy, nConnect;
    cin >> energy >> nConnect;
    
    room[i] = energy;
    if(energy<0) limit-=energy;

    for(int j=0;j<nConnect;j++){
      int target;
      cin >> target;
      
      g.insert(i,target);
    }

  }
  

  return true;
}

void work(){

  succeed=false;
  
  dijkstra();

  if(succeed) cout << "winnable" << endl;
  else cout << "hopeless" << endl;

}

int main(){

  while(read())
    work();

  return 0;
}
