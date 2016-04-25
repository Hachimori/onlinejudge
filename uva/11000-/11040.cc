#include<iostream>
#define BUF 9
using namespace std;

int b[BUF][BUF];

void read(){
  for(int r=0;r<BUF;r+=2)
    for(int c=0;c<=r;c+=2)
      cin >> b[r][c];
}

void work(){
  for(int r=1;r<BUF;r+=2)
    for(int c=0;c<=r;c+=2){
      int up = b[r-1][c], left = b[r+1][c], right = b[r+1][c+2];
      b[r+1][c+1] = (up-left-right)/2;
      b[  r][  c] = left+b[r+1][c+1];
      b[  r][c+1] = right+b[r+1][c+1];
    }

  for(int r=0;r<BUF;r++){
    for(int c=0;c<=r;c++){
      if(c) cout << ' ';
      cout << b[r][c];
    }
    cout << endl;
  }
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
