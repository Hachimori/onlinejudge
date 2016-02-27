#include<iostream>
#include<set>
#define BUF 55
using namespace std;

class Board{
public:
  int sz, b[BUF][BUF];

  void rotate(){
    Board t = *this;
    for(int i=0;i<sz;i++)
      for(int j=0;j<sz;j++)
        t.b[j][sz-i-1] = b[i][j];
    *this = t;
  }

  bool operator< (const Board &opp) const {
    for(int i=0;i<sz;i++)
      for(int j=0;j<sz;j++)
        if(b[i][j]!=opp.b[i][j])
          return b[i][j]<opp.b[i][j];
    return false;
  }
};

class Move{
public:
  int r, c;
  bool put;

  Move(){}
  Move(int r, int c, bool p): r(r), c(c), put(p){}
};

int sz;
Board init;
Move move[BUF*2];

bool read(){
  cin >> sz;
  if(sz==0) return false;

  init.sz = sz;
  for(int i=0;i<sz;i++)
    for(int j=0;j<sz;j++)
      init.b[i][j] = 0;

  for(int i=0;i<sz*2;i++){
    int r, c;
    char ch;
    cin >> r >> c >> ch;
    move[i] = Move(r-1,c-1,ch=='+');
  }

  return true;
}

void work(){
  Board curr = init;
  set<Board> S;

  S.insert(curr);

  for(int k=0;k<sz*2;k++){
    curr.b[move[k].r][move[k].c] = (move[k].put ? 1 : 0);

    for(int i=0;i<4;i++){
      if(S.count(curr)){
        cout << "Player " << !(k%2)+1 << " wins on move " << k+1 << endl;
        return;
      }
      curr.rotate();
    }
    S.insert(curr);
  }
  cout << "Draw" << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}