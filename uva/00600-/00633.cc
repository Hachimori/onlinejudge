#include<iostream>
#include<climits>
#include<queue>

#define KNIGHT 0
#define BISHOP 1
#define TELEP 2
#define MAX_SIZE 44

using namespace std;

int size;
int initR, initC, goalR, goalC;

int board[MAX_SIZE][MAX_SIZE][3];

class Point{
public:

  int r, c, lastMove;

  Point(){}
  Point(int r, int c, int l) : r(r), c(c), lastMove(l){}
  
};

bool read(){
  
  cin >> size;
  if(size==0) return false;

  cin >> initR >> initC >> goalR >> goalC;

  for(int i=0;i<size*2+2;i++)
    for(int j=0;j<size*2+2;j++)
      for(int k=0;k<3;k++)
	board[i][j][k]=INT_MAX;

  while(true){
    int r, c;
    cin >> r >> c;
    if(r==0 && c==0) break;

    board[r][c][KNIGHT]=board[r][c][BISHOP]=board[r][c][TELEP]=-1;
  }

  return true;
}

bool isInside(int r, int c){
  return (1<=r && r<=size*2 && 1<=c && c<=size*2);
}

void bfs(int initR, int initC){
  
  static const int rbMove[4]={-2,-2,2,2}, cbMove[4]={-2,2,2,-2};
  static const int rkMove[8]={-2,-2,-1,1,2,2,1,-1};
  static const int ckMove[8]={-1,1,2,2,1,-1,-2,-2};
  
  queue<Point> Q;

  board[initR][initC][KNIGHT] = 0;
  board[initR][initC][BISHOP] = 0;
  board[initR][initC][TELEP] = 0;
  Q.push(Point(initR,initC,KNIGHT));
  Q.push(Point(initR,initC,BISHOP));
  Q.push(Point(initR,initC,TELEP));
  
  
  while(!Q.empty()){
    Point curr = Q.front();
    Q.pop();

    
    // telep の動きをする
    if(curr.lastMove==KNIGHT || curr.lastMove==BISHOP){
      int rtMove[2], ctMove[2];
      
      rtMove[1]=0,ctMove[0]=0;
      
      if(curr.r<=size) rtMove[0]=(size-(curr.r-1))*2-1;
      else rtMove[0]=(-1)*((size-(curr.r-1))*2-1);
      
      if(curr.c<=size) ctMove[1]=(size-(curr.c-1))*2-1;
      else ctMove[1]=(-1)*((size-(curr.c-1))*2-1);
      
      for(int i=0;i<2;i++){
	Point next = Point(curr.r+rtMove[i],curr.c+ctMove[i],TELEP);
	
	if(isInside(next.r,next.c)){	  
	  if(next.r==goalR && next.c==goalC) {
	    cout << "Result : " << board[curr.r][curr.c][curr.lastMove]+1 << endl;
	    return ;
	  }
	  
	  if(board[next.r][next.c][next.lastMove]>board[curr.r][curr.c][curr.lastMove]+1){
	    board[next.r][next.c][next.lastMove]=board[curr.r][curr.c][curr.lastMove]+1;
	    Q.push(next);
	  }
	}
      }

    }
    
    // bishop の動きをする
    if(curr.lastMove==KNIGHT || curr.lastMove==TELEP){

      for(int i=0;i<4;i++){
	Point next = Point(curr.r+rbMove[i],curr.c+cbMove[i],BISHOP);
	
	if(isInside(next.r,next.c)){	  
	  if(next.r==goalR && next.c==goalC) {
	    cout << "Result : " << board[curr.r][curr.c][curr.lastMove]+1 << endl;
	    return ;
	  }
	  
	  if(board[next.r][next.c][next.lastMove]>board[curr.r][curr.c][curr.lastMove]+1){
	    board[next.r][next.c][next.lastMove]=board[curr.r][curr.c][curr.lastMove]+1;
	    Q.push(next);
	  }
	}
      }
      
    }

    // knight の動きをする
    if(curr.lastMove==BISHOP || curr.lastMove==TELEP){
            
      for(int i=0;i<8;i++){
	Point next = Point(curr.r+rkMove[i],curr.c+ckMove[i],KNIGHT);
	
	if(isInside(next.r,next.c)){	  
	  if(next.r==goalR && next.c==goalC) {
	    cout << "Result : " << board[curr.r][curr.c][curr.lastMove]+1 << endl;
	    return ;
	  }
	  
	  if(board[next.r][next.c][next.lastMove]>board[curr.r][curr.c][curr.lastMove]+1){
	    board[next.r][next.c][next.lastMove]=board[curr.r][curr.c][curr.lastMove]+1;
	    Q.push(next);
	  }
	}
      
      }
    } 
    
  }
  

  cout << "Solution doesn't exist" << endl;

}

void work(){

  if(initR==goalR && initC==goalC) {
    cout << "Result : 0" << endl;
    return;
  }
  
  bfs(initR,initC);

}

int main(){

  while(read())
    work();

  return 0;
}
