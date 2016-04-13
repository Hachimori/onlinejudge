#include<iostream>
#include<vector>
#include<queue>
#include<map>
#define MAX 1000

int row,column,start_R,start_C,end_R,end_C,num_walk;

class XY{
 public:
  int x,y;
};


class Graph{
  
 public:

  queue<XY> Q;
  short visited[MAX][MAX];
  
  Graph(){}

  Graph(int y, int x){

    for(int i=0;i<y;i++)
      for(int j=0;j<x;j++)
	visited[y][x]=0;
  
  }

};

void bfs(Graph g){

  int goto_y[4]={1,0,-1,0},goto_x[4]={0,1,0,-1};
  int tmp_y,tmp_x;
  XY tmp_XY;

  tmp_XY.y = start_R; 
  tmp_XY.x = start_C;
  
  g.visited[start_R][start_C]=1;
  g.Q.push(tmp_XY);
  
  while(!g.Q.empty()){
    tmp_XY = g.Q.front();
    tmp_y = tmp_XY.y;
    tmp_x = tmp_XY.x;
    g.Q.pop();
    /* cout <<"tmp_y = " << tmp_y << "  tmp_x = " 
       << tmp_x << "  distance = "<< g.visited[tmp_y][tmp_x] << endl; */
    for(int i=0;i<4;i++){

      if(tmp_y+goto_y[i] < 0 || tmp_y+goto_y[i] >= row    ||
	 tmp_x+goto_x[i] < 0 || tmp_x+goto_x[i] >= column ||
	 g.visited[tmp_y+goto_y[i]][tmp_x+goto_x[i]]>0) continue;
      else if(tmp_y+goto_y[i]==end_R && tmp_x+goto_x[i]==end_C){
	num_walk = g.visited[tmp_y][tmp_x]+1;
	return;
      }
      else{
	g.visited[tmp_y+goto_y[i]][tmp_x+goto_x[i]]=g.visited[tmp_y][tmp_x]+1;
	
	tmp_XY.y = tmp_y+goto_y[i]; 
	tmp_XY.x = tmp_x+goto_x[i];
	g.Q.push(tmp_XY);
      }

    }    
  }
   
  cout <<" error "<< endl;
  return;
 
}
    
int Input(void);
void Work(Graph &);


main(){
  while(1){
    num_walk=0;
    if(Input()==false) break;
  }
}

int Input(void){

  int num_mines,num_rows,pos_row,pos_column;
  Graph g;
 
  cin >> row >> column;
  if( row==0 && column==0 ) return false;
  cin >> num_rows;

  g = Graph(row,column);

  for(int i=0;i<num_rows;i++){
    cin >> pos_row;
    
    cin >> num_mines;
    
    for(int j=0;j<num_mines;j++){
      cin >> pos_column;
      g.visited[pos_row][pos_column]=1;
    }
  }

  /*
  for(int i=0;i<row;i++){ 
    for(int j=0;j<column;j++){
      if(g.visited[i][j]==1) cout << 1;
      else cout << 0;
    }cout << endl;
  }*/

  cin >> start_R >> start_C; 
  cin >> end_R >> end_C; 

  if(start_R == end_R && start_C == end_C){ cout << '0' << endl; return true;}

  Work(g);

  return true;
  
}

void Work(Graph &g){ /* なぜここに & をつけないと グラフの値が保持されるの？ */

  bfs(g);

  cout << num_walk-1 << endl;

  return;
  
}
