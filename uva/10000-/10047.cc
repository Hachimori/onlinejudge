#include<iostream>
#include<queue>
#include<climits>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define MAX_SIZE 30

using namespace std;

class Element{
public:
  
  int r, c, bottom, direction;

  Element(){}
  Element(int r, int c, int b, int d): r(r), c(c), bottom(b), direction(d) {}

};

int row, column;
int initR, initC, goalR, goalC;
bool isWall[MAX_SIZE][MAX_SIZE];

bool read(){

  cin >> row >> column;
  if(row==0 && column==0) return false;

  for(int i=0;i<row;i++)
    for(int j=0;j<column;j++){
      char c;
      cin >> c;
      if(c=='S'){ 
	initR=i, initC=j;
	isWall[i][j]=false;
      }
      if(c=='T'){ 
	goalR=i, goalC=j;
	isWall[i][j] = false;
      }
      if(c=='.')
	isWall[i][j] = false;
      if(c=='#')
	isWall[i][j] = true;

    }
      
  return true;
}

bool isInside(int r, int c){
  return 0<=r && r<row && 0<=c && c<column;
}

void bfs(int cost[MAX_SIZE][MAX_SIZE][6][4]){

  const static int rMove[4] = {-1,0,1,0};
  const static int cMove[4] = {0,1,0,-1};

  queue<Element> Q;
  Q.push(Element(initR,initC,0,NORTH));


  cost[initR][initC][0][NORTH]=0;

  while(!Q.empty()){
    
    Element curr=Q.front();
    Q.pop();
    
    //cout << curr.r << ' ' << curr.c << endl;

    for(int i=0;i<4;i++){
      
      int nextR=curr.r+rMove[i];
      int nextC=curr.c+cMove[i];      
      
      if(i==curr.direction) {
	if(!isInside(nextR,nextC)) continue;
	if(isWall[nextR][nextC]) continue;

	if(cost[nextR][nextC][(curr.bottom+1)%5][i]
	     >cost[curr.r][curr.c][curr.bottom][curr.direction]+1){
	  cost[nextR][nextC][(curr.bottom+1)%5][i]
	    = cost[curr.r][curr.c][curr.bottom][curr.direction]+1;

	  Q.push(Element(nextR,nextC,(curr.bottom+1)%5,i));
	}
	
      }
      else if(i==(curr.direction+1)%4 || i==(4+curr.direction-1)%4 ){
	
	if(cost[curr.r][curr.c][curr.bottom][i]
	     >cost[curr.r][curr.c][curr.bottom][curr.direction]+1){
	  cost[curr.r][curr.c][curr.bottom][i]
	    = cost[curr.r][curr.c][curr.bottom][curr.direction]+1;

	  Q.push(Element(curr.r,curr.c,curr.bottom,i));
	}
      }
      
    }
    
  }


}

void work(int cases){
  
  int cost[MAX_SIZE][MAX_SIZE][6][4];
  
  for(int i=0;i<row;i++)
    for(int j=0;j<column;j++)
      for(int k=0;k<6;k++)
	for(int l=0;l<4;l++)
	  cost[i][j][k][l] = INT_MAX;

  bfs(cost);


  int minCost=INT_MAX;


    for(int j=0;j<4;j++)
      if(minCost>cost[goalR][goalC][0][j])
	minCost = cost[goalR][goalC][0][j];
  
  cout << "Case #" << cases << endl;
  if(minCost==INT_MAX) cout << "destination not reachable" << endl;
  else  cout << "minimum time = " << minCost << " sec" <<  endl;
}

int main(){

  for(int cases=1;read();cases++){
    if(cases!=1) cout << endl;
    work(cases);
  }

  return 0;
}
