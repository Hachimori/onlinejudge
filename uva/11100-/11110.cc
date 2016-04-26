#include<iostream>
#include<string>
#include<sstream>
using namespace std;
const int BUF = 100;

int sz, b[BUF][BUF];

bool read(){
  cin >> sz;
  if(sz==0) return false;

  string dummy; getline(cin,dummy);

  memset(b,0,sizeof(b));
  for(int i=0;i<sz-1;i++){
    string s; getline(cin,s);
    stringstream in(s);
    int r, c;
    while(in >> r >> c){
      r--, c--;
      b[r][c] = i+1;
    }
  }

  return true;
}


void rec(int r, int c, int toColor){
  static int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
  b[r][c] = -1;
  for(int i=0;i<4;i++){
    int nr = r+dr[i], nc = c+dc[i];
    if(0<=nr && nr<sz && 0<=nc && nc<sz && b[nr][nc]!=-1 && b[nr][nc]==toColor)
      rec(nr,nc,toColor);
  }
}


void work(){
  int cnt = 0;
  for(int i=0;i<sz;i++)
    for(int j=0;j<sz;j++)
      if(b[i][j]>=0){
        rec(i,j,b[i][j]);
        cnt++;
      }
  cout << (cnt==sz ? "good" : "wrong") << endl;
}


int main(){
  while(read()) work();
  return 0;
}
