#include<iostream>
#include<climits>

#define MAX_SIZE 12

using namespace std;

int minScore;
char board[MAX_SIZE];

void read(){
  for(int i=0;i<MAX_SIZE;i++)
    cin >> board[i];

  minScore = INT_MAX;
}

void rec(){
  
  for(int i=0;i<MAX_SIZE-2;i++){
    if(board[i]=='o' && board[i+1]=='o' && board[i+2]=='-'){
      board[i]='-', board[i+1]='-',  board[i+2]='o';
      rec();
      board[i]='o', board[i+1]='o',  board[i+2]='-';
    }
  }
  
  for(int i=2;i<MAX_SIZE;i++){
    if(board[i]=='o' && board[i-1]=='o' && board[i-2]=='-'){
      board[i]='-', board[i-1]='-',  board[i-2]='o';
      rec();
      board[i]='o', board[i-1]='o',  board[i-2]='-';
    }
  }  
  
  int sum=0;
  for(int i=0;i<MAX_SIZE;i++)
    if(board[i]=='o') sum++;

  if(minScore>sum) minScore=sum;

}

void work(){
  
  rec();

  cout << minScore << endl;
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
