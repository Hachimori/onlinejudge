#include<iostream>

#define UNKNOWN 1
#define EXIST 2
#define NON_EXIST 3

#define MAX_ROW 10
#define MAX_COLUMN 15

using namespace std;
  
const static int rMove[4]={0,-1,-1,-1};
const static int cMove[4]={1,1,0,-1};
int toScan[4]={10,24,15,24};
int nExist[10][24];

void read(){
  
  for(int i=0;i<10;i++)
    cin >> nExist[0][i];
  
  for(int i=0;i<24;i++)
    cin >> nExist[1][i];
  
  for(int i=0;i<15;i++)
    cin >> nExist[2][i];
  
  for(int i=0;i<24;i++)
    cin >> nExist[3][i];
   
}

bool isInside(int r, int c){
  return 0<=r && r<MAX_ROW && 0<=c && c<MAX_COLUMN;
}

bool failureChk(int board[MAX_ROW][MAX_COLUMN]){

  for(int i=0;i<MAX_ROW;i++)
    for(int j=0;j<MAX_COLUMN;j++)
      if(board[i][j]==UNKNOWN)
	return true;

  for(int i=0;i<4;i++){
    
    for(int j=0;j<toScan[i];j++){
	int currR,currC;      
	int nExistCell=0;

	if(i==0) currR=j,currC=0;
	else if(i==1 && j<9) currR=j, currC=0;
	else if(i==1 && j>=9) currR=9, currC=j-9;
	else if(i==2) currR=9,currC=j;
	else if(i==3 && j<14) currR=9, currC=j;
	else if(i==3 && j>=14) currR=9-(j-14), currC=14;

	while(isInside(currR,currC)){
	  if(board[currR][currC]==EXIST) nExistCell++;
	  currR+=rMove[i], currC+=cMove[i];
	}
	
	if(nExistCell!=nExist[i][j]) return true;
    }

  }
  
  return false;
}

void work(){

  int board[MAX_ROW][MAX_COLUMN];

  for(int i=0;i<MAX_ROW;i++)
    for(int j=0;j<MAX_COLUMN;j++)
      board[i][j] = UNKNOWN;
  
  
  while(true){

    bool advance=false;
    
    for(int i=0;i<4;i++){
          
      for(int j=0;j<toScan[i];j++){
	int currR,currC;      
	int nUnknown=0, nExistCell=0;

	if(i==0) currR=j,currC=0;
	else if(i==1 && j<9) currR=j, currC=0;
	else if(i==1 && j>=9) currR=9, currC=j-9;
	else if(i==2) currR=9,currC=j;
	else if(i==3 && j<14) currR=9, currC=j;
	else if(i==3 && j>=14) currR=9-(j-14), currC=14;

	while(isInside(currR,currC)){
	  if(board[currR][currC]==UNKNOWN) nUnknown++;
	  if(board[currR][currC]==EXIST) nExistCell++;
	  currR+=rMove[i], currC+=cMove[i];
	}

	if(i==0) currR=j,currC=0;
	else if(i==1 && j<9) currR=j, currC=0;
	else if(i==1 && j>=9) currR=9, currC=j-9;
	else if(i==2) currR=9,currC=j;
	else if(i==3 && j<14) currR=9, currC=j;
	else if(i==3 && j>=14) currR=9-(j-14), currC=14;

	if(nUnknown!=0 && nUnknown==nExist[i][j]-nExistCell){
	  while(isInside(currR,currC)){
	    if(board[currR][currC]==UNKNOWN) board[currR][currC]=EXIST;
	    currR+=rMove[i], currC+=cMove[i];
	  }
	  advance=true;
	}
	else if(nUnknown!=0 && nExistCell==nExist[i][j]){
	  while(isInside(currR,currC)){
	    if(board[currR][currC]==UNKNOWN) board[currR][currC]=NON_EXIST;
	    currR+=rMove[i], currC+=cMove[i];
	  }
	  advance=true;
	}      
      }

    }
    if(!advance) break;
    /*
    for(int i=0;i<MAX_ROW;i++){
      for(int j=0;j<MAX_COLUMN;j++){
	if(board[i][j]==UNKNOWN) cout << ' ';
	else if(board[i][j]==EXIST) cout << '#';
	else if(board[i][j]==NON_EXIST) cout << '.';
      }cout << endl;
    }
    cout << endl;
    */
  }


  if(failureChk(board)){
    for(int i=0;i<MAX_ROW;i++){
      for(int j=0;j<MAX_COLUMN;j++){
	cout << '.';
      }cout << endl;
    }
  }
  else {
    for(int i=0;i<MAX_ROW;i++){
      for(int j=0;j<MAX_COLUMN;j++){
	if(board[i][j]==EXIST) cout << '#';
	else cout << '.';
      }cout << endl;
    }
  }

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
