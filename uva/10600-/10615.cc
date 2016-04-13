#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define MAX_SIZE 105

using namespace std;

int size;
int adjList[MAX_SIZE][MAX_SIZE];
char toPut[MAX_SIZE][MAX_SIZE];

void read(){
  
  cin >> size;
  
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      adjList[i][j] = 0;
  
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++){
      char c;
      cin >> c;
      
      if(c=='*'){ 
	adjList[i][j]++;
      }
      
      toPut[i][j]=c;
    }
  
}

bool maxMatching(int board[MAX_SIZE][MAX_SIZE], int nColor){
  
  bool extendedMatch=false;
  int L2R[MAX_SIZE], R2L[MAX_SIZE];
  
  for(int i=0;i<size;i++)
    L2R[i] = R2L[i] = -1;
  
 ExtendMatching:
  
  for(int i=0;i<size;i++){
    
    if(L2R[i]!=-1) continue;
    
    int prevL2R[MAX_SIZE], prevR2L[MAX_SIZE];
    queue<int> Q;

    for(int j=0;j<size;j++)
      prevL2R[j] = prevR2L[j] = -1;
    Q.push(i);

    
    while(!Q.empty()){
      
      int curr = Q.front();
      Q.pop();

      for(int j=0;j<size;j++){
	if(adjList[curr][j]==0) continue;
	if(prevR2L[j]!=-1) continue;
	
	prevR2L[j] = curr;
	
	if(R2L[j]==-1){
	  
	  int currLeft = curr, currRight = j;
	  
	  while(true){
	    
	    L2R[currLeft] = currRight;
	    R2L[currRight] = currLeft;
	    
	    if(prevL2R[currLeft]==-1) break;

	    currRight = prevL2R[currLeft];
	    currLeft = prevR2L[currRight];
	    
	    R2L[currRight] = -1;
	  }
	  
	  extendedMatch=true;
	  goto ExtendMatching;
	}
	else{
	  prevL2R[R2L[j]] = j;
	  Q.push(R2L[j]);
	}
      }
      
    }
    
  }
  
  for(int i=0;i<size;i++)
    if(L2R[i]!=-1){
      if(board[i][L2R[i]]==0 && toPut[i][L2R[i]]=='*')
	board[i][L2R[i]] = nColor;
      adjList[i][L2R[i]]--;
    }

  return extendedMatch;
}

void work(){
  
  int maxDegree=0;
  int board[MAX_SIZE][MAX_SIZE], leftDegree[MAX_SIZE], rightDegree[MAX_SIZE];
  int nColor=0;

  for(int i=0;i<size;i++){
    int nDegree=0;
    for(int j=0;j<size;j++)
      if(adjList[i][j]>0)
	nDegree++;
    
    if(maxDegree<nDegree)
      maxDegree = nDegree;
    
    leftDegree[i] = nDegree;
  }
  
  for(int i=0;i<size;i++){
    int nDegree=0;
    for(int j=0;j<size;j++)
      if(adjList[j][i]>0)
	nDegree++;
    
    if(maxDegree<nDegree)
      maxDegree = nDegree;

    rightDegree[i] = nDegree;
  }
  
  for(int i=0;i<size;i++){
    
    if(leftDegree[i]==maxDegree) continue;
    
    for(int j=0;j<size;j++){
      
      if(rightDegree[j]==maxDegree) continue;
      
      while(leftDegree[i]!=maxDegree && rightDegree[j]!=maxDegree){
	adjList[i][j]++;
	leftDegree[i]++;
	rightDegree[j]++;
      }
      
    }
  }

  
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      board[i][j] = 0;
  
  while(true){
    
    nColor++;
    if(!maxMatching(board,nColor)) break;
    
  }
  

  cout << nColor-1 << endl;
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(j==0) cout << board[i][j];
      else cout << ' ' << board[i][j];
    }cout << endl;
  }
    
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
