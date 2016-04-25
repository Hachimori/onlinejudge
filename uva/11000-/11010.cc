// DP + Greedy
//
//
// 全ての局面に対し、勝ち負けの結果を保存したテーブルを用意する。
// 自分と相手の両方が先攻になることで有利になる局面を優先的にとることがゲームの最適解となる。
//
// その原理は、
// 相手が先攻になることで相手が勝ってしまうような局面を、自分が先攻になることでそれを防げるのならば
// そうするべき、ということ。

#include<iostream>
#include<algorithm>
#include<cstdio>
#define BOARD 1005
#define BUF 20000   //3^9 19683
#define WIN 1
#define DRAW 0
#define LOSE -1
#define SELF 0
#define OPP 1
#define EMPTY 2
using namespace std;

class Value{
public:
  int v, id, self, opp;

  Value(){}
  Value(int v, int i, int s, int o): v(v), id(i), self(s), opp(o){}

  bool operator< (const Value &val) const {
    return v>val.v;
  }
};

class State{
public:
  int b[3][3];
};

int result[BUF];

int &getResult(State &s){
  int p = 1, ret = 0;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++,p*=3)
      ret += p*s.b[i][j];
  return result[ret];
}

bool isWin(State &curr, int id){
  for(int i=0;i<2;i++)
    for(int j=0;j<3;j++){
      int cnt = 0;
      for(int k=0;k<3;k++)
	if( (i?curr.b[j][k]:curr.b[k][j])==id ) cnt++;
      
      if(cnt==3) return true;
    }

  for(int i=0;i<2;i++){
    int cnt = 0;
    for(int j=0;j<3;j++)
      if( (i?curr.b[j][j]:curr.b[2-j][j])==id ) cnt++;
    
    if(cnt==3) return true;
  }

  return false;
}

int rec(State &curr, int nPut, int id){
  if(id==SELF && getResult(curr)!=-1) return getResult(curr);
  if(isWin(curr,!id)) return LOSE;
  if(nPut==9)        return DRAW;
  
  int minV = WIN;

  for(int r=0;r<3;r++)
    for(int c=0;c<3;c++){
      if(curr.b[r][c]!=EMPTY) continue;
      curr.b[r][c] = id;
      minV = min(minV,rec(curr,nPut+1,!id));
      curr.b[r][c] = EMPTY;
    }
  
  int ret;
  if(minV==WIN) ret = LOSE;
  if(minV==LOSE) ret = WIN;
  if(minV==DRAW) ret = DRAW;
  if(id==SELF) getResult(curr) = ret;
  
  return ret;
}

int nBoard;
char board[BOARD][3][3];

bool read(){
  if(scanf("%d",&nBoard)==EOF) return false;
  if(nBoard==0) return false;

  for(int i=0;i<nBoard;i++){
    char buf[20];
    if(scanf("%s",buf)==EOF) return false;
    for(int j=0;j<9;j++)
      board[i][j/3][j%3] = buf[j];
  }
  
  return true;
}

Value eval(char b[3][3], char id, int bid){
  int selfScore, oppScore;

  for(int k=0;k<2;k++){
    State s;
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++){
	if(b[i][j]=='.') s.b[i][j] = EMPTY;
	else if(b[i][j]==id) s.b[i][j] = (k ? OPP : SELF);
	else if(b[i][j]!=id) s.b[i][j] = (k ? SELF : OPP);
      }

    (k ? oppScore : selfScore) = getResult(s);
  }

  if(selfScore==WIN)
    return Value(selfScore+oppScore,bid,1,0);
  if(selfScore==LOSE)
    return Value(selfScore+oppScore,bid,0,1);
  if(selfScore==DRAW)
    return Value(selfScore+oppScore,bid,0,0);
}

void work(int cases){
  Value value[2][BOARD];
  
  for(int i=0;i<nBoard;i++){
    value[0][i] = eval(board[i],'X',i);
    value[1][i] = eval(board[i],'O',i);
  }
  sort(value[0],value[0]+nBoard);
  sort(value[1],value[1]+nBoard);
  
  
  
  int score[] = {0,0};
  
  bool used[BOARD];
  fill(used,used+nBoard,false);

  for(int i=0,sCur=0,oCur=0;i<nBoard;i+=2){
    while(used[value[0][sCur].id]) sCur++;
    score[0] += value[0][sCur].self;
    score[1] += value[0][sCur].opp;  
    used[value[0][sCur].id] = true; sCur++;

    while(used[value[1][oCur].id]) oCur++;
    score[0] += value[1][oCur].opp;
    score[1] += value[1][oCur].self;
    used[value[1][oCur].id] = true; oCur++;
  }
  
  if(score[0]>score[1]) printf("Case %d: Johnny wins.\n",cases);
  if(score[0]<score[1]) printf("Case %d: Mary wins.\n",cases);
  if(score[0]==score[1]) printf("Case %d: Draw.\n",cases);
}

int main(){
  State curr;
  fill(result,result+BUF,-1);
  for(int i=0;i<3;i++) 
    for(int j=0;j<3;j++) 
      curr.b[i][j] = EMPTY;
  rec(curr,0,SELF);
  
  for(int i=0;read();i++)
    work(i+1);

  return 0;
}
