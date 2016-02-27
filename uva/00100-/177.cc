#include<iostream>
#include<algorithm>
using namespace std;
const int BUF = 200, SHIFT = BUF/2, INF = (1<<20);

int n;

bool read(){
  cin >> n;
  return n>0;
}

void rec(int L, int R, bool goLeft[1<<13], bool left){
  goLeft[(L+R)/2-1] = left;
  if((R-L)/2>1){
    rec(L,L+(R-L)/2,goLeft,true);
    rec(L+(R-L)/2,R,goLeft,false);
  }
}

void work(){
  bool goLeft[1<<13] = {false};
  rec(0,1<<n,goLeft,true);

  bool vert[BUF][BUF], hori[BUF][BUF];
  memset(vert,false,sizeof(vert));
  memset(hori,false,sizeof(hori));

  int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
  int dir = 1, cr = 0, cc = 0;

  for(int i=0;i<(1<<n);i++){
    int nr = cr+dr[dir], nc = cc+dc[dir];
    switch(dir){
    case 0:
      vert[cr+SHIFT][cc+SHIFT] = true;
      break;
    case 1:
      hori[cr+SHIFT][cc+SHIFT] = true;
      break;
    case 2:
      vert[nr+SHIFT][nc+SHIFT] = true;
      break;
    case 3:
      hori[nr+SHIFT][nc+SHIFT] = true;
      break;
    }
    cr = nr, cc = nc;
    dir = goLeft[i] ? (dir+3)%4 : (dir+1)%4;
  }

  int minR = INF, minC = INF, maxR = -INF, maxC = -INF;
  for(int r=0;r<BUF;r++)
    for(int c=0;c<BUF;c++){
      if(vert[r][c] || hori[r][c]){
        minR = min(minR,r);
        maxR = max(maxR,r);
      }
      if(vert[r][c]){
        minC = min(minC,c*2);
        maxC = max(maxC,c*2);
      }
      if(hori[r][c]){
        minC = min(minC,c*2+1);
        maxC = max(maxC,c*2+1);
      }
    }

  for(int r=minR;r<=maxR;r++){
    string line;
    for(int c=minC;c<=maxC;c++){
      if(c%2==0 && vert[r][c/2])
        line += '|';
      else if(c%2==1 && hori[r][c/2])
        line += '_';
      else
        line += ' ';
    }
    while(line[line.size()-1]==' ') line.erase(line.size()-1,1);
    cout << line << endl;
  }
  cout << "^" << endl;
}

int main(){
  while(read()) work();
  return 0;
}
