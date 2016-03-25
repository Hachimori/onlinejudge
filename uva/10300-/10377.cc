#include<iostream>
#include<string>

#define MAX_SIZE 65

using namespace std;

int row, column;
string board[MAX_SIZE];

void read(){

  cin >> row >> column; 
  
  getline(cin,board[0]);
  for(int i=0;i<row;i++)
    getline(cin,board[i]);
    
}

void work(){

  const int rMove[4]={-1,0,1,0}, cMove[4]={0,1,0,-1};

  int r, c, direction=0;
  cin >> r >> c;

  r--, c--;

  while(true){
    char ope;
    cin >> ope;
    
    if(ope=='Q') break;
    
    switch(ope){
    case 'R': 
      direction++;
      direction%=4;
      break;
    case 'L':
      direction+=4;
      direction--;
      direction%=4;
      break;
    case 'F':
      if(board[r+rMove[direction]][c+cMove[direction]]==' '){
	r+=rMove[direction];
	c+=cMove[direction];
      }
      break;
    }
    
  }

  cout << r+1 << ' ' << c+1 << ' ';
  
  switch(direction){
  case 0:
    cout << 'N';
    break;
  case 1:
    cout << 'E';
    break;
  case 2:
    cout << 'S';
    break;
  case 3:
    cout << 'W';
    break;
  }cout << endl;

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
