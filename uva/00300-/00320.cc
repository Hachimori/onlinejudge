#include<iostream>

#define MAX_SIZE 35
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

int startX, startY;

void read(){  
  cin >> startX >> startY;  
}

bool isInside(int x, int y){
  return (0<=x && x<=32 && 0<=y && y<=32);
}

void work(int cases){

  int currX=startX, currY=startY;
  const static int moveX[4]={0,1,0,-1}, moveY[4]={1,0,-1,0};
  char c;
  char board[MAX_SIZE][MAX_SIZE];

  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++)
      board[i][j] = '.';

  while(true){
    cin >> c;
    if(c=='.') break;

    switch(c){

    case 'N':
      if(isInside(currY,currX)) board[currY][currX] = 'X';
      currY+=moveY[NORTH];
      currX+=moveX[NORTH];
      break;
    case 'E':
      if(isInside(currY-1,currX)) board[currY-1][currX] = 'X';
      currY+=moveY[EAST];
      currX+=moveX[EAST];
      break;   
    case 'S':
      if(isInside(currY-1,currX-1)) board[currY-1][currX-1] = 'X';
      currY+=moveY[SOUTH];
      currX+=moveX[SOUTH];
      break;
    case 'W':
      if(isInside(currY,currX-1)) board[currY][currX-1] = 'X';
      currY+=moveY[WEST];
      currX+=moveX[WEST];
      break;      
    }

  }


  cout << "Bitmap #" << cases << endl;
  for(int i=31;i>=0;i--){
    for(int j=0;j<32;j++){
      cout << board[i][j];
    }cout << endl;
  }cout << endl;

}

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
