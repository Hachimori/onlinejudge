#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef vector< vector<char> > State;

set<State> S;

bool isWin(State &st){
  for(int dir=0;dir<2;dir++)
    for(int i=0;i<3;i++){
      vector<char> row;
      for(int j=0;j<3;j++)
        row.push_back(dir?st[i][j]:st[j][i]);

      if(row[0]!='.' && row[0]==row[1] && row[1]==row[2]) 
        return true;
    }

  return (st[0][0]!='.' && st[0][0]==st[1][1] && st[1][1]==st[2][2]) ||
         (st[0][2]!='.' && st[0][2]==st[1][1] && st[1][1]==st[2][0]);
}

void make(bool turn, int nPut, State &curr){
  if(S.count(curr)) return;
  S.insert(curr);
  if(isWin(curr) || nPut==9) return;
  
  for(int r=0;r<3;r++)
    for(int c=0;c<3;c++){
      if(curr[r][c]!='.') continue;
      
      curr[r][c] = (turn ? 'X' : 'O');
      make(!turn,nPut+1,curr);
      curr[r][c] = '.';
    }
}

State st;

void read(){
  st = State(3,vector<char>(3));
  for(int r=0;r<3;r++)
    for(int c=0;c<3;c++)
      cin >> st[r][c];
}

void work(){
  if(S.count(st))
    cout << "yes" << endl;
  else
    cout << "no" << endl;
}

int main(){
  State curr(3,vector<char>(3,'.'));
  make(true,0,curr);
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
