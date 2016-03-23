#include<iostream>
#include<sstream>
#define r first
#define c second
using namespace std;
typedef pair<int,int> Pos;
const int  BUF = 255;

int row = 250, col = 250;
char b[BUF][BUF];

int color(int r1, int c1, int r2, int c2, char ch){
  for(int i=r1;i<=r2;i++)
    for(int j=c1;j<=c2;j++)
      b[i][j] = ch;
}

void dfs(int r, int c, char to, char from){
  int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
  b[r][c] = to;
  for(int i=0;i<4;i++)
    if(0<=r+dr[i] && r+dr[i]<row && 0<=c+dc[i] && c+dc[i]<col && b[r+dr[i]][c+dc[i]]==from)
      dfs(r+dr[i],c+dc[i],to,from);
}

int main(){
  color(0,BUF-1,0,BUF-1,'O');
  
  while(1){
    string ope;
    getline(cin,ope);
    stringstream in(ope);
    string command;
    in >> command;
    if(command=="I"){
      in >> col >> row;
      color(0,0,row-1,col-1,'O');
    }
    if(command=="C"){
      color(0,0,row-1,col-1,'O');
    }
    if(command=="L"){
      int r, c;
      char ch;
      in >> c >> r >> ch;
      b[r-1][c-1] = ch;
    }
    if(command=="V"){
      int c, r1, r2;
      char ch;
      in >> c >> r1 >> r2 >> ch;
      c--, r1--, r2--;
      if(r1>r2) swap(r1,r2);
      color(r1,c,r2,c,ch);
    }
    if(command=="H"){
      int c1, c2, r;
      char ch;
      in >> c1 >> c2 >> r >> ch;
      c1--, c2--, r--;
      if(c1>c2) swap(c1,c2);
      color(r,c1,r,c2,ch);
    }
    if(command=="K"){
      int r1, c1, r2, c2;
      char ch;
      in >> c1 >> r1 >> c2 >> r2 >> ch;
      r1--, c1--, r2--, c2--;
      if(r1>r2) swap(r1,r2);
      if(c1>c2) swap(c1,c2);
      color(r1,c1,r2,c2,ch);
    }
    if(command=="F"){
      int r, c;
      char ch;
      in >> c >> r >> ch;
      c--, r--;
      if(ch!=b[r][c]) dfs(r,c,ch,b[r][c]);
    }
    if(command=="S"){
      string title;
      in >> title;
      cout << title << endl;
      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
          cout << b[i][j];
        cout << endl;
      }
    }
    if(command=="X") break;
  }

  return 0;
}
