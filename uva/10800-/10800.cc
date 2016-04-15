#include<iostream>
#include<string>
#include<algorithm>

#define MAX_SIZE 55

using namespace std;

string ope;

void read(){
  cin >> ope;
}

void work(int cases){
  
  int maxHeight=0,minHeight=MAX_SIZE*2,currHeight=MAX_SIZE;
  char board[MAX_SIZE*2][MAX_SIZE];

  for(int i=0;i<MAX_SIZE*2;i++)
    for(int j=0;j<MAX_SIZE;j++)
      board[i][j] = ' ';


  for(int i=0;i<ope.size();i++){

    switch(ope[i]){
    case 'R':
      maxHeight = max(currHeight,maxHeight);
      minHeight = min(currHeight,minHeight);
      if(currHeight>=0) board[currHeight][i] = '/';
      currHeight++;
      break;
    case 'C':
      if(currHeight>=0) board[currHeight][i] = '_';
      maxHeight = max(currHeight,maxHeight);
      minHeight = min(currHeight,minHeight);
      break;      
    case 'F':
      currHeight--;
      if(currHeight>=0) board[currHeight][i] = '\\';
      maxHeight = max(currHeight,maxHeight);
      minHeight = min(currHeight,minHeight);
      break;      
    }

  }
 

  cout << "Case #" << cases << ":" << endl;
  for(int i=maxHeight;i>=minHeight;i--){
    
    cout << "| ";
    for(int j=0;j<ope.size();j++){
      
      bool charExist=false;
      for(int k=j;k<ope.size();k++)
	if(board[i][k]!=' ') charExist=true;
      
      if(charExist){
	while(j<ope.size() && board[i][j]==' '){ 
	  cout << board[i][j];
	  j++;
	}
	cout << board[i][j];
      }
      else break;
    }
    
    cout << endl;
  }
  
  cout << "+-";
  for(int i=0;i<ope.size();i++)
    cout << '-';
  cout << '-' << endl << endl;
  
}

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
