#include<iostream>
#include<vector>

#define MAX_SIZE 8

using namespace std;

class Point{
public:

  int r, c;

  Point(){}
  Point(int r, int c) : r(r), c(c) {}

};

vector<Point> bPawn, bKnight, bRook, bBishop, bQueen, bKing;
vector<Point> wPawn, wKnight, wRook, wBishop, wQueen, wKing;
char board[MAX_SIZE][MAX_SIZE];


bool read(){
  
  bPawn.clear(), bKnight.clear(), bRook.clear(), bBishop.clear(), bQueen.clear(), bKing.clear();
  wPawn.clear(), wKnight.clear(), wRook.clear(), wBishop.clear(), wQueen.clear(), wKing.clear();
  
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++){
      cin >> board[i][j];
      
      if(board[i][j]=='p') bPawn.push_back(Point(i,j));
      if(board[i][j]=='r') bRook.push_back(Point(i,j));
      if(board[i][j]=='b') bBishop.push_back(Point(i,j));
      if(board[i][j]=='q') bQueen.push_back(Point(i,j));
      if(board[i][j]=='k') bKing.push_back(Point(i,j));
      if(board[i][j]=='n') bKnight.push_back(Point(i,j));

      if(board[i][j]=='P') wPawn.push_back(Point(i,j));
      if(board[i][j]=='R') wRook.push_back(Point(i,j));
      if(board[i][j]=='B') wBishop.push_back(Point(i,j));
      if(board[i][j]=='Q') wQueen.push_back(Point(i,j));
      if(board[i][j]=='K') wKing.push_back(Point(i,j));
      if(board[i][j]=='N') wKnight.push_back(Point(i,j));
    }
  

  if(bKing.size()==0 && wKing.size()==0) return false;
  return true;
}
  
bool isInside(int r, int c){
  return (0<=r && r<MAX_SIZE && 0<=c && c<MAX_SIZE);
}

