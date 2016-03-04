#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<cassert>
#include<map>

#define MAX_PIPE 5
#define MAX_SIZE 25
#define MAX_STATE 1100000

using namespace std;

class Element{
public:

  int pos, nPut, nProcess;

  Element(){}
  Element(int pos, int nPut, int nProcess): pos(pos), nPut(nPut), nProcess(nProcess) {}
  
};

class State{
public:
  
  int size;
  bool board[MAX_PIPE][MAX_SIZE];

  State(){};
  
  bool operator< ( State const &s ) const {
    
    for(int i=0;i<MAX_PIPE;i++){
      for(int j=0;j<size;j++){
	if(board[i][j] && !s.board[i][j]) return true;
	if(!board[i][j] && s.board[i][j]) return false;
      }
    }
    
    return false;
  }
  
};

int nColumn;
int nState;
bool isBusy[MAX_PIPE][MAX_SIZE];
int visited[MAX_STATE];
vector< pair<int,int> > g[MAX_STATE];

bool read(){
  
  cin >> nColumn;
  if(nColumn==0) return false;
  
  for(int i=0;i<MAX_PIPE;i++){
    for(int j=0;j<nColumn;j++){
      char c;
      cin >> c;
      
      if(c=='.') isBusy[i][j] = false;
      else isBusy[i][j] = true;
    }
  }
  
  return true;
}

void constractGraph(int curr, vector< pair<int,int> > g[MAX_STATE], bool schedule[MAX_PIPE][MAX_SIZE*4], map<State,int> &visited){
  
  int currState=nState;
  int maxBusy=-1;
  bool putAble=true;
  State el;

  el.size = nColumn;
  
  for(int i=0;i<MAX_PIPE;i++)
    for(int j=0;j<nColumn;j++){
      el.board[i][j]=schedule[i][j+curr];
      
      if(schedule[i][j+curr] && isBusy[i][j]){
	putAble=false;
	
      }
    }

  if(putAble){

    
    for(int i=0;i<MAX_PIPE;i++)
      for(int j=0;j<nColumn;j++)
	if(isBusy[i][j]){
	  schedule[i][j+curr]=true;
	  el.board[i][j]=true;
	}
    
    if(visited.find(el)==visited.end()){
      visited[el] = nState+1;
      g[currState].push_back( make_pair(nState+1,1) );
      nState++;
      constractGraph(curr+1,g,schedule,visited);
    }
    else {
      g[currState].push_back( make_pair(visited[el],1) );
    }
    
    for(int i=0;i<MAX_PIPE;i++)
      for(int j=0;j<nColumn;j++)
	if(isBusy[i][j]){
	  schedule[i][j+curr]=false; 
	  el.board[i][j]=false;
	}
  }
  
  //if(currState==0) return;
  
  if(visited.find(el)==visited.end()){
      visited[el]=nState+1;
      g[currState].push_back( make_pair(nState+1,0) );
      nState++;
      constractGraph(curr+1,g,schedule,visited);
  }
  else {
    g[currState].push_back( make_pair(visited[el],0) );
  }

}

void bfs(vector< pair<int,int> > g[MAX_STATE]){
  
  int ans=INT_MAX;
  queue< Element > Q;
  
  fill(visited,visited+MAX_STATE,-1);
  
  Q.push(Element(0,0,0));
  
  while(!Q.empty()){
    
    Element curr=Q.front();
    Q.pop();
   
    if(visited[curr.pos]>=curr.nPut) continue;
    visited[curr.pos] = curr.nPut;
    
    
    if(curr.nPut==10){
      ans = curr.nProcess;
      break;
    }
    
    for(int i=0;i<g[curr.pos].size();i++){
      
      Element next=curr;
      
      next.pos=g[curr.pos][i].first;
      next.nPut+=g[curr.pos][i].second;
      next.nProcess++;
      
      Q.push(next);
    }
    
  }
  
  cout << ans+nColumn-1 << endl;
  
}

void work(){
  
  if(nColumn==1){
    cout << 10 << endl;
    return;
  }
  
  map<State,int> visited;
  nState=0;
  bool schedule[MAX_PIPE][MAX_SIZE*4];
  
  for(int i=0;i<MAX_PIPE;i++)
    for(int j=0;j<MAX_SIZE*4;j++)
      schedule[i][j] = false;
  
  fill(g,g+MAX_STATE,vector< pair<int,int> >() );
  
  constractGraph(0,g,schedule,visited);
  
  bfs(g);
  
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
