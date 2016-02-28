#include<iostream>

#define MAX_SIZE 205

using namespace std;

int size;
char board[MAX_SIZE][MAX_SIZE];
const int rMove[6]={-1,-1,0,0,1,1};
const int cMove[6]={-1,0,-1,1,0,1};

bool read(){
  
  cin >> size;
  if(size==0) return false;
  
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      cin >> board[i][j];

  return true;
}

bool isInside(int row, int column){
  return 0<=row && row<size && 0<=column && column<size;
}

bool dfs(int row, int column, bool visited[MAX_SIZE][MAX_SIZE]){
  
  if(row==size-1) return true;
  visited[row][column]=true;
  
  for(int i=0;i<6;i++){
    int nextRow = row+rMove[i], nextColumn = column+cMove[i];
   
    if(!isInside(nextRow,nextColumn)) continue;
    if(visited[nextRow][nextColumn]) continue;
    if(board[nextRow][nextColumn]!='b') continue;

    if(dfs(nextRow,nextColumn,visited)) return true;
  }
  
  return false;
}

void work(int cases){

  for(int i=0;i<size;i++){
    
    bool visited[MAX_SIZE][MAX_SIZE];
    for(int j=0;j<size;j++)
      for(int k=0;k<size;k++)
	visited[j][k] = false;
    
    if(board[0][i]=='b' && dfs(0,i,visited)){      
      cout << cases << ' ' << 'B' << endl;
      return;      
    }    
  }

  cout << cases << ' ' << 'W' << endl;
}

int main(){
  
  for(int cases=1;read();cases++)
    work(cases);

  return 0;
}
