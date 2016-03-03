#include<iostream>
#include<stdio.h>

#define WALL -1
#define MAX 200
#define EAST 1
#define NORTH 2
#define WEST 3
#define SOUTH 4

int matrix[MAX][MAX];
int num_visited[MAX][MAX];
int row,column;
int curr_row,curr_column;
int curr_direction;


void move_north(){

  if(matrix[curr_row][curr_column+1]==1 || matrix[curr_row][curr_column+1]==WALL){
    if(matrix[curr_row-1][curr_column]==1 || matrix[curr_row-1][curr_column]==WALL){
      if(matrix[curr_row][curr_column-1]==1 || matrix[curr_row][curr_column-1]==WALL){
	
	curr_direction=SOUTH;
	curr_row++;
	
      }
      else{
	curr_direction=WEST;
	curr_column--;
      }
    }
    else curr_row--;
  }
  else{
    curr_direction=EAST;
    curr_column++;
  }
  
}

void move_west(){

  if(matrix[curr_row-1][curr_column]==1 || matrix[curr_row-1][curr_column]==WALL){
    if(matrix[curr_row][curr_column-1]==1 || matrix[curr_row][curr_column-1]==WALL){      
      if(matrix[curr_row+1][curr_column]==1 || matrix[curr_row+1][curr_column]==WALL){
	
	curr_direction=EAST;
	curr_column++;
	
      }
      else{
	curr_direction=SOUTH;
	curr_row++;
      }
    }
    else curr_column--;
  }    
  else{
    curr_direction=NORTH;
    curr_row--;
  }

}

void move_east(){
  
  if(matrix[curr_row+1][curr_column]==1 || matrix[curr_row+1][curr_column]==WALL){
    if(matrix[curr_row][curr_column+1]==1 || matrix[curr_row][curr_column+1]==WALL){
      if(matrix[curr_row-1][curr_column]==1 || matrix[curr_row-1][curr_column]==WALL){
	
	curr_direction=WEST;
	curr_column--;
	
      }
      else{
	curr_direction=NORTH;
	curr_row--;
      }
    }
    else curr_column++;
    
  }
  else{
    curr_direction=SOUTH;
    curr_row++;
  }
 
}

void move_south(){
  
  if(matrix[curr_row][curr_column-1]==1 || matrix[curr_row][curr_column-1]==WALL){
    if(matrix[curr_row+1][curr_column]==1 || matrix[curr_row+1][curr_column]==WALL){
      if(matrix[curr_row][curr_column+1]==1 || matrix[curr_row][curr_column+1]==WALL){
      
	curr_direction=NORTH;
	curr_row--;
	
      }
      else{
	curr_direction=EAST;
	curr_column++;
      }
    }
    else curr_row++;

  }
  else{
    curr_direction=WEST;
    curr_column--;
  }

}

class Solver{
 public:

  bool read(){
    
    cin >> row >> column;
    if(row==0 && column==0) return false;

    curr_row=row, curr_column=1,curr_direction=EAST;

    for(int i=0;i<row+2;i++)
      for(int j=0;j<column+2;j++){
	matrix[i][j]=WALL;
	num_visited[i][j]=0;
      }

    for(int i=1;i<row+1;i++)
      for(int j=1;j<column+1;j++){
	char c;
	scanf("%c",&c);
	if(c<'0' || c>'9'){ j--; continue; }
        else matrix[i][j] = c -'0';
      }

    return true;

  }

  void work(){

    while(true){
      //cout << curr_row << "  " << curr_column << "  " << curr_direction << endl;
      if(curr_direction==WEST){
	move_west();
	num_visited[curr_row][curr_column]++;
	if(curr_column==1 && curr_row==row) return;
      }
      else if(curr_direction==EAST){
	move_east();
	num_visited[curr_row][curr_column]++;
	if(curr_column==1 && curr_row==row) return;
      }
      else if(curr_direction==NORTH){
	move_north();
	num_visited[curr_row][curr_column]++;
	if(curr_column==1 && curr_row==row) return;
      }
      else if(curr_direction==SOUTH){
	move_south();
	num_visited[curr_row][curr_column]++;
	if(curr_column==1 && curr_row==row) return;
      }

    }
  
  }

  void output(){

    int zero=0,one=0,two=0,three=0,four=0;

    for(int i=1;i<row+1;i++){
      for(int j=1;j<column+1;j++){
	if(matrix[i][j]==1) continue;
	else if(num_visited[i][j]==0) zero++;
	else if(num_visited[i][j]==1) one++;
	else if(num_visited[i][j]==2) two++;
	else if(num_visited[i][j]==3) three++;
	else if(num_visited[i][j]==4) four++;
      }
    }


    printf("%3d%3d%3d%3d%3d\n",zero,one,two,three,four);

  }


};

main(){
  
  Solver solver;

  while(true){
    if(solver.read()==false) break;
    solver.work();
    solver.output();
  }

}
