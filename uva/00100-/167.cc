#include<iostream>
#include<cstdio>

#define MAX_SIZE 8

using namespace std;

int board[MAX_SIZE][MAX_SIZE];
bool isExist[MAX_SIZE][MAX_SIZE];
int maxScore;

void read(){

  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++)
      cin >> board[i][j];
  
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++)
      isExist[i][j]=false;

  maxScore=0;
}

bool isInside(int r, int c){
  return (0<=r && r<MAX_SIZE && 0<=c && c<MAX_SIZE);
}

bool isSafePos(int r, int c){

  for(int i=1;i<MAX_SIZE;i++)
    if(c-i<0) break;
    else if(isExist[r][c-i]) return false;

  for(int i=1;i<MAX_SIZE;i++)
    if(r-i<0 || c-i<0) break;
    else if(isExist[r-i][c-i]) return false;
    
  for(int i=1;i<MAX_SIZE;i++)
    if(r+i==MAX_SIZE || c-i<0) break;
    else if(isExist[r+i][c-i]) return false;    

  return true;
}

void rec(int curr, int score){

  if(curr==MAX_SIZE){    
    if(maxScore<score) maxScore=score;
    return;
  }
  

  for(int i=0;i<MAX_SIZE;i++)    
    if(isSafePos(i,curr)){
      isExist[i][curr]=true;
      rec(curr+1,score+board[i][curr]);
      isExist[i][curr]=false;
    }
   
}

void work(){
  
  /*
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++) cout << board[i][j] << ' ';
    cout << endl;
  }cout << endl;
  */

  rec(0,0);

  printf("%5d\n",maxScore);
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
