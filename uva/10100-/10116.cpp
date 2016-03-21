#include<iostream>
#define MAX 13
#define WALL -1

int row,column,start_column;
char matrix[MAX][MAX];


void search_rec(int visited[MAX][MAX], int curr_row, int curr_column, int score){

  if(visited[curr_row][curr_column]>0){
    cout << visited[curr_row][curr_column]-1 << " step(s) before a loop of " << score-visited[curr_row][curr_column] << " step(s)"<< endl;
    return;
  }

  visited[curr_row][curr_column] = score;

  if(matrix[curr_row][curr_column] == WALL){
    cout << score-1 << " step(s) to exit" << endl;
    return;
  }
  else if(matrix[curr_row][curr_column] == 'W') return search_rec(visited,curr_row,curr_column-1,score+1);
  else if(matrix[curr_row][curr_column] == 'E') return search_rec(visited,curr_row,curr_column+1,score+1);
  else if(matrix[curr_row][curr_column] == 'S') return search_rec(visited,curr_row+1,curr_column,score+1);
  else if(matrix[curr_row][curr_column] == 'N') return search_rec(visited,curr_row-1,curr_column,score+1);
  

}

class Solver{
 public:

  bool read(){

    cin >> row >> column >> start_column;
    if(row == 0 && column ==0 && start_column == 0) return false;

    for(int i=0;i<row+2;i++)
      for(int j=0;j<column+2;j++)
	matrix[i][j] = WALL;
    
    for(int i=1;i<row+1;i++)
      for(int j=1;j<column+1;j++)
	cin >> matrix[i][j];

    return true;

  }

  void work(){
   
    int visited[MAX][MAX];

    if( start_column<1 || start_column>column ) cout << "0 step(s) to exit" << endl;
    else{

      for(int i=0;i<row+2;i++)
	for(int j=0;j<column+2;j++)
	  visited[i][j] = WALL;

      for(int i=1;i<row+1;i++)
	for(int j=1;j<column+1;j++)
	  visited[i][j] = 0;

      search_rec(visited,1,start_column,1);
    }

  }


};

main(){

  Solver solver;
  
  while(true){

    if(solver.read()==false) break;
    solver.work();

  }

}
