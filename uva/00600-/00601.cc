#include<iostream>
#include<queue>
#define r first
#define c second
using namespace std;
typedef pair<int,int> Point;
const int BUF = 90, dr[]={-1,0,1,0}, dc[]={0,1,0,-1};

enum Type{WHITE,BLACK,NONE};

int n, b[BUF][BUF];

bool read(){
  cin >> n;
  if(n==0) return false;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      char ch;
      cin >> ch;
      b[i][j] = ch=='W' ? WHITE : ch=='B' ? BLACK : NONE;
    }
  return true;
}


bool isInside(Point p){
  return 0<=p.r && p.r<n && 0<=p.c && p.c<n;
}


bool whiteWin(){
  bool visited[BUF][BUF]={};
  queue<Point> Q;
  
  for(int i=0;i<n;i++)
    if(b[i][0]==WHITE){
      visited[i][0] = true;
      Q.push(Point(i,0));
    }

  while(!Q.empty()){
    Point cur = Q.front();
    Q.pop();
    if(cur.c==n-1) return true;
    for(int i=0;i<4;i++){
      Point nex = Point(cur.r+dr[i],cur.c+dc[i]);
      if(!isInside(nex) || visited[nex.r][nex.c] || b[nex.r][nex.c]!=WHITE) continue;
      visited[nex.r][nex.c] = true;
      Q.push(nex);
    }
  }

  return false;
}


bool blackWin(){
  bool visited[BUF][BUF]={};
  queue<Point> Q;
  
  for(int i=0;i<n;i++)
    if(b[0][i]==BLACK){
      visited[0][i] = true;
      Q.push(Point(0,i));
    }

  while(!Q.empty()){
    Point cur = Q.front();
    Q.pop();
    if(cur.r==n-1) return true;
    for(int i=0;i<4;i++){
      Point nex = Point(cur.r+dr[i],cur.c+dc[i]);
      if(!isInside(nex) || visited[nex.r][nex.c] || b[nex.r][nex.c]!=BLACK) continue;
      visited[nex.r][nex.c] = true;
      Q.push(nex);
    }
  }

  return false;
}


void work(){
  if(whiteWin()){
    cout << "White has a winning path." << endl;
    return;
  }
  if(blackWin()){
    cout << "Black has a winning path." << endl;
    return;
  }
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      if(b[i][j]==NONE){
        b[i][j] = WHITE;
        if(whiteWin()){
          cout << "White can win in one move." << endl;
          return;
        }
        b[i][j] = NONE;
      }
    }

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      if(b[i][j]==NONE){
        b[i][j] = BLACK;
        if(blackWin()){
          cout << "Black can win in one move." << endl;
          return;
        }
        b[i][j] = NONE;
      }
    }

  cout << "There is no winning path." << endl;
}


int main(){
  while(read()) work();
  return 0;
}
