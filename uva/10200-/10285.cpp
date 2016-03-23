#include<iostream>
#include<string>

#define MAX 103
#define WALL 9999

int matrix[MAX][MAX];
bool visited[MAX][MAX];
string name;
int row,column,max;
int move_x[4]={0,1,0,-1},move_y[4]={1,0,-1,0};

void init(){
  
  for(int i=0;i<row+2;i++)
    for(int j=0;j<column+2;j++)
      matrix[i][j]=WALL;
 
  for(int i=1;i<row+1;i++)
    for(int j=1;j<column+1;j++)
      visited[i][j]=false;  
}

void Search_rec(int curr_y, int curr_x, int curr_score){

  for(int i=0;i<4;i++){

    int next_x = curr_x + move_x[i];
    int next_y = curr_y + move_y[i];

    if(visited[next_y][next_x]==true) continue;
    else if(matrix[next_y][next_x] < matrix[curr_y][curr_x]){
      
      visited[next_y][next_x] = true;

      Search_rec(next_y,next_x,curr_score+1);

      visited[next_y][next_x] = false;
      
    }

  }

  if(max<curr_score) max = curr_score;

  return;

}

class Solver{

 public:

  void read(){
    
    cin >> name ;
    cin >> row >> column;

    init();

    for(int i=1;i<row+1;i++)
      for(int j=1;j<column+1;j++)
	cin >> matrix[i][j];

  }

  void work(){

    max = 0;

    for(int i=1;i<row+1;i++){
      for(int j=1;j<column+1;j++){
	
	Search_rec(i,j,0);

      }
    }

    cout << name << ": " << max+1 << endl;

  }

};




main(){

  int cases;
  Solver solver;

  cin >> cases;

  for(int i=0;i<cases;i++){
    
    solver.read();
    solver.work();

  }

}
