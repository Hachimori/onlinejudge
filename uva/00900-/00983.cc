#include<iostream>
using namespace std;
typedef unsigned long long integer;
const int BUF = 1005;

int szB, szSub, b[BUF][BUF];

bool read(){
  if(!(cin >> szB >> szSub)) return false;
  for(int i=0;i<szB;i++)
    for(int j=0;j<szB;j++)
      scanf("%d",&b[i][j]);
  return true;
}


integer get(int r1, int c1, int r2, int c2, integer sub[BUF][BUF]){
  integer ret = 0;
  ret += sub[r2][c2];
  if(c1) ret -= sub[r2][c1-1];
  if(r1) ret -= sub[r1-1][c2];
  if(r1 && c1) ret += sub[r1-1][c1-1];
  return ret;
}


void work(){
  static integer sub[BUF][BUF];
  for(int i=0;i<szB;i++)
    for(int j=0;j<szB;j++){
      sub[i][j] = b[i][j];
      if(i) sub[i][j] += sub[i-1][j];
      if(j) sub[i][j] += sub[i][j-1];
      if(i && j) sub[i][j] -= sub[i-1][j-1];
    }

  integer sum = 0;
  for(int i=0;i+szSub<=szB;i++)
    for(int j=0;j+szSub<=szB;j++){
      integer t = get(i,j,i+szSub-1,j+szSub-1,sub);
      sum += t;
      cout << t << endl;
    }
  cout << sum << endl;
}


int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  return 0;
}
