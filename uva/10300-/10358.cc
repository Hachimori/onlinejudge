#include<iostream>
using namespace std;
const int sz = 8;

enum Result{SELF=0,OPP=1};
const int UNKNOWN = 0, LIMIT = sz*sz, INF = 1<<20;

int ar, ac, br, bc, cr, cc;
string b[sz];

void read(){
  for(int i=0;i<sz;i++){
    cin >> b[i];
    for(int j=0;j<sz;j++){
      if(b[i][j]=='M'){
        ar = i, ac = j;
        b[i][j] = '.';
      }
      else if(b[i][j]=='A'){
        cr = br, cc = bc;
        br = i, bc = j;
        b[i][j] = '.';     
      }
    }
  }
}

bool isInside(int r, int c){
  return 0<=r && r<sz && 0<=c && c<sz;
}

int inc(int n){
  n += n<0 ? -1 : 1;
  return (n<0 ? -1 : 1) * min(abs(n),LIMIT);
}

void work(){
  static int dr[]={-1,0,1,0,0}, dc[]={0,1,0,-1,0};
  static int dp[2][sz][sz][sz][sz][sz][sz]; // dp<0 if SELF is eliminated
                                            // dp>0 if SELF can escape
                                            // abs(dp): the number of turn
  for(int i=0;i<2;i++)
  for(int j=0;j<sz;j++)
  for(int k=0;k<sz;k++)
  for(int l=0;l<sz;l++)
  for(int m=0;m<sz;m++)
  for(int n=0;n<sz;n++)
  for(int o=0;o<sz;o++)
    dp[i][j][k][l][m][n][o] = UNKNOWN;
  
      
  for(int r1=0;r1<sz;r1++)
    for(int c1=0;c1<sz;c1++){
      if(b[r1][c1]=='#') continue;
      for(int r2=0;r2<sz;r2++)
        for(int c2=0;c2<sz;c2++){
          if(b[r2][c2]=='#') continue;
          for(int r3=0;r3<sz;r3++)
            for(int c3=0;c3<sz;c3++){
              if(b[r3][c3]=='#') continue;
              if((r1==r2 && c1==c2) || (r1==r3 && c1==c3)) 
                dp[SELF][r1][c1][r2][c2][r3][c3] = dp[OPP][r1][c1][r2][c2][r3][c3] = -1;
              if(b[r1][c1]=='P' && !((r1==r2 && c1==c2) || (r1==r3 && c1==c3)))
                dp[SELF][r1][c1][r2][c2][r3][c3] = dp[OPP][r1][c1][r2][c2][r3][c3] = 1;
            }
        }
    }

  while(1){
    bool update = false;
    for(int turn=0;turn<2;turn++)
      for(int r1=0;r1<sz;r1++)
        for(int c1=0;c1<sz;c1++){
          if(b[r1][c1]=='#') continue;
          for(int r2=0;r2<sz;r2++)
            for(int c2=0;c2<sz;c2++){
              if(b[r2][c2]=='#') continue;
              for(int r3=0;r3<sz;r3++)
                for(int c3=0;c3<sz;c3++){
                  if(b[r3][c3]=='#') continue;
                  int &orig = dp[turn][r1][c1][r2][c2][r3][c3];
                  if((r1==r2 && c1==c2) || (r1==r3 && c1==c3)) continue;
                  if(b[r1][c1]=='P' && !((r1==r2 && c1==c2) || (r1==r3 && c1==c3))) continue;
                  if(turn==SELF){
                    int minV = INF;
                    for(int i=0;i<5;i++){
                      int rr1 = r1+dr[i], cc1 = c1+dc[i];
                      if(!isInside(rr1,cc1) || b[rr1][cc1]=='#') continue;
                      int nex = dp[!turn][rr1][cc1][r2][c2][r3][c3];
                      if(nex==UNKNOWN) continue;
                      if(minV==INF || (minV<0 && nex>0))
                        minV = nex;
                      else if((minV<0 && nex<0) || (minV>0 && nex>0))
                        minV = min(minV,nex);
                    }
                    if(minV==INF) continue;
                    minV = inc(minV);
                    if(minV!=orig){
                      orig = minV;
                      update = true;
                    }
                  }
                  else{
                    int maxV = -INF;
                    for(int i=0;i<5;i++){
                      int rr2 = r2+dr[i], cc2 = c2+dc[i];
                      if(!isInside(rr2,cc2) || b[rr2][cc2]=='#') continue;
                      for(int j=0;j<5;j++){
                        int rr3 = r3+dr[j], cc3 = c3+dc[j];
                        if(!isInside(rr3,cc3) || b[rr3][cc3]=='#') continue;
                        int nex = dp[!turn][r1][c1][rr2][cc2][rr3][cc3];
                        if(nex==UNKNOWN) continue;
                        if(maxV==-INF || (maxV>0 && nex<0))
                          maxV = nex;
                        else if((maxV<0 && nex<0) || (maxV>0 && nex>0))
                          maxV = max(maxV,nex);
                      }
                    }
                    if(maxV==-INF) continue;
                    maxV = inc(maxV);
                    if(maxV!=orig){
                      orig = maxV;
                      update = true;
                    }
                  }
                }
            }
        }
    if(!update) break;
  }
  int result = dp[SELF][ar][ac][br][bc][cr][cc];
  if(abs(result)==sz*sz || result==UNKNOWN)
    cout << "You are trapped in the Matrix." << endl;
  else if(result<0)
    cout << "You are eliminated." << endl;
  else
    cout << "You can escape." << endl;
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
