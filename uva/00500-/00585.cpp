#include<iostream>
#include<assert.h>

#define WALL -1
#define MAX 207

int height,cases;
char matrix[MAX][MAX];


int Search_down(int y, int x){

  int num_triangle;
  bool flg;

  for(int n=1;;n++){
 
    flg=true;

    for(int k=0,i=y;i<y+n;k++,i++){
      for(int j=x;j<x+(n-1)*2-k*2+1;j++){
	if(matrix[i][j]==WALL || matrix[i][j]=='#') flg=false;
      }
    }
        
    if(flg==true) num_triangle = n*n;
    else return num_triangle;

  }


}

int Search_up(int y, int x){

  int num_triangle;  
  bool flg;

  for(int n=1;;n++){

    flg=true;

    for(int k=0,i=y;i>y-n;k++,i--){
      for(int j=x+k*2;j<x+(n-1)*2+1;j++){
	if(matrix[i][j]==WALL || matrix[i][j]=='#') flg=false;
      }
    }

    if(flg==true) num_triangle = n*n;
    else return num_triangle;

  }

  
}

class Solver{
 public:

  bool read(){

    cin >> height;
    if(height==0) return false;


    for(int i=0;i<height+3;i++){
      for(int j=0;j<height*2+3;j++){
	matrix[i][j]=WALL;
      }
    }
    
    for(int i=2;i<height+2;i++){
      for(int j=2;j<height*2-(i-2)*2+1;j++){
	char c;
	
	cin >> c;

	if(c=='#' || c=='-'){
	  matrix[i][j] = c;
	}
	else {
	  j--;
	  continue;
	}

      }
    }

    return true;

  }


  void work(){
    /*
    for(int i=0;i<height+3;i++){
      for(int j=0;j<height*2+3;j++){
	if(matrix[i][j]==WALL) cout << '+';
	else cout << matrix[i][j];
      }cout << endl;
    }cout << endl;
    */

    int max=0;
    int tmp;
    
    for(int i=2;i<height+2;i++){
      for(int j=2;j<height*2-(i-2)*2+1;j++){
	
	if(matrix[i][j]=='-' && j%2==0){
	  tmp = Search_down(i,j);
	  if(max<tmp) max = tmp;
	  //cout <<"i = " << i << "  j = " << j << "  " <<  "down " << tmp << endl;
	}
	else if(matrix[i][j]=='-' && j%2==1){
	  tmp = Search_up(i,j);
	  if(max<tmp) max = tmp;
	  //cout <<"i = " << i << "  j = " << j << "  " <<  "up " << tmp << endl;
	}
	
      }
    }

    cout << "Triangle #" << cases << endl;
    cout << "The largest triangle area is " << max << "." << endl;
    cout << endl;

  }

};

main(){

  Solver solver;

  for(cases=1;;cases++){

    if(solver.read()==false) break;
    solver.work();

  }

}
