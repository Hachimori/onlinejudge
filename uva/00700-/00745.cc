#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<cassert>
#define MAX 20
#define WALL -1

using namespace std;

int allSum[MAX];
int size, numDigit;
char ansBoard[MAX][MAX];
char digits[9][MAX][MAX];

void initDigits(){
  
  for(int i=0;i<numDigit;i++)
      for(int k=0;k<size;k++)
	for(int l=0;l<size;l++)
	  digits[i][k][l] = WALL;
 
}

int getDigit(string str){
   for(int i=0;i<str.length();i++)
     if(isdigit(str[i])) return str[i]-'0';
   
   assert(false);
}

bool isValid(int row, int column, vector<string> piece){
  return (column<piece[row].length() && isdigit(piece[row][column]) );
}

bool noChar(string str){

  for(int i=0;i<str.length();i++)
    if(str[i]=='#' || isdigit(str[i])) return false;
  
  return true;
}

bool validPos(int n, int row, int column, char board[MAX][MAX]){
  
  for(int i=row,y=0;i<size+row;y++,i++){
    for(int j=column,x=0;j<size+column;x++,j++){
      
      if(i>=size && isdigit(digits[n][y][x])) return false;
      if(j>=size && isdigit(digits[n][y][x])) return false;
      if(isdigit(board[i][j]) && isdigit(digits[n][y][x])) return false;
      
    }
  }

  return true;
}

bool isCurrentDigit(string str, int &currDigit){
  
  for(int i=0;i<str.length();i++){
    if(isdigit(str[i])){ 
      if(str[i]-'0'==currDigit) break;
      else{ 
	currDigit = str[i]-'0';
	return false;
      }
    }
  }

  return true;
}

void round(int sum[MAX]){
  for(int i=size-1;i>=1;i--){
    if(sum[i]>=10){
      sum[i-1] += sum[i]/10;
      sum[i] = sum[i]%10;
    }
  }
}

bool greater(int allSum[MAX], int sum[MAX]){
  round(sum);
  for(int i=0;i<size;i++){
    if(allSum[i]<sum[i]) return true;
    else if(allSum[i]>sum[i]) return false;
  }

  return false;
}

void putPiece(int n, int row, int column, char board[MAX][MAX]){

  for(int i=row,y=0;i<size+row;y++,i++)
    for(int j=column,x=0;j<size+column;x++,j++)   
      if(isdigit(digits[n][y][x])) 
	board[i][j] = digits[n][y][x];
  
}

void copyAns(char board[MAX][MAX]){
  int sum[MAX]; 

  for(int i=0;i<size;i++)
    sum[i] = 0;

  // Case 0
  for(int i=0;i<size;i++){
    int partSum=0;
    for(int j=0;j<size;j++){
      partSum += board[j][i]-'0';
    }
    sum[i]=partSum;
  }
  if(greater(allSum,sum)){
    for(int i=0;i<size;i++)
      allSum[i] = sum[i];
    for(int i=0;i<size;i++)
      for(int j=0;j<size;j++)
	ansBoard[i][j] = board[i][j];
  }
  

  // Case 1
  for(int i=0;i<size;i++)
    sum[i] = 0;
  for(int i=0;i<size;i++){
    int partSum=0;
    for(int j=0;j<size;j++){
      partSum += board[i][j]-'0';
    }
    sum[i]=partSum;
  }
  if(greater(allSum,sum)){
    for(int i=0;i<size;i++)
      allSum[i] = sum[i];
    for(int i=0;i<size;i++)
      for(int j=0;j<size;j++)
	ansBoard[i][j] = board[j][size-1-i];
  }


  // Case 2
  for(int i=0;i<size;i++)
    sum[i] = 0;
  for(int i=0;i<size;i++){
    int partSum=0;
    for(int j=size-1;j>=0;j--){
      partSum += board[j][size-1-i]-'0';
    }
    sum[i]=partSum;
  }
  if(greater(allSum,sum)){
    for(int i=0;i<size;i++)
      allSum[i] = sum[i];
    for(int i=0;i<size;i++)
      for(int j=0,k=size-1;j<size;j++,k--)
	ansBoard[i][j] = board[size-1-i][k];
  } 
  

  // Case 3
  for(int i=0;i<size;i++)
    sum[i] = 0;
  for(int i=0;i<size;i++){
    int partSum=0;
    for(int j=size-1;j>=0;j--){
      partSum += board[size-1-i][j]-'0';
    }
    sum[i]=partSum;
  }
  if(greater(allSum,sum)){
    for(int i=0;i<size;i++)
      allSum[i] = sum[i];
    for(int i=0;i<size;i++)
      for(int j=0,k=size-1;j<size;j++,k--)
	ansBoard[i][j] = board[k][i];
  } 

  
}

