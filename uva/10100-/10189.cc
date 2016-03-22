#include<iostream>
#include<string>

#define MAX_SIZE 105

using namespace std;

int row, column;
string board[MAX_SIZE];


bool read(){
  
  cin >> row >> column;
  if(row==0 && column==0) return false;
  
  for(int i=0;i<row;i++)
    cin >> board[i];
  
  return true;
}

bool isInside(int r, int c){
  return (0<=r && r<row && 0<=c && c<column);
}

void work(int cases){
  
  const static int rMove[8]={1,1,1,0,-1,-1,-1,0};
  const static int cMove[8]={-1,0,1,1,1,0,-1,-1};
  

  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      
      if(board[i][j]=='*') continue;

      int cnt=0;

      for(int k=0;k<8;k++){
	int nextR=i+rMove[k], nextC=j+cMove[k];
	
	if(!isInside(nextR,nextC)) continue;
	
	if(board[nextR][nextC]=='*') 
	  cnt++;	
      }

      board[i][j]=cnt+'0';

    }
  }

  cout << "Field #" << cases << ":" << endl;
  for(int i=0;i<row;i++)
    cout << board[i] << endl;


}

int main(){
  
  for(int cases=1;read();cases++){
    if(cases!=1) cout << endl;
    work(cases);
  }
  
  return 0;
}
