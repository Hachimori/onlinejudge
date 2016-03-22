#include<iostream>
#include<string>
#include<cstdio>
#include<queue>
#include<climits>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define MAX_SIZE 11

using namespace std;

class State{
public:

  int targetC, targetR, bottom, left, front;

  State(){}
  State(int r, int c, int b, int l, int f)
    : targetR(r), targetC(c), bottom(b), left(l), front(f) {}

  bool operator== ( const State &s ) {
    return (targetC==s.targetC && targetR==s.targetR 
	    && bottom==s.bottom && left==s.left && front==s.front);
  }

};

int row, column;
int startR, startC, goalR, goalC;
bool wallExist[MAX_SIZE][MAX_SIZE][4];

void read(){
  
  cin >> column >> row;
  cin >> startC >> startR >> goalC >> goalR;
  
  for(int i=0;i<=row;i++)
    for(int j=0;j<=column;j++)
      for(int k=0;k<4;k++)
	wallExist[i][j][k] = false;
  
  string str; 
  while(true){
    getline(cin,str);
    if(str=="v") break;
  }


  while(true){
    getline(cin,str);
    if(str=="h") break;
    
    int c,r;
    sscanf(str.c_str(),"%d%d",&c,&r);

    wallExist[r][c][RIGHT] = true;
    wallExist[r][c+1][LEFT] = true;
  }

  while(true){
    if(getline(cin,str)==NULL) break;
    if(str.empty()) break;
    
    int c,r;
    sscanf(str.c_str(),"%d%d",&c,&r);
    
    wallExist[r][c][UP] = true;
    wallExist[r+1][c][DOWN] = true;
  }

}

bool isInside(int c, int r){
  return (1<=c && c<=column && 1<=r && r<=row);
}

void bfs(){
  
  // up, right, down, left
  static const int rMove[4]={1,0,-1,0}, cMove[4]={0,1,0,-1};

  // row, column, bottom, left, front 
  int fromDistance[MAX_SIZE][MAX_SIZE][7][7][7];
  State goal=State(goalR,goalC,6,4,2);
  queue<State> Q;

  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++)
      for(int k=0;k<7;k++)
	for(int l=0;l<7;l++)
	  for(int m=0;m<7;m++)
	    fromDistance[i][j][k][l][m] = INT_MAX;
  
  fromDistance[startR][startC][6][4][2] = 0;
  Q.push(State(startR,startC,6,4,2));
  

  while(!Q.empty()){

    State curr = Q.front();
    Q.pop();    

    //cout << curr.targetR << ' ' << curr.targetC << endl;

    if(curr.targetR==goalR && curr.targetC==goalC 
       && curr.bottom==6){
      cout << fromDistance[goalR][goalC][6][curr.left][curr.front] << endl;
      return;
    }

    for(int i=0;i<4;i++){
      State next;
      next.targetC=curr.targetC+cMove[i];
      next.targetR=curr.targetR+rMove[i];
      
      if(!isInside(next.targetC,next.targetR)) continue;
      if( wallExist[curr.targetR][curr.targetC][i] ) continue;
      
      //cout << next.targetC << ' ' << next.targetR << endl;

      if(i==UP){
	next.left = curr.left;
	next.bottom = 7-curr.front;
	next.front = curr.bottom;
      }
      if(i==RIGHT){
	next.left = curr.bottom;
	next.bottom = 7-curr.left;
	next.front = curr.front;	
      } 
      if(i==DOWN){
	next.left = curr.left;
	next.bottom = curr.front;
	next.front = 7-curr.bottom;	
      }
      if(i==LEFT){
	next.left = 7-curr.bottom;
	next.bottom = curr.left;
	next.front = curr.front;	
      } 
      
      if(fromDistance[next.targetR][next.targetC][next.bottom][next.left][next.front]
	 >fromDistance[curr.targetR][curr.targetC][curr.bottom][curr.left][curr.front]+1){
	
	fromDistance[next.targetR][next.targetC][next.bottom][next.left][next.front]
	  = fromDistance[curr.targetR][curr.targetC][curr.bottom][curr.left][curr.front]+1;
	
	Q.push(next);
      }

    }

  }

  cout << "No solution" << endl;
}

void work(){
  
  bfs();

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
