#include<iostream>

#define MAX_SIZE 52
#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

using namespace std;

class Bamper{
public:
  
  int value, cost;

  Bamper(){}
  Bamper(int v, int c): value(v), cost(c){}

};

class Ball{
public:

  int r, c, direction, life;

  Ball(){}
  Ball(int r, int c, int d, int l): r(r), c(c), direction(d), life(l) {}

};

int row, column;
int wallCost;
int total;
bool isBamper[MAX_SIZE][MAX_SIZE];
Bamper board[MAX_SIZE][MAX_SIZE];
Ball ball;

void readBoard(){
  
  int nBamper;

  cin >> column >> row;
  cin >> wallCost;

  cin >> nBamper;


  for(int i=0;i<=row;i++)
    for(int j=0;j<=column;j++)
      isBamper[i][j]=false;

  for(int i=0;i<nBamper;i++){
    int c,r;
    Bamper tmpBamper;

    cin >> c >> r >> tmpBamper.value >> tmpBamper.cost;

    isBamper[r][c] = true;
    board[r][c]=tmpBamper;
  }
  
}

bool read(){
  if(!(cin >> ball.c >> ball.r >> ball.direction >> ball.life)) return false;
  return true;
}

bool isWall(int r, int c){
  return (r<=1 || r>=row || c<=1 || c>=column);
}

int rec(Ball currBall, int score){
  
  static const int rMove[4]={0,1,0,-1}, cMove[4]={1,0,-1,0};
  
  int nextR = rMove[currBall.direction]+currBall.r;
  int nextC = cMove[currBall.direction]+currBall.c;
  
  //cout << currBall.r << ' ' << currBall.c << endl;
  if(currBall.life<=1) return score;
  
  if(isWall(nextR,nextC)){
    currBall.direction = (currBall.direction-1+4)%4;
    currBall.life-=wallCost+1;

    return rec(currBall,score);
  }
  
  if(isBamper[nextR][nextC]){
    currBall.direction = (currBall.direction-1+4)%4;
    currBall.life-=board[nextR][nextC].cost+1;

    return rec(currBall,score+board[nextR][nextC].value);
  }

  currBall.life--;
  currBall.r = nextR;
  currBall.c = nextC;
  
  return rec(currBall,score);
}

void work(){
  
  int ret = rec(ball,0);

  cout << ret << endl;
  
  total+=ret;
}

int main(){

  readBoard();

  total=0;

  while(read())
    work();

  cout << total << endl;

  return 0;
}
