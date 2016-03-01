#include<iostream>
using namespace std;
const int BUF = 30;

int sz, b[BUF][BUF];

bool read(){
  if(!(cin >> sz)) return false;
  for(int i=0;i<sz;i++)
    for(int j=0;j<sz;j++){
      char ch;
      cin >> ch;
      b[i][j] = ch=='1';
    }
  return true;
}

void rec(int r, int c){
  static int dr[]={-1,-1,-1,0,1,1,1,0}, dc[]={-1,0,1,1,1,0,-1,-1};
  b[r][c] = 0;
  for(int i=0;i<8;i++)
    if(0<=r+dr[i] && r+dr[i]<sz && 0<=c+dc[i] && c+dc[i]<sz && b[r+dr[i]][c+dc[i]])
      rec(r+dr[i],c+dc[i]);
}

void work(int cases){
  int ans = 0;
  for(int i=0;i<sz;i++)
    for(int j=0;j<sz;j++)
      if(b[i][j]){
        ans++;
        rec(i,j);
      }
  cout << "Image number " << cases << " contains " << ans << " war eagles." << endl;
}

int main(){
  for(int i=1;read();i++)
    work(i);
  
  return 0;
}
