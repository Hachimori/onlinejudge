#include<iostream>
#include<vector>
#include<string>

#define MAX_PIECES 110
#define MAX_SIZE 26
#define TOP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

using namespace std;

int size;
int row, column;

class Cell{
public:

  string pic[MAX_SIZE];
  int piece[4];

  bool match(int self, int opp, Cell oppCell){    
    return (piece[self]==(-1)*oppCell.piece[opp]);
  }

};

Cell cellList[MAX_PIECES*MAX_PIECES], board[MAX_PIECES][MAX_PIECES];
static const int rMove[4]={1,0,-1,0}, cMove[4]={0,1,0,-1};
bool used[MAX_PIECES*MAX_PIECES];
bool put[MAX_SIZE][MAX_SIZE];

void read(){

  cin >> size >> row >> column;

  for(int i=0;i<size*size;i++){      
    string str;
    getline(cin,str);
    
    for(int k=0;k<row;k++)
      getline(cin,cellList[i].pic[k]);
    
    for(int k=0;k<4;k++)	
      cin >> cellList[i].piece[k];
    
    getline(cin,str);    
  }

}

bool isInside(int r, int c){
  return (0<=r && r<size && 0<=c && c<size);
}

bool isCorner(int r, int c, Cell cell){
  return ( (r==-1 && cell.piece[TOP]==0) ||
	   (c==-1 && cell.piece[LEFT]==0) ||
	   (r==size && cell.piece[DOWN]==0) ||
	   (c==size && cell.piece[RIGHT]==0) );
	   
}

bool rec(int r, int c){

  if(r==size) return true;

  if(c==size){
    if(rec(r+1,0)) return true;
    else return false;
  }

  if(put[r][c]){
    if(rec(r,c+1)) return true;
    else return false;
  }
  
  
  for(int i=0;i<size*size;i++){
    if(used[i]) continue;

    bool fail=false;
    for(int k=0;k<4;k++){
      int nextR=r+rMove[k], nextC=c+cMove[k];
      
      if(isInside(nextR,nextC)){	 	    
	if(!put[nextR][nextC]) continue;
	else if(!board[nextR][nextC].match(k,(k+2)%4,cellList[i]))
	  fail=true;
      }
      else if(!isCorner(nextR,nextC,cellList[i]))
	fail=true;      
    }
    
    if(fail) continue;
    
    put[r][c] = true;
    used[i]=true;
    board[r][c] = cellList[i];
    
    if(rec(r,c+1)) return true;
    
    put[r][c] = false;
    used[i]=false;      
    
  }

  return false;
}

void work(){  
  
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      put[i][j] = false;

  for(int i=0;i<size*size;i++)
    used[i]=false;
  
  for(int i=0;i<size*size;i++){
    if(cellList[i].piece[TOP]==0 && cellList[i].piece[LEFT]==0){
      put[0][0]=true;
      used[i]=true;
      board[0][0] = cellList[i];
    }
    
    if(cellList[i].piece[TOP]==0 && cellList[i].piece[RIGHT]==0){
      put[0][size-1]=true;
      used[i]=true;
      board[0][size-1] = cellList[i];
    }

    if(cellList[i].piece[DOWN]==0 && cellList[i].piece[LEFT]==0){
      put[size-1][0]=true;
      used[i]=true;
      board[size-1][0] = cellList[i];
    }

    if(cellList[i].piece[DOWN]==0 && cellList[i].piece[RIGHT]==0){
      put[size-1][size-1]=true;
      used[i]=true;
      board[size-1][size-1] = cellList[i];
    }
  }

  rec(0,1);  
 
  char largePic[400][400];
  
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)      
      for(int k=0;k<row;k++)
	for(int l=0;l<column;l++)
	  largePic[k+row*i][l+column*j] = board[i][j].pic[k][l];
  
  
  for(int i=0;i<size*row;i++){
    for(int j=0;j<size*column;j++){
      cout << largePic[i][j];
    }cout << endl;
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
