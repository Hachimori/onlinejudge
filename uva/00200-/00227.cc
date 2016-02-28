#include<iostream>
#include<string>
#include<algorithm>

#define MAX_SIZE 5

using namespace std;

class Point{
public:

  int row, column;
  
  Point(){}
  Point(int r, int c): row(r), column(c){}
};

Point blankPos;
char board[MAX_SIZE][MAX_SIZE];
string ope;

bool read(){
  
  string boardStr[MAX_SIZE];

  for(int i=0;i<MAX_SIZE;i++)
    getline(cin,boardStr[i]);
  
  if(boardStr[0]=="Z") return false;
    
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<boardStr[i].length();j++){
      if(boardStr[i][j]==' ')
	blankPos = Point(i,j);
      
      board[i][j] = boardStr[i][j];
    }
  
  return true;
}

void fail(int cases){
  cout << "Puzzle #" << cases << ":" << endl;
  cout << "This puzzle has no final configuration." << endl;

  while(true){
    char c;
    cin >> c;
    if(c=='0') break;
  }

  string str;
  getline(cin,str);
}

void work(int cases){
  
  /*
  for(int i=0;i<MAX_SIZE;i++){
    for(int j=0;j<MAX_SIZE;j++) cout << board[i][j];
    cout << endl;
  }cout << endl;
  */

  for(int i=0;;i++){
    char ope;
    cin >> ope;

    if(ope=='0') break;

    if(ope=='A') {
      if(blankPos.row==0){
	fail(cases);
	return;
      }
      swap(board[blankPos.row][blankPos.column],board[blankPos.row-1][blankPos.column]);
      blankPos.row--;
    }

    if(ope=='R') {
       if(blankPos.column==4){
	 fail(cases);
	 return;
       }
      swap(board[blankPos.row][blankPos.column],board[blankPos.row][blankPos.column+1]);
      blankPos.column++;
    }

     if(ope=='L') {
       if(blankPos.column==0){
	 fail(cases);
	 return;
       }
      swap(board[blankPos.row][blankPos.column],board[blankPos.row][blankPos.column-1]);
      blankPos.column--;
    }

     if(ope=='B') {
       if(blankPos.row==4){
	 fail(cases);
	 return;
       }
      swap(board[blankPos.row][blankPos.column],board[blankPos.row+1][blankPos.column]);
      blankPos.row++;
     }
     
  }

  cout << "Puzzle #" << cases << ":" << endl;
  for(int i=0;i<MAX_SIZE;i++){
    for(int j=0;j<MAX_SIZE;j++){
      if(j!=0) cout << ' ' << board[i][j];
      else cout << board[i][j];
    }cout << endl;
  }

  string str;
  getline(cin,str);
}

int main(){
  
  for(int cases=1;read();cases++){
    if(cases!=1) cout << endl;
    work(cases);
  }

  return 0;
}
