//734
#include<iostream>
#include<cstdio>

#define MAX_NUM 7
#define MAX_SIZE 6
#define UP 0
#define UR 1
#define DR 2
#define DOWN 3
#define DL 4
#define UL 5

using namespace std;

int hexPos[MAX_NUM];
int board[MAX_NUM][MAX_SIZE];
int hexList[MAX_NUM][MAX_SIZE];

bool read(){

  char c;
  if(!(cin >> c)) return false;

  hexList[0][0] = c-'0';

  for(int i=1;i<MAX_SIZE;i++){
    cin >> c;
    hexList[0][i] = c-'0';
  }
  
  for(int i=1;i<MAX_NUM;i++){
    for(int j=0;j<MAX_SIZE;j++){
      cin >> c;
      hexList[i][j] = c-'0';
    }  
  }  

  cin >> c;

  return true;
}

bool rec(int curr, bool used[MAX_NUM]){
  if(curr==7) return true;

  if(curr==0){
    for(int i=0;i<7;i++){
      for(int j=0;j<6;j++){
	board[curr][j] = hexList[i][j];
      }
      used[i] = true;
      hexPos[curr] = i;

      if(rec(curr+1,used)) return true;

      used[i] = false;
    }
  }
  else if(curr==1){
    
    for(int i=0;i<7;i++){
      if(used[i]) continue;
      
      for(int j=0;j<6;j++){
	if(board[0][UP]==hexList[i][(j+3)%6]){

	  used[i]=true;
	  hexPos[curr]=i;
	  for(int k=0;k<6;k++)
	    board[curr][k]=hexList[i][(k+j)%6];
	  
	  if(rec(curr+1,used)) return true;
	  used[i]=false;
	}
      }
    }

  }
  else if(curr==2){

    for(int i=0;i<7;i++){
      if(used[i]) continue;

      for(int j=0;j<6;j++){
	if(board[1][DR]==hexList[i][(j+5)%6] &&
	   board[0][UR]==hexList[i][(j+4)%6]){
	  
	  for(int k=0;k<6;k++)
	    board[curr][k] = hexList[i][(k+j)%6];

	  used[i] = true;
	  hexPos[curr]=i;
	 
	  if(rec(curr+1,used)) return true;
	  
	  used[i] = false;
	}	   	
      }

    }
    
  }
  else if(curr==3){

    for(int i=0;i<7;i++){
      if(used[i]) continue;

      for(int j=0;j<6;j++){
	if(board[2][DOWN]==hexList[i][j] &&
	   board[0][DR]==hexList[i][(j+5)%6]){
	  
	  for(int k=0;k<6;k++)
	    board[curr][k] = hexList[i][(k+j)%6];
	  
	  used[i] = true;
	  hexPos[curr]=i;
	  
	  if(rec(curr+1,used)) return true;
	  
	  used[i] = false;
	}	   	
      }
      
    }
    
  }
  else if(curr==4){

    for(int i=0;i<7;i++){
      if(used[i]) continue;
      
      for(int j=0;j<6;j++){
	if(board[3][DL]==hexList[i][(j+1)%6] &&
	   board[0][DOWN]==hexList[i][j]){
	  
	  for(int k=0;k<6;k++)
	    board[curr][k] = hexList[i][(k+j)%6];
	  
	  used[i] = true;
	  hexPos[curr]=i;
	  
	  if(rec(curr+1,used)) return true;;
	  
	  used[i] = false;
	}	   	
      }

    }
    
  }
  else if(curr==5){

    for(int i=0;i<7;i++){
      if(used[i]) continue;

      for(int j=0;j<6;j++){
	if(board[4][UL]==hexList[i][(j+2)%6] &&
	   board[0][DL]==hexList[i][(j+1)%6]){
	  
	  for(int k=0;k<6;k++)
	    board[curr][k] = hexList[i][(k+j)%6];
	  
	  used[i] = true;
	  hexPos[curr]=i;
	 
	  if(rec(curr+1,used)) return true;
	  
	  used[i] = false;
	}	   	
      }

    }
    
  }
  else if(curr==6){

    for(int i=0;i<7;i++){
      if(used[i]) continue;
      
      for(int j=0;j<6;j++){
	if(board[5][UP]==hexList[i][(j+3)%6] && 
	   board[1][DL]==hexList[i][(j+1)%6] &&
	   board[0][UL]==hexList[i][(j+2)%6]){
	  
	  for(int k=0;k<6;k++)
	    board[curr][k] = hexList[i][(k+j)%6];

	  used[i] = true;
	  hexPos[curr]=i;
	 
	  if(rec(curr+1,used)) return true;
	  
	  used[i] = false;
	}	   	
      }

    }
    
  }
  

  return false;
}

void work(){
  /*
  for(int i=0;i<7;i++){
    for(int j=0;j<6;j++){
      cout << hexList[i][j];
    }cout << endl;
  }cout << endl;
  */

  bool used[MAX_NUM];
  for(int i=0;i<MAX_NUM;i++)
    used[i] = false;


  if(rec(0,used)) {

    cout << "PEG   HEX   POSITION" << endl;
    cout << "---   ---   --------" << endl;
    for(int i=0;i<7;i++){
      printf(" %d     %c     ",i,hexPos[i]+'A');
      
      for(int j=0;j<6;j++)
	cout << board[i][j];
      cout << endl;
    }
    
  }
  else cout << "No solution possible" << endl;
  
  cout << "************************************" << endl;
  
}

int main(){

  while(read())
    work();

  return 0;
}
