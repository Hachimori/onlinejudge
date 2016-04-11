#include<iostream>

#define MAX_SIZE 15
#define WALL 0
#define EMPTY 1
#define UNKNOWN 2

using namespace std;

int row, column;
int initR, initC;
int board[MAX_SIZE][MAX_SIZE];

bool read(){
  
  cin >> row >> column;
  if(row==0 && column==0) return false;
  
  cin >> initR >> initC;

  initR--, initC--;
  
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      char c;
      cin >> c;

      if(c=='0')
	board[i][j] = EMPTY;
      else if(c=='X')
	board[i][j] = WALL;
    }
  }
  
  return true;
}

bool isInside(int r, int c){
  return 0<=r && r<row && 0<=c && c<column;
}

void dfs(int r, int c, int &nMove, int ansBoard[MAX_SIZE][MAX_SIZE], bool visited[MAX_SIZE][MAX_SIZE]){
  

  const static int rMove[4] = {-1,0,1,0};
  const static int cMove[4] = {0,1,0,-1};
  
  visited[r][c] = true;
  
  for(int i=0;i<4;i++){
    if(!isInside(r+rMove[i],c+cMove[i])) continue;
    
    ansBoard[r+rMove[i]][c+cMove[i]] = board[r+rMove[i]][c+cMove[i]];
  }
  
  for(int i=0;i<4;i++){
    if(!isInside(r+rMove[i],c+cMove[i])) continue;
    if(board[r+rMove[i]][c+cMove[i]]==WALL) continue;
    if(visited[r+rMove[i]][c+cMove[i]]) continue;
    
    nMove++;
    dfs(r+rMove[i],c+cMove[i],nMove,ansBoard,visited);
    return;
  }
  
}

void work(){
  
  int nMove=0;
  int ansBoard[MAX_SIZE][MAX_SIZE];
  bool visited[MAX_SIZE][MAX_SIZE];

  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      ansBoard[i][j] = UNKNOWN;
      visited[i][j] = false;
    }
  }
  
  ansBoard[initR][initC] = board[initR][initC];
  
  dfs(initR,initC,nMove,ansBoard,visited);
  
  
  for(int i=0;i<row;i++){
    
    for(int j=0;j<column;j++)
      cout << "|---";
    cout << "|" << endl;
  
    for(int j=0;j<column;j++){
      cout << "| ";
      if(ansBoard[i][j]==WALL)
	cout << "X ";
      else if(ansBoard[i][j]==EMPTY)
	cout << "0 ";
      else if(ansBoard[i][j]==UNKNOWN)
	cout << "? ";
    }
    cout << "|" << endl;
  }
  
  for(int j=0;j<column;j++)
      cout << "|---";
  cout << "|" << endl << endl;
  

  cout << "NUMBER OF MOVEMENTS: " << nMove << endl;
}

int main(){
  
  while(read()){
    cout << endl;
    work();
  }

  return 0;
}
