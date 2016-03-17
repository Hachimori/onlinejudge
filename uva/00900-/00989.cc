#include<iostream>
using namespace std;
const int BUF = 10;

int sz, b[BUF][BUF];

bool read(){
  if(!(cin >> sz)) return false;
  
  for(int i=0;i<sz*sz;i++)
    for(int j=0;j<sz*sz;j++)
      cin >> b[i][j];
  return true;
}

bool rec(int r, int c, bool rUsed[BUF][BUF], bool cUsed[BUF][BUF],
         bool bUsed[BUF][BUF], int bId[BUF][BUF]){
  if(c==sz*sz) return rec(r+1,0,rUsed,cUsed,bUsed,bId);
  if(r==sz*sz) return true;
  if(b[r][c]) return rec(r,c+1,rUsed,cUsed,bUsed,bId);
  for(int i=1;i<=sz*sz;i++){
    if(rUsed[r][i] || cUsed[c][i] || bUsed[bId[r][c]][i]) continue;
    b[r][c] = i;
    rUsed[r][i] = cUsed[c][i] = bUsed[bId[r][c]][i] = true;
    if(rec(r,c+1,rUsed,cUsed,bUsed,bId)) return true;
    b[r][c] = 0;
    rUsed[r][i] = cUsed[c][i] = bUsed[bId[r][c]][i] = false;
  }
  return false;
}

void work(){
  bool rUsed[BUF][BUF]={}, cUsed[BUF][BUF]={}, bUsed[BUF][BUF]={};
  int bId[BUF][BUF];
  for(int r=0;r<sz;r++)
    for(int c=0;c<sz;c++)
      for(int rr=r*sz;rr<r*sz+sz;rr++)
        for(int cc=c*sz;cc<c*sz+sz;cc++)
          bId[rr][cc] = r*sz+c;

  for(int r=0;r<sz*sz;r++)
    for(int c=0;c<sz*sz;c++)
      if(b[r][c]>0){
        rUsed[r][b[r][c]] = true;
        cUsed[c][b[r][c]] = true;
        bUsed[bId[r][c]][b[r][c]] = true;
      }

  if(rec(0,0,rUsed,cUsed,bUsed,bId)){
    for(int r=0;r<sz*sz;r++){
      for(int c=0;c<sz*sz;c++){
        if(c) cout << ' ';
        cout << b[r][c];
      }
      cout << endl;
    }
  }
  else
    cout << "NO SOLUTION" << endl;
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  return 0;
}
