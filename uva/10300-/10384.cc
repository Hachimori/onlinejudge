// ó‘Ô‚ğ•Û‘¶‚µ‚ÄBFS

#include<iostream>
#include<cassert>
#include<set>
#include<string>
#include<queue>

#define ROW 4
#define COLUMN 6
#define WEST 0
#define NORTH 1
#define EAST 2
#define SOUTH 3

using namespace std;

class Point{
public:

  int r, c;

  Point(){}
  Point(int r, int c): r(r), c(c){}

  bool operator< ( const Point &p ) const {
    if(r==p.r) return c<p.c;
    return r<p.r;
  }
};

class State{
public:
  
  Point pos;
  int board[ROW][COLUMN];
  string path;
  
  State(){}
  
  bool operator< ( const State &s ) const {
    for(int i=0;i<ROW;i++)
      for(int j=0;j<COLUMN;j++){
	if(board[i][j]==s.board[i][j]) continue;
	return board[i][j]<s.board[i][j];
      }
    
    return pos<s.pos;
  }
};

Point init;
int board[ROW][COLUMN];
char int2c[4]={'W','N','E','S'};

bool read(){
  cin >> init.c >> init.r;
  if(init.r==0 && init.c==0) return false;
  
  init.r--, init.c--;

  for(int i=0;i<ROW;i++)
    for(int j=0;j<COLUMN;j++)
      cin >> board[i][j];
  
  return true;
}

bool isInside(const Point &p){
  return 0<=p.r && p.r<ROW && 0<=p.c && p.c<COLUMN;
}

void bfs(){
  const static int dr[4]={0,-1,0,1}, dc[4]={-1,0,1,0};
  State toPush;  
  queue<State> Q;
  set<State> visited;
  
  for(int i=0;i<ROW;i++)
    for(int j=0;j<COLUMN;j++)
      toPush.board[i][j] = board[i][j];
  toPush.pos = init;
  
  Q.push(toPush);

  while(!Q.empty()){
    State curr = Q.front();
    Q.pop();
    
    if(!isInside(curr.pos)){
      cout << curr.path << endl;
      break;
    }
    if(visited.count(curr)) continue;
    visited.insert(curr);
    
    for(int i=0;i<4;i++){
      State next = curr;
      
      next.pos.r += dr[i];
      next.pos.c += dc[i];
      next.path += int2c[i];
      
      if(isInside(next.pos)){
	if( (curr.board[curr.pos.r][curr.pos.c]&(1<<i)) != 0 &&
	    (curr.board[next.pos.r][next.pos.c]&(1<<i)) == 0 ){ // •Ç‚ğ‰Ÿ‚·
	  
	  next.board[next.pos.r][next.pos.c] |= (1<<i);
	  next.board[next.pos.r][next.pos.c] &= ~(1<<((i+2)%4));
	  next.board[curr.pos.r][curr.pos.c] &= ~(1<<i);
	  
	  if(isInside(Point(next.pos.r+dr[i],next.pos.c+dc[i])))
	    next.board[next.pos.r+dr[i]][next.pos.c+dc[i]] |= (1<<((i+2)%4));
	  
	  Q.push(next);
	}
	else if( (curr.board[curr.pos.r][curr.pos.c]&(1<<i)) == 0 ){ //‚»‚Ì‚Ü‚ÜˆÚ“®
	  Q.push(next);
	}
      }
      else if((curr.board[curr.pos.r][curr.pos.c]&(1<<i)) == 0){  //ƒS[ƒ‹
	Q.push(next);
      }
    }
  }
 
}

void work(){
  bfs();
}

int main(){
  while(read())
    work();
  
  return 0;
}
