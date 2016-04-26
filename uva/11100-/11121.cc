#include<iostream>
#include<cstdio>
#define INF (1<<30)
#define ROOK 5005
using namespace std;

class Rook{
public:
  int lr, ur, lc, uc;

  Rook(){}
  Rook(int lr, int lc, int ur, int uc):
    lr(lr), lc(lc), ur(ur), uc(uc){}
};

int nRook;
Rook rook[ROOK];

bool read(){
  scanf("%d",&nRook);
  if(nRook==0) return false;

  for(int i=0;i<nRook;i++){
    int lr, lc, ur, uc;
    scanf("%d%d%d%d",&lr,&lc,&ur,&uc);
    rook[i] = Rook(lr-1,lc-1,ur-1,uc-1);
  }
  
  return true;
}

void work(){
  int row[ROOK], col[ROOK];
  bool used[ROOK];

  for(int i=0;i<nRook;i++)
    used[i] = false;
  
  // determine row
  for(int r=0;r<nRook;r++){
    int minRem = INF, toPut;
    for(int i=0;i<nRook;i++){
      if(used[i] || !(rook[i].lr<=r && r<=rook[i].ur)) continue;

      if(minRem>rook[i].ur-r){
	minRem = rook[i].ur-r;
	toPut = i;
      }
    }
    
    if(minRem==INF){
      cout << "IMPOSSIBLE" << endl;
      return;
    }

    used[toPut] = true;
    row[toPut] = r;
  }
  

  for(int i=0;i<nRook;i++)
    used[i] = false;

  // determine col
  for(int c=0;c<nRook;c++){
    int minRem = INF, toPut;
    for(int i=0;i<nRook;i++){
      if(used[i] || !(rook[i].lc<=c && c<=rook[i].uc)) continue;

      if(minRem>rook[i].uc-c){
	minRem = rook[i].uc-c;
	toPut = i;
      }
    }
    
    if(minRem==INF){
      cout << "IMPOSSIBLE" << endl;
      return;
    }

    used[toPut] = true;
    col[toPut] = c;
  }

  for(int i=0;i<nRook;i++)
    printf("%d %d\n",row[i]+1,col[i]+1);
}

int main(){
  while(read())
    work();
  
  return 0;
}
