#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
#include<utility>
#include<vector>

#define MAX_SIZE 20
#define WALL -1
#define ROAD 0
#define ENDPOINT 1
#define DIAMOND 2
#define VISITED 3

using namespace std;

int row, column, nDia, minScore;
int board[MAX_SIZE][MAX_SIZE];
pair<int,int> dList[MAX_SIZE]; //row, column

bool read(){
  
  cin >> row >> column;
  
  nDia=0;

  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      char cell;
      cin >> cell;
      
      if(cell=='.') board[i][j]=ROAD;
      else if(cell=='#') board[i][j]=WALL;
      else if(cell=='*'){ 
	board[i][j]=DIAMOND;
	dList[nDia]=make_pair(i,j);
	nDia++;
      }
    }
  }

}

int calcManhattan(pair<int,int> curr, bool taken[MAX_SIZE]){
  
  const static int rMove[4]={1,0,-1,0};
  const static int cMove[4]={0,1,0,-1};
  
  int nMove=0;
  
  
  for(int i=0;i<nDia;i++){
    
    if(i!=0 && taken[i]) continue;
    
    queue< pair< pair<int,int> , int > > Q;
    
    if(i==0)
      Q.push( make_pair(curr,0) );
    else
      Q.push( make_pair(dList[i],1) );
    
    bool succeed=false;
    int currBoard[MAX_SIZE][MAX_SIZE];

    for(int j=0;j<row;j++)
      for(int k=0;k<column;k++)
	currBoard[j][k] = board[j][k];
    
    while(!Q.empty()){
      
      pair< pair<int,int>, int > curr=Q.front();
      Q.pop();
      
      if(currBoard[curr.first.first][curr.first.second]==VISITED) continue;
      currBoard[curr.first.first][curr.first.second]=VISITED;
      
      for(int j=0;j<4;j++){
	
	pair< pair<int,int>, int >  next=curr;
	next.first.first+=rMove[j], next.first.second+=cMove[j];
	next.second++;
	
	if(currBoard[next.first.first][next.first.second]==ENDPOINT ||
	   currBoard[next.first.first][next.first.second]==DIAMOND ||
	   currBoard[next.first.first][next.first.second]==WALL ) {
	  nMove+=next.second-1;
	  succeed=true;	  
	  break;
	}
	else if(currBoard[next.first.first][next.first.second]==ROAD)
	  Q.push(next);
	  	
      }

      if(succeed) break;
            
    }
    
  }
  
  return nMove;
  
}

bool dfs(pair<int,int> start, pair<int,int> currPos, int currMove, int limit, bool taken[MAX_SIZE]){
  
  const static int rMove[4]={1,0,-1,0};
  const static int cMove[4]={0,1,0,-1};

  if(currMove+calcManhattan(currPos,taken)>limit) return false;
      
  for(int i=0;i<4;i++){
    
    pair<int,int> next=currPos;
    next.first+=rMove[i], next.second+=cMove[i];
    
    if(board[next.first][next.second]==ENDPOINT && next.first!=start.first && next.second!=start.second){ 
      
      board[next.first][next.second]=VISITED;
      
      bool allTaken=true;
      
      for(int j=0;j<nDia;j++)
	if(!taken[j]){
	  
	  allTaken=false;
	  taken[j]=true;
	  board[dList[j].first][dList[j].second]=ENDPOINT;
	  
	  if(dfs(dList[j],dList[j],currMove+1,limit,taken)) return true;
	  
          board[dList[j].first][dList[j].second]=DIAMOND;
	  taken[j]=false;

	}
      
      if(allTaken) return true;
      
      board[next.first][next.second]=ENDPOINT;
    }
    else if(board[next.first][next.second]==WALL){
      
      bool allTaken=true;
      
      for(int j=0;j<nDia;j++)
	if(!taken[j]){
	  
	  allTaken=false;
	  taken[j]=true;
	  board[dList[j].first][dList[j].second]=ENDPOINT;
	  
	  if(dfs(dList[j],dList[j],currMove+1,limit,taken)) return true;
	  
          board[dList[j].first][dList[j].second]=DIAMOND;
	  taken[j]=false;
	  
	}
      
      if(allTaken) return true;      
      
    }
    else if(board[next.first][next.second]==ROAD){

      board[next.first][next.second]=VISITED;

      if(dfs(start,next,currMove+1,limit,taken)) return true;
      
      board[next.first][next.second]=ROAD;
    }
    else if(board[next.first][next.second]==DIAMOND){

      board[next.first][next.second]=VISITED;
      int takenDia;
      
      for(int i=0;i<nDia;i++)
	if(dList[i].first==next.first && dList[i].second==next.second)
	  takenDia=i;

      taken[takenDia]=true;
      
      if(dfs(start,next,currMove+1,limit,taken)) return true;
      
      taken[takenDia]=false;
      
      board[next.first][next.second]=DIAMOND;
      
    }

  }


  return false;
}

int iterativeDeepning(){
  
  bool taken[MAX_SIZE];
  for(int i=0;i<nDia;i++)
    taken[i]=false;
    
  int limit=calcManhattan(dList[0],taken);
  
  while(true){
  
    taken[0]=true;
        
    board[dList[0].first][dList[0].second]=ENDPOINT;

    if(dfs(dList[0],dList[0],1,limit,taken)) break;
    
    limit++;
  }
  /*
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      if(board[i][j]==DIAMOND) cout << '*';
      if(board[i][j]==WALL) cout << '#';
      if(board[i][j]==ROAD) cout << '.';      
      if(board[i][j]==ENDPOINT) cout << "@";
      if(board[i][j]==VISITED) cout << "$";
    }cout << endl;
  }cout << endl;
  */
  return limit;
}

void work(){
  /*
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      if(board[i][j]==DIAMOND) cout << '*';
      if(board[i][j]==WALL) cout << '#';
      if(board[i][j]==ROAD) cout << '.';      
    }cout << endl;
  }cout << endl;

  for(int i=0;i<nDia;i++)
    cout << dList[i].first << ' ' << dList[i].second << endl;
  cout << endl;
  */
  
  cout << iterativeDeepning() << endl;
		    
}

int main(){
  
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
