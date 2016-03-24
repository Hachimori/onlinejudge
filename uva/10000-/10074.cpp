#include<iostream>
#include<string>

#define MAX 100
using namespace std;

int num_row,num_column;
int max_piece;

class Solver{

 public:


  bool read(int matrix[MAX][MAX]){
    
    cin >> num_row >> num_column;
    if(num_row==0 && num_column==0) return false;

    for(int i=0;i<num_row;i++)
      for(int j=0;j<num_column;j++)
	cin >> matrix[i][j];

    return true;

  }

  void work(int matrix[MAX][MAX]){
    /*
    for(int i=0;i<num_row;i++){
      for(int j=0;j<num_column;j++){
	cout << matrix[i][j];
      }cout << endl;
    }cout << endl;
    */

    bool check;

    for(int i=0;i<num_row;i++){
      for(int j=0;j<num_column;j++){
	if(matrix[i][j]==1) continue;
	
	for(int lim_column=j;lim_column<num_column;lim_column++){
	  if(matrix[i][lim_column]==1) break;

	  check = true;

	  int curr_row,curr_column;

	  for(curr_row=i; curr_row<num_row; curr_row++){
	    for(curr_column=j; curr_column<=lim_column; curr_column++){
	      
	      if(matrix[curr_row][curr_column]==1){ check=false; break; } 
	    }

	    if(check==false) break;

	  }

	  if( (curr_row-i)*(lim_column-j+1) > max_piece ) 
	    max_piece = (curr_row-i)*(lim_column-j+1);	  

	}

      }
    }

    cout << max_piece << endl;

  }

};

main(){

  Solver solver;
  int matrix[MAX][MAX];

  while(true){

    max_piece=0;

    if(solver.read(matrix)==false) break;
    solver.work(matrix);
    
  }

}
