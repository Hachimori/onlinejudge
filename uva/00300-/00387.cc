#include<iostream>

#define MAX_PIECE 100
#define MAX_SIZE 4

using namespace std;

class Piece{
public:

  int r,c;
  char p[MAX_SIZE][MAX_SIZE];
  
  Piece(){}
  
};

int nPiece,nBlock;
Piece pList[MAX_PIECE];

bool read(){
  
  cin >> nPiece;
  if(nPiece==0) return false;
  
  nBlock=0;
  
  for(int i=0;i<nPiece;i++){
    cin >> pList[i].r >> pList[i].c;

    for(int j=0;j<pList[i].r;j++)
      for(int k=0;k<pList[i].c;k++){
	char c;
	cin >> c;
	if(c=='0')
	  pList[i].p[j][k] = c;
	else{
	  pList[i].p[j][k] = i+'1';
	  nBlock++;
	}
      }
  }
  
  return true;
}

bool match(Piece piece, int r, int c, char filled[MAX_SIZE][MAX_SIZE]){

  if(r+piece.r>MAX_SIZE || c+piece.c>MAX_SIZE) return false;
  
  for(int i=r;i<r+piece.r;i++)
    for(int j=c;j<c+piece.c;j++)
      if(filled[i][j]!='0' && piece.p[i-r][j-c]!='0') 
	return false;

  return true;
}

void putPiece(char result[MAX_SIZE][MAX_SIZE], char source[MAX_SIZE][MAX_SIZE], 
	      int r, int c, Piece piece){
  
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++)
      result[i][j] = source[i][j];
  
  for(int i=r;i<r+piece.r;i++)
    for(int j=c;j<c+piece.c;j++)
      if(piece.p[i-r][j-c]!='0') 
	result[i][j] = piece.p[i-r][j-c];
}

bool rec(int nUsed, bool used[MAX_PIECE], char filled[MAX_SIZE][MAX_SIZE]){
  
  if(nUsed==nPiece){ 
    for(int i=0;i<MAX_SIZE;i++){
      for(int j=0;j<MAX_SIZE;j++){
	cout << filled[i][j];
      }cout << endl;
    }
    return true;
  }
  
  for(int i=0;i<nPiece;i++){
    
    for(int r=0;r<MAX_SIZE;r++){
      for(int c=0;c<MAX_SIZE;c++){
	if(used[i]) continue;
	if(!match(pList[i],r,c,filled)) continue;
	
	char next[MAX_SIZE][MAX_SIZE];
	putPiece(next,filled,r,c,pList[i]);
	
	used[i] = true;
	
	if(rec(nUsed+1,used,next)) return true;
	
	used[i] = false;
      }
    }

  }
  
  return false;
}

void work(){
  
  bool used[MAX_PIECE];
  char filled[MAX_SIZE][MAX_SIZE];
  
  if(nBlock!=16){
    cout << "No solution possible" << endl;
    return;
  }
  
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++)
      filled[i][j] = '0';
  
  for(int i=0;i<nPiece;i++)
    used[i] = false;
  
  if(!rec(0,used,filled)) {
    cout << "No solution possible" << endl;
    return;
  }
  
}

int main(){
  
  for(int i=0;read();i++){
    if(i!=0) cout << endl;
    work();
  }

  return 0;
}
