#include<iostream>
#include<vector>
#define BUF 205
#define RANGE 1005
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
using namespace std;

class Spr{
public:
  int r, c, dir, range, time;

  Spr(){}
  Spr(int r, int c, int d, int rn, int t): r(r), c(c), dir(d), range(rn), time(t){}
  
  bool interrupt(int rr, int cc, int bgn, int end){
    if(abs(r-rr)>0 && abs(c-cc)>0) return false;
    if(abs(r-rr)+abs(c-cc)>range) return false;
    if(end-bgn>=(time+1)*4) return true;
    if(r==rr && c==cc) return true;

    int bp = bgn%((time+1)*4), ep = end%((time+1)*4);
    
    for(int d=dir,i=0;i<4;i++,d=(d+1)%4){
      int bTime = i*(time+1), eTime = bTime+time;
      if((d==NORTH && rr<r) || (d==EAST && cc>c) || 
	 (d==SOUTH && rr>r) || (d==WEST && cc<c)){
	if(bp<ep){
	  return max(bp,bTime)<min(ep,eTime);
	}
	else{
	  return !(ep<=bTime && eTime<=bp);
	}
      }
    }
  }
};

const int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
int row, col, bgn, end, nSpr;
bool safe[BUF][BUF];
Spr spr[RANGE];

bool isInside(int r, int c){
  return 0<=r && r<row && 0<=c && c<col;
}

bool read(){
  cin >> row >> col >> nSpr;
  if(row==0 && col==0 && nSpr==0) return false;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      safe[i][j] = true;
  
  for(int i=0;i<nSpr;i++){
    int r,c,t,len;
    char d;
    cin >> r >> c >> t >> len >> d;
    r--, c--;
    
    if(d=='N') spr[i] = Spr(r,c,NORTH,len,t);
    if(d=='E') spr[i] = Spr(r,c,EAST,len,t);
    if(d=='S') spr[i] = Spr(r,c,SOUTH,len,t);
    if(d=='W') spr[i] = Spr(r,c,WEST,len,t);

    for(int j=0;j<4;j++){
      for(int k=0;k<=len;k++){
	if(!isInside(r+k*dr[j],c+k*dc[j])) break;
	safe[r+k*dr[j]][c+k*dc[j]] = false;
      }
    }
  }
  cin >> bgn >> end;
  end++;
  
  return true;
}

void work(){
  int cnt = 0;
  
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      if(safe[i][j]){
	cnt++;
	continue;
      }
      bool ok = true;
      for(int k=0;k<nSpr;k++)
	if(spr[k].interrupt(i,j,bgn,end)){
	  ok = false;
	  break;
	}
      if(ok) cnt++;
    }
  }

  cout << cnt << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
