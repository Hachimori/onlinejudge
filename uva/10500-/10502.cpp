#include<iostream>

#define MAX 103
#define WALL -1

char matrix[MAX][MAX];
int row,column;
int counter;

class Solver{
 public:

  bool read(){
    
    cin >> row;
    if(row==0) return false;

    cin >> column;

    for(int i=0;i<row+2;i++)
      for(int j=0;j<column+2;j++)
	matrix[i][j]=WALL;

    for(int i=1;i<row+1;i++){
      for(int j=1;j<column+1;j++){
	
	char c;
	cin >> c;
	
	if(c>='0' && c<='9'){
	  matrix[i][j]=c;
	}
	else {
	  j--;
	}
      
      }
    }

  }

  void work(){
    /*
    for(int i=0;i<row+2;i++){
      for(int j=0;j<column+2;j++){
	if(matrix[i][j]==WALL) cout << '#';
	else cout << matrix[i][j];
      }cout << endl;
    }cout << endl;
    */

    bool flg;

    for(int i=1;i<row+1;i++){
      for(int j=1;j<column+1;j++){
	
	if(matrix[i][j]=='0') continue;

	flg=true;

	for(int row_limit=i,k=i;k<row+1;k++){
	  for(int l=j;l<column+1;l++){
	    
	    flg=true;

	    for(int m=k;m>=row_limit;m--){
	      if(matrix[m][l]=='0'){ 
		flg=false;
		break;
	      }
	    }

	    if(flg==true) counter++;
	    else break;

	  }
	}

      }
    }


    cout << counter << endl;

  }

};

main(){

  Solver solver;

  while(true){

    if(solver.read()==false) break;
    counter=0;
    solver.work();

  }


}