void copyDigit(int n, vector<string> piece){
  
  int maxX=0, maxY=piece.size();


  for(int i=0;i<piece.size();i++)
    if(maxX<piece[i].length()) 
      maxX=piece[i].length();
  
  /*
  for(int i=0;i<piece.size();i++){
    for(int j=0;j<piece[i].length();j++){
      cout << piece[i][j];
    }cout << endl;
  }cout << endl;
  */


  for(int j=0;j<maxY;j++)
    for(int k=0;k<maxX;k++)
      if(isValid(j,k,piece))
	digits[n][j][k] = piece[j][k];

  return;
  
}

bool read(){
  
  cin >> size;
  if(size==0) return false;


  cin >> numDigit;
  initDigits();
  
  string str;
  int currDigit;
  getline(cin,str);

  vector<string> piece;

  for(int i=0;i<numDigit;i++){
    
    if(i==0){
      while(true){
	getline(cin,str);
	if(!noChar(str)){
	  currDigit = getDigit(str);
	  piece.push_back(str);
	  break;
	}
      }
    }
    
    for(int j=1;j<size+10000;j++){
      getline(cin,str);
      if(noChar(str)){ 
	j--;
	continue;
      }

      if(str[0]=='#'){
	if(piece.size()>=size+1) assert(false);
	copyDigit(i,piece);
	break;
      }
      else if(!isCurrentDigit(str,currDigit)){
	if(piece.size()>=size+1) assert(false);
	copyDigit(i,piece);
	piece.clear();
	piece.push_back(str);
	break;
      }
      
      piece.push_back(str);
    }

  }

  return true;
}

void rec(int row, int column, char board[MAX][MAX], bool used[9]){
  /*
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(board[i][j]==WALL) cout << ' ';
      else cout << board[i][j];
    }cout << endl;
  }cout << endl;
  */
  //cout << row << ' ' << column << endl;
  if(row==size){
    /*
    for(int i=0;i<size;i++)
      for(int j=0;j<size;j++)
	if(board[i][j]==WALL) 
	  return;
	  */
    copyAns(board);

    return;
  }
  else if(column==size){
    rec(row+1,0,board,used);
    return;
  }

  
  for(int i=0;i<numDigit;i++){
    
    if(used[i]) continue;

    
    if(validPos(i,row,column,board)){
      char backup[MAX][MAX];
      used[i] = true;
      
      for(int k=0;k<size;k++)
	for(int l=0;l<size;l++)
	  backup[k][l] = board[k][l];
      
      putPiece(i,row,column,backup);
      
      rec(row,column,backup,used);
      
      used[i] = false;
    
      
    }
  
  }
  
    
  if(board[row][column]!=WALL) rec(row,column+1,board,used);
  
}

void work(){
  
  /*
  for(int i=0;i<numDigit;i++){
    for(int k=0;k<size;k++){
      for(int l=0;l<size;l++){
	if(digits[i][k][l]==WALL) cout << ' ';
	else cout << digits[i][k][l];
      }cout << endl;
    }cout << endl;
  }
  cout << endl; cout << endl;
  */
  
  
  for(int i=0;i<size;i++)
    allSum[i] = -1;
  
  bool used[9];
  char board[MAX][MAX];
  
  for(int i=0;i<9;i++) used[i] = false;
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      board[i][j] = WALL;

  rec(0,0,board,used);
  
  if(allSum[0]==-1) assert(false);
  
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      cout << ansBoard[i][j];
    }cout << endl;
  }

  cout << endl;
  
}

int main(){
  
  while(read())
    work();

  return 0;
}
