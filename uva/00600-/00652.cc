#include<iostream>
#include<map>
#include<set>
#include<utility>
#include<queue>
#include<vector>

#define LIMIT 30
#define MAX_SIZE 3
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

class Statement{
public:

  short posR, posC;
  short board[MAX_SIZE][MAX_SIZE];
  
  Statement(){}

  void move(int direction){

    if(direction==UP){
      swap(board[posR][posC],board[posR-1][posC]);
      posR--;
    }
    else if(direction==RIGHT){
      swap(board[posR][posC],board[posR][posC+1]);
      posC++;
    }
    else if(direction==DOWN){
      swap(board[posR][posC],board[posR+1][posC]);
      posR++;
    }
    else if(direction==LEFT){
      swap(board[posR][posC],board[posR][posC-1]);
      posC--;
    }
    
  }
  
  void print(){
    for(int i=0;i<MAX_SIZE;i++){
      for(int j=0;j<MAX_SIZE;j++){
	cout << board[i][j] << ' ';
      }cout << endl;
    }

  }

  bool operator< (const Statement &s) const {

    for(int i=0;i<MAX_SIZE;i++)
      for(int j=0;j<MAX_SIZE;j++)
	if(board[i][j]<s.board[i][j]) return true;
	else if(board[i][j]>s.board[i][j]) return false;

    return false;
  }
  
};

const static int rMove[4] = {-1,0,1,0};
const static int cMove[4] = {0,1,0,-1};
Statement init;
map<Statement,vector<short> > completeList;

bool isInside(int r, int c){
  return 0<=r && r<MAX_SIZE && 0<=c && c<MAX_SIZE;
}

void createComplete(){

  queue< pair<Statement, vector<short> >  > Q;
  Statement s;

  int cnt=1;
  
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++)
      s.board[i][j] = cnt++;
  
  s.board[2][2]=0;
  s.posR=2, s.posC=2;

  
  Q.push( make_pair(s,vector<short>()) );
  

  while(!Q.empty()){

    pair< Statement,vector<short> > curr = Q.front();
    Q.pop();


    if(completeList.find(curr.first)!=completeList.end()) continue;
    completeList[curr.first]=curr.second;
    
    if(curr.second.size()==LIMIT) continue;
    
    for(int i=0;i<4;i++){
      int nextR=rMove[i]+curr.first.posR;
      int nextC=cMove[i]+curr.first.posC;
    
      if(!isInside(nextR,nextC)) continue;
      
      curr.first.move(i);
      curr.second.push_back(i);
      
      Q.push(curr);
      
      curr.first.move((i+2)%4);
      curr.second.pop_back();
    }

  }
  
}

void read(){
  
  for(int i=0;i<MAX_SIZE;i++){
    for(int j=0;j<MAX_SIZE;j++){
      char c;
      cin >> c;

      if(c=='x'){
	init.board[i][j]=0;
	init.posR=i;
	init.posC=j;
      }
      else {
	init.board[i][j]=c-'0';
      }
    }
  }
  
}

void work(){
    
  if(completeList.find(init)!=completeList.end()) {
    for(int i=(int)(completeList[init].size()-1);i>=0;i--)
      if(completeList[init][i]==UP) cout << "d";
      else if(completeList[init][i]==RIGHT) cout << "l";
      else if(completeList[init][i]==DOWN) cout << "u";      
      else if(completeList[init][i]==LEFT) cout << "r";
    
    cout << endl;
  }
  else cout << "unsolvable" << endl;
                
}

int main(){
  
  int cases;
  cin >> cases;
  
  createComplete();

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }

  return 0;
}
