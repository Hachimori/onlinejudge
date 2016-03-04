#include<iostream>

#define ROOK 1
#define WALL -1
#define MAX 7

int length;
int max;
char matrix[MAX][MAX];
char tmp_matrix[MAX][MAX];

void Put_Rook(int y, int x, int counter){

  if(max<counter) max = counter;
  tmp_matrix[y][x] = ROOK;

  for(int i=y;i<length+1;i++){
    
    if(i==y)
    for(int j=x;j<length+1;j++){
      if(matrix[i][j]=='X' || tmp_matrix[i][j]==ROOK) continue;
      
       bool flg=true;
       for(int k=i-1;k>=1;k--){
	 if(matrix[k][j]=='X' || matrix[k][j]==WALL) break;
	 else if(tmp_matrix[k][j]==ROOK) flg=false;
       }
       for(int k=i+1;k<length+1;k++){
	 if(matrix[k][j]=='X' || matrix[k][j]==WALL) break;
	 else if(tmp_matrix[k][j]==ROOK) flg=false;
       }       
       for(int k=j-1;k>=1;k--){
	 if(matrix[i][k]=='X' || matrix[i][k]==WALL) break;
	 else if(tmp_matrix[i][k]==ROOK) flg=false;
       }
       for(int k=j+1;k<length+1;k++){
	 if(matrix[i][k]=='X' || matrix[i][k]==WALL) break;
	 else if(tmp_matrix[i][k]==ROOK) flg=false;
       }
       if(flg==false) continue;

       Put_Rook(i,j,counter+1);
       tmp_matrix[i][j] = '.';
    }
    else 
      for(int j=1;j<length+1;j++){
      if(matrix[i][j]=='X' || tmp_matrix[i][j]==ROOK) continue;
      
       bool flg=true;
       for(int k=i-1;k>=1;k--){
	 if(matrix[k][j]=='X' || matrix[k][j]==WALL) break;
	 else if(tmp_matrix[k][j]==ROOK) flg=false;
       }
       for(int k=i+1;k<length+1;k++){
	 if(matrix[k][j]=='X' || matrix[k][j]==WALL) break;
	 else if(tmp_matrix[k][j]==ROOK) flg=false;
       }       
       for(int k=j-1;k>=1;k--){
	 if(matrix[i][k]=='X' || matrix[i][k]==WALL) break;
	 else if(tmp_matrix[i][k]==ROOK) flg=false;
       }
       for(int k=j+1;k<length+1;k++){
	 if(matrix[i][k]=='X' || matrix[i][k]==WALL) break;
	 else if(tmp_matrix[i][k]==ROOK) flg=false;
       }
       if(flg==false) continue;

       Put_Rook(i,j,counter+1);
       tmp_matrix[i][j] = '.';
    }
  }

}

class Solver{

 public:

  bool read(){

    cin >> length;
    if(length==0) return false;

    for(int i=0;i<length+2;i++)
      for(int j=0;j<length+2;j++){
	matrix[i][j] = WALL;
	tmp_matrix[i][j] = WALL;
      }
    
    for(int i=1;i<length+1;i++){
      for(int j=1;j<length+1;j++){
	char c;
	cin >> c;

	if(c=='X' || c=='.'){
	  matrix[i][j]=c;
	  tmp_matrix[i][j]=c;
	}
	else j--;
      }
    }
	
    return true;

  }

  void work(){

    max = 0;

    for(int i=1;i<length+1;i++){
      for(int j=1;j<length+1;j++){
	
	if(matrix[i][j]=='.'){ 
	  Put_Rook(i,j,1);
	  tmp_matrix[i][j] = '.';
	}

      }
    }

    cout << max << endl;

  }

};

main(){

  Solver solver;

  while(true){
    
    if(solver.read()==false) break;
    solver.work();

  }

}
