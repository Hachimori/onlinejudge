// 10443

#include<iostream>
#include<cstdio>
#include<string>

#define MAX_SIZE 105

using namespace std;

int row, column, date;
char board[MAX_SIZE][MAX_SIZE];

void read(){

  cin >> row >> column >> date;

  for(int i=0;i<row;i++)
    scanf("%s",board[i]);

}

bool isInside(int r, int c){
  return (0<=r && r<row && 0<=c && c<column);
}

void work(){
  
  const static int rMove[4]={1,0,-1,0}, cMove[4]={0,1,0,-1};
  char nextBoard[MAX_SIZE][MAX_SIZE];

  if(row==1 && column==1){
    cout << board[0] << endl;
    return;
  }

  for(int i=0;i<row;i++)
    for(int j=0;j<column;j++)
      nextBoard[i][j] = ' ';

  for(int i=0;i<date;i++){

    for(int j=0;j<row;j++){
      for(int k=0;k<column;k++){
	
	bool survive=true;

	for(int l=0;l<4;l++){
	  int nextR=j+rMove[l], nextC=k+cMove[l];

	  if(!isInside(nextR,nextC)) continue;

	  if(board[j][k]=='P' && board[nextR][nextC]=='S')
	    survive=false;
	  else if(board[j][k]=='R' && board[nextR][nextC]=='P')
	    survive=false;
	  else if(board[j][k]=='S' && board[nextR][nextC]=='R')
	    survive=false;	  
	}

	if(survive)
	  nextBoard[j][k] = board[j][k];
	else if(board[j][k]=='P')
	  nextBoard[j][k] = 'S';
	else if(board[j][k]=='S')
	  nextBoard[j][k] = 'R';
	else if(board[j][k]=='R')
	  nextBoard[j][k] = 'P';
	

	  
      }
    }
    
    for(int j=0;j<row;j++)
      for(int k=0;k<column;k++)
	board[j][k] = nextBoard[j][k];
    

  }
  
  for(int i=0;i<row;i++)
    printf("%s\n",board[i]);

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
