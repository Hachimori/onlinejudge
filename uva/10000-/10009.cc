#include<iostream>
#include<string>
#include<climits>
#include<map>
#include<vector>
#include<queue>

#define MAX_NODE 1000

using namespace std;

class Element{
public:
  
  int target;
  vector<int> path;

  Element(){}
  Element(int t, vector<int> p): target(t), path(p){}

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

  vector<int> operator[] ( int n ){
    return adjList[n];
  }

};

Graph g;
int nNode, nQuery;
map<string,int> nameToInt;
map<int,string> intToName;

void read(){

  nameToInt.clear();
  intToName.clear();

  g = Graph(MAX_NODE);

  int nEdge;
  cin >> nEdge >> nQuery;
  
  nNode=0;

  for(int i=0;i<nEdge;i++){
    string source, target;
    cin >> source >> target;
    
    if(nameToInt.find(source)==nameToInt.end()){
      nameToInt[source] = nNode;
      intToName[nNode] = source;
      nNode++;
    }
    if(nameToInt.find(target)==nameToInt.end()){
      nameToInt[target] = nNode;
      intToName[nNode] = target;
      nNode++;
    }    
    
    g.insert(nameToInt[source],nameToInt[target]);
    g.insert(nameToInt[target],nameToInt[source]);    
					 
  }
  
  /*
  map<string,int>::iterator i, begin=nameToInt.begin(), end=nameToInt.end();
  for(i=begin;i!=end;i++){
    cout << (*i).first << ' '<< (*i).second << endl;
  }
  */

}

void bfs(int start, int goal){
  
  //cout << start << ' ' << intToName[start] << endl;

  int fromDistance[MAX_NODE];
  bool visited[MAX_NODE];
  queue<Element> Q;
  vector<int> initial;


  initial.push_back(start);  
  Q.push(Element(start,initial));

  for(int i=0;i<nNode;i++){
    visited[i] = false;
    fromDistance[i] = INT_MAX;
  }

  
  while(!Q.empty()){
    
    Element curr=Q.front();
    Q.pop();

    if(curr.target==goal){
      for(int i=0;i<curr.path.size();i++){
	cout << intToName[curr.path[i]][0];
      }cout << endl;
      return;
    }

    if(visited[curr.target]) continue;
    else visited[curr.target] = true;

    for(int i=0;i<g[curr.target].size();i++){
      int next = g[curr.target][i];
      vector<int> nextPath=curr.path;
      
      nextPath.push_back(next);

      if(visited[next]) continue;

      if(fromDistance[next]>fromDistance[curr.target]+1){
	fromDistance[next] = fromDistance[curr.target]+1;
	Q.push(Element(next,nextPath));
      }
      
    }

  }

}

void work(){

  for(int i=0;i<nQuery;i++){
    string start, goal;
    cin >> start >> goal;
    
    bfs(nameToInt[start],nameToInt[goal]);
  }

}

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }

  return 0;
}
