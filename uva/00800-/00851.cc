#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<climits>

#define MAX_SIZE 13
#define WALL -1
#define ROAD 0
#define MAN 1
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

int size;
int board[MAX_SIZE][MAX_SIZE];
const static int rMove[4]={-1,0,1,0};
const static int cMove[4]={0,1,0,-1};

void read(){
  
  cin >> size;
  
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      char c;
      cin >> c;

      if(c=='O') board[i][j] = WALL;
      if(c=='.') board[i][j] = ROAD;
    }
  }
  
}

bool isInside(int r, int c){
  return 0<=r && r<size && 0<=c && c<size;
}

bool isGoal(int r, int c){
  return r==0 || r==size-1 || c==0 || c==size-1;
}

void calcCost(int cost[MAX_SIZE][MAX_SIZE]){
  
  const static int rMove[4]={-1,0,1,0};
  const static int cMove[4]={0,1,0,-1};
  
  int visited[MAX_SIZE][MAX_SIZE];


  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      cost[i][j] = INT_MAX;

  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      
      if(board[i][j]==WALL) continue;
      
      for(int k=0;k<size;k++)
	for(int l=0;l<size;l++)
	  visited[k][l] = INT_MAX;

      queue< pair< pair< int,int >, int > > Q;
      
      Q.push( make_pair( make_pair(i,j), 0 ) );
      
      while(!Q.empty()){
	
	pair< pair<int,int>, int > curr=Q.front();
	Q.pop();
	
	if(visited[curr.first.first][curr.first.second]>curr.second)
	  visited[curr.first.first][curr.first.second]=curr.second;
	else 
	  continue;	
	
	if(isGoal(curr.first.first,curr.first.second)){
	  cost[i][j] = curr.second;
	  break;
	}
	
	for(int k=0;k<4;k++){	  
	  pair< pair<int,int>, int > next;

	  next.first.first = curr.first.first+rMove[k];
	  next.first.second = curr.first.second+cMove[k];
	  next.second = curr.second+1;
	  
	  if(!isInside(next.first.first,next.first.second)) continue;
	  if(board[next.first.first][next.first.second]==WALL) continue;
	  
	  Q.push(next);
	}
	
      }
      
    }
  }

}

bool succeed(int nMove,  bool manExist[MAX_SIZE][MAX_SIZE], int cost[MAX_SIZE][MAX_SIZE], int limit, vector<int> &path){
  
  int manhattan=0;
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      if(manExist[i][j])
	manhattan = max(manhattan,cost[i][j]);
  
  if(manhattan==0) return true;
  if(manhattan+nMove>limit) return false;
  
  /*
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(manExist[i][j]==false && board[i][j]==WALL) cout << "#";
      else if(manExist[i][j]==false && board[i][j]==ROAD) cout << ".";
      else cout << "O";
    }cout << endl;
  }cout << endl;
  */

  for(int i=0;i<4;i++){
    
    bool backup[MAX_SIZE][MAX_SIZE];
    
    for(int r=0;r<size;r++)
      for(int c=0;c<size;c++)
	backup[r][c] = manExist[r][c];

    if(i==NORTH || i==WEST){

      for(int r=0;r<size;r++)
	for(int c=0;c<size;c++){
	  if(isGoal(r,c)) continue;
	  if(!isInside(r+rMove[i],c+cMove[i])) continue;
	  if(board[r+rMove[i]][c+cMove[i]]==WALL) continue;
	  if(!manExist[r][c]) continue;

	  manExist[r][c]=false;
	  manExist[r+rMove[i]][c+cMove[i]] = true;
	}
    }
    else {

      for(int r=size-1;r>=0;r--)
	for(int c=size-1;c>=0;c--){
	  if(isGoal(r,c)) continue;
	  if(!isInside(r+rMove[i],c+cMove[i])) continue;
	  if(board[r+rMove[i]][c+cMove[i]]==WALL) continue;
	  if(!manExist[r][c]) continue;

	  manExist[r][c]=false;
	  manExist[r+rMove[i]][c+cMove[i]] = true;
	}
    }
    
    path.push_back(i);
    
    if(succeed(nMove+1,manExist,cost,limit,path)) return true;
    
    path.pop_back();

    for(int r=0;r<size;r++)
      for(int c=0;c<size;c++)
	manExist[r][c] = backup[r][c];    
  }
  
  return false;
}

void iterativeDeepning(int cost[MAX_SIZE][MAX_SIZE]){
  
  int limit=0;
  
  vector<int> path;
    
  while(true){
    
    bool manExist[MAX_SIZE][MAX_SIZE];

    for(int i=0;i<size;i++)
      for(int j=0;j<size;j++)
	if(board[i][j]==ROAD)
	  manExist[i][j] = true;
	else
	  manExist[i][j] = false;

    path.clear();

    if(succeed(0,manExist,cost,limit,path)) break;
    limit++;
  }
  
  for(int i=0;i<limit;i++){
    if(path[i]==NORTH) cout << "north" << endl;
    else if(path[i]==EAST) cout << "east" << endl;
    else if(path[i]==SOUTH) cout << "south" << endl;
    else if(path[i]==WEST) cout << "west" << endl;
  }
  
}

void work(){
  
  int cost[MAX_SIZE][MAX_SIZE];

  calcCost(cost);
  
  /*
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(cost[i][j]==INT_MAX) cout << "# ";
      else cout << cost[i][j] << ' ';
    }cout << endl;
  }cout << endl;
  */

  
  iterativeDeepning(cost);

}


int main(){
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    
    read();
    work();
  }
  
  return 0;
}
