#include<iostream>
#include<map>
#include<queue>
#include<vector>
#define BUF 12
#define LIMIT 8
using namespace std;

class State{
public:
  int b[2][BUF];
  
  State(){}
  State(int bb[2][BUF]){
    for(int i=0;i<2;i++)
      for(int j=0;j<BUF;j++)
	b[i][j] = bb[i][j];
  }
  
  void copy(int s, int t){
    for(int i=9;i<=11;i++)
      b[t][i] = b[s][i];
  }
  
  void rotate1(int p){
    int t = b[p][0];
    for(int i=0;i<BUF;i+=2)
      b[p][i] = b[p][(i+2)%BUF];
    b[p][10] = t;
    
    t = b[p][1];
    for(int i=1;i<BUF;i+=2)
      b[p][i] = b[p][(i+2)%BUF];
    b[p][11] = t;
    
    copy(p,!p);
  }
  
  void rotate2(int p){
    int t = b[p][BUF-1];
    for(int i=BUF-1;i>=0;i-=2)
      b[p][i] = b[p][(BUF+i-2)%BUF];
    b[p][1] = t;
    
    t = b[p][BUF-2];
    for(int i=BUF-2;i>=2;i-=2)
      b[p][i] = b[p][(BUF+i-2)%BUF];
    b[p][0] = t;
    
    copy(p,!p);
  }
  
  bool operator< (const State &s) const {
    for(int i=0;i<2;i++) 
      for(int j=0;j<BUF;j++)
	if(b[i][j]!=s.b[i][j]) 
	  return b[i][j]<s.b[i][j];
    return false;
  }
};

State init;
map<State,vector<int> > goal;

vector<int> bfs(State s, map<State,vector<int> > &M, map<State,vector<int> > &GM){
  vector<int> ret(1,-1);
  queue<State> Q;

  Q.push(s);
  M[s] = vector<int>();

  while(!Q.empty()){
    State curr = Q.front();
    Q.pop();
    
    vector<int> v = M[curr];
    if(GM.count(curr)){
      vector<int> toCmp = v;
      toCmp.insert(toCmp.end(),GM[curr].rbegin(),GM[curr].rend());
      
      if(ret==vector<int>(1,-1) || (ret.size()==toCmp.size() && ret>toCmp) )
	ret = toCmp;
      continue;
    }
    if(v.size()==LIMIT) continue;
    
    for(int i=0;i<2;i++){
      State next = curr;
      vector<int> nextv = v;
      
      next.rotate1(i);
      if(GM.empty())
      	if(i==0)
	  nextv.push_back(1);
	else
	  nextv.push_back(4);
      else 
	if(i==0)
	  nextv.push_back(3);
	else
	  nextv.push_back(2);

      if(!M.count(next)){
	M[next] = nextv;
	Q.push(next);
      }
      
      next.rotate2(i);
      next.rotate2(i);
      nextv.pop_back();
      if(GM.empty())
	if(i==0)
	  nextv.push_back(3);
	else
	  nextv.push_back(2);
      else 
	if(i==0)
	  nextv.push_back(1);
	else
	  nextv.push_back(4);

      if(!M.count(next)){
	M[next] = nextv;
	Q.push(next);
      }
    }
  }
  
  return ret;
}

void makeTable(){
  int b[][BUF]={{0,3,4,3,0,5, 6,5,0,1,2,1},
		{0,7,8,7,0,9,10,9,0,1,2,1}};

  map<State,vector<int> > empty;
  State s = State(b);
  
  bfs(s,goal,empty);
}

void read(){
  int b[2][BUF];
  
  for(int i=0;i<2;i++)
    for(int j=0;j<BUF;j++)
      cin >> b[i][j];
  
  init = State(b);
}

void work(){
  map<State,vector<int> > M;
  vector<int> ret = bfs(init,M,goal);
  
  if(ret.size()==0)
    cout << "PUZZLE ALREADY SOLVED" << endl;
  else if(ret[0]==-1)
    cout << "NO SOLUTION WAS FOUND IN 16 STEPS" << endl;
  else {
    for(int i=0;i<ret.size();i++)
      cout << ret[i];
    cout << endl;
  }
}

int main(){
  makeTable();
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
