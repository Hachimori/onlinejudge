#include<iostream>
using namespace std;
const int BUF = 50;

int initR, initC, initPosR, initPosC;

void read(){
  cin >> initR >> initC >> initPosR >> initPosC;
}

int win[BUF][BUF][BUF][BUF]; //(row,col,posR,posC)

int rec(int row, int col, int posR, int posC){
  int &ret = win[row][col][posR][posC];
  if(ret!=-1) return ret;
  if(row==1 && col==1) return ret = 0;
  ret = 0;
  for(int r=1;r<row;r++){
    if(r<=posR && !rec(row-r,col,posR-r,posC)) return ret = 1;
    if(r>posR  && !rec(    r,col,posR  ,posC)) return ret = 1;
  }
  for(int c=1;c<col;c++){
    if(c<=posC && !rec(row,col-c,posR,posC-c)) return ret = 1;
    if(c>posC  && !rec(row,    c,posR,posC  )) return ret = 1;
  }
  return ret;
}

void work(){
  cout << (rec(initR,initC,initPosR,initPosC) ? 
           "Gretel" : "Hansel") << endl;
}

int main(){
  memset(win,-1,sizeof(win));
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
