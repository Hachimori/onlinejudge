#include<stdio.h>
#include<string.h>

#define MAX_c 100
#define MAX_b 50

void Put0(int,int,int [MAX_b][MAX_b]);
void North_Move(int,int,char,int [MAX_b][MAX_b]);
void South_Move(int,int,char,int [MAX_b][MAX_b]);
void East_Move(int,int,char,int [MAX_b][MAX_b]);
void West_Move(int,int,char,int [MAX_b][MAX_b]);

int tmp_x,tmp_y,lost=0;
char direction;

main()
{

  int i,j;
  int x,y,board[MAX_b][MAX_b],length;
  char ctr[MAX_c];

  scanf("%d%d",&x,&y);
  Put0(x,y,board);
  
  while( scanf("%d%d %c",&tmp_x,&tmp_y,&direction) != EOF ){
    
    scanf("%s",ctr);
    length = strlen(ctr);
    
    for(i=0;i<length;i++){
      if( lost == 1 ) break;
      else if( direction == 'N' ) North_Move(x,y,ctr[i],board);
      else if( direction == 'S' ) South_Move(x,y,ctr[i],board);
      else if( direction == 'E' ) East_Move(x,y,ctr[i],board);
      else if( direction == 'W' ) West_Move(x,y,ctr[i],board);      
      //printf("%d %d %c\n",tmp_x,tmp_y,direction);
    }

    printf("%d %d %c",tmp_x,tmp_y,direction);
    if(lost == 1){
      printf(" LOST\n");
      lost = 0;
    }
    else printf("\n");
 
  }

}

void Put0(int x, int y, int board[MAX_b][MAX_b]){

  int i,j;

  for(i=0;i<y;i++){
    for(j=0;j<x;j++){
      board[i][j] = 0;
    }
  }

  return;
}

void North_Move(int x, int y, char ctr, int board[MAX_b][MAX_b]){
  
  if( ctr == 'R' ) direction = 'E';
  else if( ctr == 'L' ) direction = 'W';
  else if( ctr == 'F' ){
    if( tmp_y == y && board[tmp_y][tmp_x] != 1){
      lost = 1;
      board[tmp_y][tmp_x] = 1;
    }
    else if( tmp_y == y && board[tmp_y][tmp_x] == 1){}
    else tmp_y++;
  }

  return;

}
      
void South_Move(int x, int y, char ctr, int board[MAX_b][MAX_b]){
  
  if( ctr == 'R' ) direction = 'W';
  else if( ctr == 'L' ) direction = 'E';
  else if( ctr == 'F' ){
    if( tmp_y == 0 && board[tmp_y][tmp_x] != 1){
      lost = 1;
      board[tmp_y][tmp_x] = 1;
    }
    else if( tmp_y == 0 && board[tmp_y][tmp_x] == 1){}
    else tmp_y--;
  }

  return;

}

void East_Move(int x, int y, char ctr, int board[MAX_b][MAX_b]){
  
  if( ctr == 'R' ) direction = 'S';
  else if( ctr == 'L' ) direction = 'N';
  else if( ctr == 'F' ){
    if( tmp_x == x && board[tmp_y][tmp_x] != 1){
      lost = 1;
      board[tmp_y][tmp_x] = 1;
    }
    else if( tmp_x == x && board[tmp_y][tmp_x] == 1){}
    else tmp_x++;
  }

  return;

}

void West_Move(int x, int y, char ctr, int board[MAX_b][MAX_b]){
  
  if( ctr == 'R' ) direction = 'N';
  else if( ctr == 'L' ) direction = 'S';
  else if( ctr == 'F' ){
    if( tmp_x == 0 && board[tmp_y][tmp_x] != 1){
      lost = 1;
      board[tmp_y][tmp_x] = 1;
    }
    else if( tmp_x == 0 && board[tmp_y][tmp_x] == 1){}
    else tmp_x--;
  }

  return;

}
