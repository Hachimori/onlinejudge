#include<iostream>
#include<climits>
#include<vector>
#include<cmath>
#include<queue>

#define DARK 0
#define LIGHT 1
#define MAN 2

#define MOVE 0
#define OFF 1
#define ON 2

#define NUM_DOOR 13
#define MAX_STATE 2000000

using namespace std;

class Action{
public:
  int ope;
  int source, target;

  Action(){}
  Action(int ope, int source, int target): ope(ope), source(source), target(target) {}
};

class State{
public:

  int hash;
  vector<Action> path;

  State(){}
  State(int h, vector<Action> p): hash(h), path(p){}
};

int nRoom;
bool adjDoor[NUM_DOOR][NUM_DOOR];
bool adjLight[NUM_DOOR][NUM_DOOR];

bool read(){
  
  int nDoor, nLight;

  cin >> nRoom >> nDoor >> nLight;
  if(nRoom==0 && nDoor==0 && nLight==0) return false;

  for(int i=0;i<=nRoom;i++)
    for(int j=0;j<=nRoom;j++){
      adjDoor[i][j] = false;
      adjLight[i][j] = false;
    }

  for(int i=0;i<nDoor;i++){
    int source, target;
    cin >> source >> target;
    adjDoor[source][target] = true;
    adjDoor[target][source] = true;
  }

  for(int i=0;i<nLight;i++){
    int source, target;
    cin >> source >> target;
    adjLight[source][target] = true;
  }  

  return true;

}

void hashToState(int hash, int room[NUM_DOOR]){
  
  for(int i=0;i<=nRoom;hash/=3,i++){
    room[i] = hash%3;
  }
  
}

void calcManPos(int hash, int &manPos){

  for(int i=0;i<=nRoom;hash/=3,i++){
    if(hash%3==MAN){
      manPos = i;
      break;
    }
  }

}

bool isGoal(State state, int cases){
  //cout << state.hash << endl;
  for(int i=0;i<=nRoom-1;i++,state.hash/=3)
    if(state.hash%3!=DARK) return false;
  
  if(state.hash%3==MAN){ 
    cout << "Villa #" << cases << endl;
    cout << "The problem can be solved in " << state.path.size() << " steps:" << endl;
    for(int i=0;i<state.path.size();i++){
      switch(state.path[i].ope){
      case MOVE:
	cout << "- Move to room " << state.path[i].target << "." << endl;
	break;
      case ON:
	cout << "- Switch on light in room " << state.path[i].target << "." << endl;
	break;
      case OFF:
	cout << "- Switch off light in room " << state.path[i].target << "." << endl;
	break;
      }
    }
    return true;
  }


  return false;
}

int fromDistance[MAX_STATE];

void bfs(int cases){

  queue<State> Q;
  
  for(int i=0;i<MAX_STATE;i++)
    fromDistance[i] = INT_MAX;

  Q.push(State(MAN*3,vector<Action>()));
  fromDistance[MAN*3] = 0;
  
  
  while(!Q.empty()){
    
    State curr=Q.front();
    Q.pop();
    
    if(isGoal(curr,cases)) return;
    
    int roomState[NUM_DOOR];
    int manPos;

    hashToState(curr.hash,roomState);
    calcManPos(curr.hash,manPos);
    
    for(int i=1,p=3;i<=nRoom;i++,p*=3){
      if(adjDoor[manPos][i] && roomState[i]==LIGHT){
	State next = curr;
	next.hash += MAN*p;
	next.hash -= LIGHT*p;
	next.hash += LIGHT*(int)(pow((double)3,(double)manPos)+0.5);
	next.hash -= MAN*(int)(pow((double)3,(double)manPos)+0.5);
	
	next.path.push_back(Action(MOVE,manPos,i));
	
	if(fromDistance[next.hash]>fromDistance[curr.hash]+1){
	  Q.push(next);
	  fromDistance[next.hash]=fromDistance[curr.hash]+1;
	}
      }	
    }  
    
    for(int i=1,p=3;i<=nRoom;i++,p*=3){
      if(adjLight[manPos][i]){
	State next = curr;
	
	if(roomState[i]==DARK){
	  next.hash += LIGHT*p;
	  next.hash -= DARK*p;
	  next.path.push_back(Action(ON,manPos,i));
	}
	else if(roomState[i]==LIGHT){
	  next.hash += DARK*p;
	  next.hash -= LIGHT*p;
	  next.path.push_back(Action(OFF,manPos,i));	  
	}

	if(fromDistance[next.hash]>fromDistance[curr.hash]+1){
	  Q.push(next);
	  fromDistance[next.hash]=fromDistance[curr.hash]+1;
	}
      }	
    }    

  }
  
  cout << "Villa #" << cases << endl;
  cout << "The problem cannot be solved." << endl;

}

void work(int cases){

  bfs(cases);

  cout << endl;
}

int main(){

  for(int cases=1;read();cases++)
    work(cases);

  return 0;
}
