#include<iostream>
#include<climits>
#include<string>
#include<algorithm>

#define LIGHT 0
#define DARK 1
#define MAX_SIZE 15

using namespace std;

string name;
int board[MAX_SIZE][MAX_SIZE];

bool read(){
  
  cin >> name;
  if(name=="end") return false;

  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++){
      char c;
      cin >> c;

      if(c=='#') board[i][j]=DARK;
      else board[i][j]=LIGHT;
    }
      
  return true;
}

bool isInside(int r, int c){
  return (0<=r && r<10 && 0<=c && c<10);
}

int push(bool isPush[MAX_SIZE]){

  static const int rMove[5]={1,0,-1,0,0};
  static const int cMove[5]={0,1,0,-1,0};

  int currCost=0;
  int currBoard[MAX_SIZE][MAX_SIZE];


  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      currBoard[i][j] = board[i][j];


  for(int i=0;i<10;i++){
    
    if(isPush[i]){

      for(int j=0;j<5;j++){	
	int nextR=0+rMove[j], nextC=i+cMove[j];

	if(!isInside(nextR,nextC)) continue;
	
	if(currBoard[nextR][nextC]==DARK)
	  currBoard[nextR][nextC]=LIGHT;
	else 
	  currBoard[nextR][nextC]=DARK;
      }

      currCost++;
    }

  }

  /*
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(currBoard[i][j]==DARK) cout << "#";
      else cout << "O";
    }cout << endl;
  }cout << endl;   
  */

  for(int currRow=1;currRow<10;currRow++){
    for(int currColumn=0;currColumn<10;currColumn++){

      if(currBoard[currRow-1][currColumn]==LIGHT){

	for(int i=0;i<5;i++){
	  int nextR=currRow+rMove[i], nextC=currColumn+cMove[i];

	  if(!isInside(nextR,nextC)) continue;
	
	  if(currBoard[nextR][nextC]==DARK)
	    currBoard[nextR][nextC]=LIGHT;
	  else 
	    currBoard[nextR][nextC]=DARK;	  
	}
	
	currCost++;
      }      

    }
   
  }    

  for(int i=0;i<10;i++)
    if(currBoard[9][i]==LIGHT) return -1;
    
  if(currCost>100) return -1;

  return currCost;
}

void rec(int curr, bool isPush[MAX_SIZE], int &minCost){

  if(curr==10){

    int ans = push(isPush);
    
    if(ans==-1) return;
    else minCost = min(minCost,ans);

    return;
  }
  

  isPush[curr]=false;
  rec(curr+1,isPush,minCost);

  isPush[curr]=true;
  rec(curr+1,isPush,minCost);
  

}

void work(){

  int minCost=INT_MAX;  
  bool isPush[MAX_SIZE];
  
  rec(0,isPush,minCost);
  
  if(minCost==INT_MAX) cout << name << ' ' << -1 << endl;
  else 
    cout << name << ' ' << minCost << endl;
  
}

int main(){

  while(read())
    work();

  return 0;
}
