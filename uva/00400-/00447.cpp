#include<iostream>
#include<string>
#include<cassert>
using namespace std;

#define WALL -1
#define EMPTY 0
#define PEOPLE 1
#define NEXT_PEOPLE 2
#define NEXT_ALIVE 3
#define NEXT_EMPTY -2
#define MAX 23


int year;
int x_move[8]={-1,0,1,1,1,0,-1,-1},y_move[8]={1,1,1,0,-1,-1,-1,0};
char matrix2[MAX][MAX];
char matrix[MAX][MAX];

void output(){
  
  for(int i=1;i<21;i++){
    for(int j=1;j<21;j++){
      if(matrix[i][j]==PEOPLE) cout << 'O';
      else cout << ' ';
    }cout << endl;
  }
  cout << "********************" << endl;

}

class Solver{
 public:

  void read(){
    
    for(int i=0;i<MAX;i++)
      for(int j=0;j<MAX;j++)
	matrix[i][j]=WALL;

    for(int i=1;i<21;i++)
      for(int j=1;j<21;j++)
	matrix[i][j]=EMPTY;

    cin >> year;
    
    
    string tmp;
    getline(cin,tmp);

    while(true){
      int x=0,y=0;
      int arg=0;
      string str;

      str.erase(0,str.size()+1);

      getline(cin,str);
      if(str.length()==0) return;

      while(str[arg]<'0' || str[arg]>'9') arg++;

      
      for(int k=10;str[arg]!=' ';arg++){
	
	y*=k;
	y+=str[arg]-'0';
      }
      arg++;
      
      for(int k=10;arg<str.length();arg++){
	x*=k;
	x+=str[arg]-'0';
      }
      matrix[y][x]=PEOPLE;
 
    }
   
  }

  void work(){

    cout << "********************" << endl;

    for(int curr_year=0;curr_year<year;curr_year++){
      
      output();

      
      for(int i=0;i<MAX;i++)
	for(int j=0;j<MAX;j++)
	  matrix2[i][j] = matrix[i][j];

      for(int i=1;i<21;i++){
	for(int j=1;j<21;j++){
	  if(matrix[i][j]==EMPTY){
	    
	    int counter=0;
	    for(int k=0;k<8;k++){
	      int y_next = i+y_move[k];
	      int x_next = j+x_move[k];
	      
	      if(matrix[y_next][x_next]==PEOPLE) counter++;
	    }
	    if(counter==3) matrix2[i][j]=NEXT_PEOPLE;

	  }
	}
      }
      /*
      for(int i=0;i<MAX;i++)
	for(int j=0;j<MAX;j++)
	  matrix[i][j] = tmp_matrix[i][j];   

     
      for(int i=0;i<MAX;i++)
	for(int j=0;j<MAX;j++)
	  tmp_matrix[i][j] = matrix[i][j];
	  */

      for(int i=1;i<21;i++){
	for(int j=1;j<21;j++){
	  if(matrix[i][j]==PEOPLE){
	    
	    int counter=0;
	    for(int k=0;k<8;k++){
	      int y_next = i+y_move[k];
	      int x_next = j+x_move[k];
	      
	      if(matrix[y_next][x_next]==PEOPLE) counter++;
	    }
	    if(counter<2) matrix2[i][j]=NEXT_EMPTY;
	    else if(counter>=2 && counter<=3) matrix2[i][j]=NEXT_ALIVE;
	    else if(counter>=4) matrix2[i][j]=NEXT_EMPTY;

	  }
	}
      }      
 
      for(int i=1;i<21;i++)
	for(int j=1;j<21;j++){
	  if(matrix2[i][j]==NEXT_PEOPLE) matrix[i][j]=PEOPLE;
	  else if(matrix2[i][j]==NEXT_EMPTY) matrix[i][j]=EMPTY;
	  else if(matrix2[i][j]==NEXT_ALIVE) matrix[i][j]=PEOPLE;
	}
    }

  }
  

};

main(){

  int cases;
  Solver solver;
  string str;

  cin >> cases;
  getline(cin,str);
  getline(cin,str);
  
  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    solver.read();
    solver.work();
  }

}