void work(int cases){
  
  static const int brPawn[2]={1,1}, bcPawn[2]={-1,1}, wrPawn[2]={-1,-1}, wcPawn[2]={-1,1};
  static const int rBishop[4]={1,1,-1,-1}, cBishop[4]={-1,1,1,-1};
  static const int rQueen[8]={1,1,1,0,-1,-1,-1,0}, cQueen[8]={-1,0,1,1,1,0,-1,-1};
  static const int rRook[4]={1,0,-1,0}, cRook[4]={0,1,0,-1};
  static const int rKnight[8]={2,2,1,-1,-2,-2,-1,1}, cKnight[8]={-1,1,2,2,1,-1,-2,-2};


  for(int i=0;i<bPawn.size();i++)
    for(int j=0;j<2;j++)
      if(isInside(bPawn[i].r+brPawn[j],bPawn[i].c+bcPawn[j]) && 
	 board[bPawn[i].r+brPawn[j]][bPawn[i].c+bcPawn[j]]=='K') {
	
	cout << "Game #" << cases << ": white king is in check." << endl;
	return;

      }
  
  for(int i=0;i<bBishop.size();i++)
    for(int j=0;j<4;j++)
      for(int k=1;isInside(bBishop[i].r+k*rBishop[j],bBishop[i].c+k*cBishop[j]);k++)
	if(board[bBishop[i].r+k*rBishop[j]][bBishop[i].c+k*cBishop[j]]=='K') {
	  
	  cout << "Game #" << cases << ": white king is in check." << endl;
	  return;
	}
        else if(board[bBishop[i].r+k*rBishop[j]][bBishop[i].c+k*cBishop[j]]!='.') 
	  break;
 
  for(int i=0;i<bRook.size();i++)
    for(int j=0;j<4;j++)
      for(int k=1;isInside(bRook[i].r+k*rRook[j],bRook[i].c+k*cRook[j]);k++)
	if(board[bRook[i].r+k*rRook[j]][bRook[i].c+k*cRook[j]]=='K') {
	  
	  cout << "Game #" << cases << ": white king is in check." << endl;
	  return;
	}
        else if(board[bRook[i].r+k*rRook[j]][bRook[i].c+k*cRook[j]]!='.') 
	  break;
  
  for(int i=0;i<bQueen.size();i++)
    for(int j=0;j<8;j++)
      for(int k=1;isInside(bQueen[i].r+k*rQueen[j],bQueen[i].c+k*cQueen[j]);k++)
	if(board[bQueen[i].r+k*rQueen[j]][bQueen[i].c+k*cQueen[j]]=='K') {
	  
	  cout << "Game #" << cases << ": white king is in check." << endl;
	  return;
	}
        else if(board[bQueen[i].r+k*rQueen[j]][bQueen[i].c+k*cQueen[j]]!='.') 
	  break;
  
  for(int i=0;i<bKnight.size();i++)
    for(int j=0;j<8;j++)
      if(isInside(bKnight[i].r+rKnight[j],bKnight[i].c+cKnight[j])
	  && board[bKnight[i].r+rKnight[j]][bKnight[i].c+cKnight[j]]=='K') {
	
	cout << "Game #" << cases << ": white king is in check." << endl;
	return;
      }
  

  
  for(int i=0;i<wPawn.size();i++)
    for(int j=0;j<2;j++)
      if(isInside(wPawn[i].r+wrPawn[j],wPawn[i].c+wcPawn[j]) && 
	 board[wPawn[i].r+wrPawn[j]][wPawn[i].c+wcPawn[j]]=='k') {
	
	cout << "Game #" << cases << ": black king is in check." << endl;
	return;

      }
  
  for(int i=0;i<wBishop.size();i++)
    for(int j=0;j<4;j++)
      for(int k=1;isInside(wBishop[i].r+k*rBishop[j],wBishop[i].c+k*cBishop[j]);k++)
	if(board[wBishop[i].r+k*rBishop[j]][wBishop[i].c+k*cBishop[j]]=='k') {
	  
	  cout << "Game #" << cases << ": black king is in check." << endl;
	  return;
	}
        else if(board[wBishop[i].r+k*rBishop[j]][wBishop[i].c+k*cBishop[j]]!='.') 
	  break;
 
  for(int i=0;i<wRook.size();i++)
    for(int j=0;j<4;j++)
      for(int k=1;isInside(wRook[i].r+k*rRook[j],wRook[i].c+k*cRook[j]);k++)
	if(board[wRook[i].r+k*rRook[j]][wRook[i].c+k*cRook[j]]=='k') {
	  
	  cout << "Game #" << cases << ": black king is in check." << endl;
	  return;
	}
        else if(board[wRook[i].r+k*rRook[j]][wRook[i].c+k*cRook[j]]!='.') 
	  break;
  
  for(int i=0;i<wQueen.size();i++)
    for(int j=0;j<8;j++)
      for(int k=1;isInside(wQueen[i].r+k*rQueen[j],wQueen[i].c+k*cQueen[j]);k++)
	if(board[wQueen[i].r+k*rQueen[j]][wQueen[i].c+k*cQueen[j]]=='k') {
	  
	  cout << "Game #" << cases << ": black king is in check." << endl;
	  return;
	}
        else if(board[wQueen[i].r+k*rQueen[j]][wQueen[i].c+k*cQueen[j]]!='.') 
	  break;
  
  for(int i=0;i<wKnight.size();i++)
    for(int j=0;j<8;j++)
      if(isInside(wKnight[i].r+rKnight[j],wKnight[i].c+cKnight[j])
	  && board[wKnight[i].r+rKnight[j]][wKnight[i].c+cKnight[j]]=='k') {
	
	cout << "Game #" << cases << ": black king is in check." << endl;
	return;
      }



  cout << "Game #" << cases << ": no king is in check." << endl;


}

int main(){

  for(int i=1;;i++){
    if(!read()) break;
    work(i);
  }

  return 0;
}
