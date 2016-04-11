#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<map>

#define MAX_NODE 100

using namespace std;

class State{
public:
  
  long long target, item;
  vector<char> path;

  State(){}
  State(long long t, long long i, vector<char> p): target(t), item(i), path(p){}

  bool isBetter(const State &s){
    
    if(item<s.item) return true;
    else if(item==s.item){
      for(int i=s.path.size()-1,j=path.size()-1;i>=0 && j>=0;i--,j--){
	if(path[j]<s.path[i]) return true;
	if(path[j]>s.path[i]) return false;
      }
      
      return (path.size()<s.path.size());
    }
    

    return false;
  }
  
};

long long nNode, initItem;

map<char,long long> nodeToInt;
char start, goal, intToChar[MAX_NODE];
bool adjList[MAX_NODE][MAX_NODE];

bool read(){
  
  int nEdge;
  cin >> nEdge;
  if(nEdge==-1) return false;
  
  nNode=0;
  nodeToInt.clear();
  for(int i=0;i<MAX_NODE;i++)
    for(int j=0;j<MAX_NODE;j++)
      adjList[i][j] = false;

  for(int i=0;i<nEdge;i++){
    char source, target;
    cin >> source >> target;

    if(nodeToInt.find(source)==nodeToInt.end()){
      intToChar[nNode] = source;
      nodeToInt[source] = nNode;
      nNode++;
    }
    if(nodeToInt.find(target)==nodeToInt.end()){
      intToChar[nNode] = target;
      nodeToInt[target] = nNode;
      nNode++;
    }

    adjList[nodeToInt[source]][nodeToInt[target]] = true;
    adjList[nodeToInt[target]][nodeToInt[source]] = true;
    
  }

  cin >> initItem >> goal >> start;

  return true;
}

void dijkstra(int cases){

  bool visited[MAX_NODE];
  State fromDistance[MAX_NODE];
  int nConnected=0;

  for(int i=0;i<nNode;i++){
    fromDistance[i]=State(0,UINT_MAX,vector<char>());
    visited[i] = false;
  }

  
  fromDistance[nodeToInt[start]] = State(0,initItem,vector<char>());
  fromDistance[nodeToInt[start]].path.push_back(start);

  
  while(nConnected<nNode){
    /*
    for(int i=0;i<nNode;i++){
      cout << fromDistance[i].item << ' ';
    }cout << endl;
    */
    State minElement=State(0,UINT_MAX,vector<char>());
    int minPos;

    for(int i=0;i<nNode;i++){
      if(!visited[i] && fromDistance[i].isBetter(minElement)){
	minPos = i;
	minElement = fromDistance[i];
      }
    }
    
    nConnected++;
    visited[minPos] = true;

    for(int i=0;i<nNode;i++){
      if(visited[i] || !adjList[minPos][i]) continue;
      
      State nextState=fromDistance[minPos];
      nextState.path.push_back(intToChar[i]);
      
      if(isupper(intToChar[minPos])){
	if(fromDistance[minPos].item%19==0)
	  nextState.item = 20*(fromDistance[minPos].item)/19;
	else 
	  nextState.item = 20*fromDistance[minPos].item/19+1;
      }
      else 
	nextState.item = fromDistance[minPos].item+1;

      if(nextState.isBetter(fromDistance[i]))
	fromDistance[i] = nextState;
    }
    
  }
  

  cout << "Case " << cases << ":" << endl;
  cout << fromDistance[nodeToInt[goal]].item << endl;
  for(int i=fromDistance[nodeToInt[goal]].path.size()-1;i>=0;i--){
    if(i==fromDistance[nodeToInt[goal]].path.size()-1) 
      cout << fromDistance[nodeToInt[goal]].path[i];
    else 
      cout << '-' << fromDistance[nodeToInt[goal]].path[i];
  }
  cout << endl;

}

void work(int cases){
  /*
  for(int i=0;i<nNode;i++)
    cout << intToChar[i] << ' ';
  cout << endl << endl;;

  for(map<char,int>::iterator i=nodeToInt.begin();i!=nodeToInt.end();i++){
    cout << i->first << ' ' << i->second << endl;
  }cout << endl;
  */
  dijkstra(cases);
  
}

int main(){

  for(int cases=1;read();cases++)
    work(cases);

  return 0;
}
