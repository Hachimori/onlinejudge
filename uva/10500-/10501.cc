#include<iostream>
#include<string>
#include<set>
#include<utility>
#include<vector>
#include<queue>

#define MAX_SIZE 24
#define EMPTY 0
#define CONTINUE 0
#define TRUE 1
#define FAIL 2

using namespace std;

class Element{
public:

  int nChange, r, c;
  bool isVertical;
  
  Element(){}
  Element(int n, int r, int c, bool i):
    nChange(n), r(r), c(c), isVertical(i) {}
  
};

class Board{
public:
  
  int row, column;
  char board[MAX_SIZE][MAX_SIZE];
  
  bool isInside(int r, int c){
    return 0<=r && r<=row+1 && 0<=c && c<=column+1;
  }
  
  void deleteFind(int r, int c, char ch, vector< pair<int,int> > &posList){
    
    queue<Element> Q;
    bool visited[2][MAX_SIZE][MAX_SIZE];
    
    for(int i=0;i<2;i++)
      for(int j=0;j<row+2;j++)
	for(int k=0;k<column+2;k++)
	  visited[i][j][k] = false;
    
    Q.push(Element(1,r,c,true));
    Q.push(Element(1,r,c,false));
    
    while(!Q.empty()){
      
      Element curr = Q.front();
      Q.pop();
      
      if(visited[curr.isVertical][curr.r][curr.c]) continue;
      visited[curr.isVertical][curr.r][curr.c] = true;
      if(curr.nChange==4) continue;
      if(board[curr.r][curr.c]!=EMPTY){
	 
	if(ch!=board[curr.r][curr.c]) continue;
	else if(!(curr.r==r && curr.c==c)){
	  posList.push_back( make_pair(curr.r,curr.c) );
	  continue;
	}
      }
      
      
      if(curr.isVertical){
	if(isInside(curr.r,curr.c-1)) Q.push(Element(curr.nChange+1,curr.r,curr.c-1,false));
	if(isInside(curr.r,curr.c+1)) Q.push(Element(curr.nChange+1,curr.r,curr.c+1,false));
	if(isInside(curr.r+1,curr.c)) Q.push(Element(curr.nChange,curr.r+1,curr.c,true));
	if(isInside(curr.r-1,curr.c)) Q.push(Element(curr.nChange,curr.r-1,curr.c,true));
      }
      else{
	if(isInside(curr.r,curr.c-1)) Q.push(Element(curr.nChange,curr.r,curr.c-1,false));
	if(isInside(curr.r,curr.c+1)) Q.push(Element(curr.nChange,curr.r,curr.c+1,false));
	if(isInside(curr.r+1,curr.c)) Q.push(Element(curr.nChange+1,curr.r+1,curr.c,true));
	if(isInside(curr.r-1,curr.c)) Q.push(Element(curr.nChange+1,curr.r-1,curr.c,true));
      }
      
    }
    
  }
  
  bool operator< ( const Board &b ) const {
    
    for(int i=1;i<row+1;i++)
      for(int j=1;j<column+1;j++)
	if(board[i][j]<b.board[i][j]) return true;
	else if(board[i][j]>b.board[i][j]) return false;
    
    return false;
  }
  
};

int row, column;
Board b;


bool read(){
  
  for(int i=0;i<MAX_SIZE;i++){
    for(int j=0;j<MAX_SIZE;j++){
      b.board[i][j] = EMPTY;
    }
  }
  
  if(!(cin >> column >> row)) return false;
  
  b.row=row, b.column=column;
  
  for(int i=1;i<=row;i++)
    for(int j=1;j<=column;j++)
      cin >> b.board[i][j];
  
  return true;
}

int calc(Board &curr, vector< pair<int,int> > &delList){
  
  bool isEmpty=true;
  for(int i=1;i<row+1;i++)
    for(int j=1;j<column+1;j++)
      if(curr.board[i][j]!=EMPTY){
	isEmpty=false;
	break;
      }
  
  if(isEmpty) return TRUE;
  
  for(int i=1;i<row+1;i++){
    for(int j=1;j<column+1;j++){
      
      if(curr.board[i][j]==EMPTY) continue;
      
      vector< pair<int,int> > dList;
      
      curr.deleteFind(i,j,curr.board[i][j],dList);
      
      for(int k=0;k<dList.size();k++){
	char tmp = curr.board[i][j];
	
	curr.board[i][j]=EMPTY;
	curr.board[dList[k].first][dList[k].second]=EMPTY;
	
	delList.push_back(make_pair(i,j));
	delList.push_back(dList[k]);
	
	switch(calc(curr,delList)){
	case TRUE: 
	  return TRUE;

	case FAIL:
	  return FAIL;
	}
	
	curr.board[i][j]=tmp;
	curr.board[dList[k].first][dList[k].second]=tmp;
	
	delList.pop_back();
	delList.pop_back();
      }
      
      /*
	if(dList.size()!=0)
	return FAIL;
      */
    }
  }
  
  return FAIL;

}

void work(){
  
  vector< pair<int,int> > delList;

  
  if(calc(b,delList)==TRUE) {
    for(int i=0;i<delList.size();i+=2)
      cout << "(" << delList[i].second << ',' << delList[i].first << "),(" 
	   << delList[i+1].second << ',' << delList[i+1].first << ")" << endl;
  }
  else
    cout << "No solution" << endl;
  
  cout << endl;
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
