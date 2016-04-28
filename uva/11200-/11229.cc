#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
#include<cmath>
#define BUF 3
#define MAP (3*3*3*3*3*3*3*3*3)
#define SELF 0
#define OPP 1
#define EMPTY 2
#define win first
#define lose second
#define EPS (1.0e-9)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define GE(x,y) ((x)>=(y)-EPS)
#define LE(x,y) ((x)<=(y)+EPS)
using namespace std;
typedef pair<double,double> Result;

// for first player
bool firster(Result a, Result b){
  return GE(a.lose,b.lose);
}

// for second player
bool seconder(Result a, Result b){
  return LE(a.win,b.win);
}

class State{
public:
  int v[BUF][BUF];

  int toInt(){
    int p = 1, ret = 0;
    for(int i=0;i<BUF;i++)
      for(int j=0;j<BUF;j++){
        ret += p*v[i][j];
        p *= 3;
      }
    return ret;
  }
  
  bool operator< (const State &s) const {
    for(int i=0;i<BUF;i++)
      for(int j=0;j<BUF;j++)
        if(v[i][j]!=s.v[i][j])
          return v[i][j]<s.v[i][j];
    return false;
  }
};

double p[2][BUF][BUF];

void read(){
  for(int k=0;k<2;k++)
    for(int i=0;i<BUF;i++)
      for(int j=0;j<BUF;j++){
        cin >> p[k][i][j];
        p[k][i][j] *= 0.01;
      }
}

bool isWin(int id, State &b){
  for(int k=0;k<2;k++)
    for(int i=0;i<BUF;i++){
      bool ok = true;
      for(int j=0;j<BUF;j++)
        if((k?b.v[i][j]:b.v[j][i])!=id){
          ok = false;
          break;
        }
      if(ok) return true;
    }
  
  for(int k=0;k<2;k++){
    bool ok = true;
    for(int i=0;i<BUF;i++)
      if((k?b.v[i][i]:b.v[i][BUF-1-i])!=id){
        ok = false;
        break;
      }

    if(ok) return true;
  }

  return false;
}

bool filled(State &b){
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      if(b.v[i][j]==EMPTY) return false;
  return true;
}

Result rec(int id, double pp, State &b, Result M[2][MAP]){
  int num = b.toInt();
  
  if(M[id][num].win>-0.5) return Result(M[id][num].win*pp,M[id][num].lose*pp);
  if(isWin( id,b)) return Result(pp, 0);
  if(isWin(!id,b)) return Result( 0,pp);
  if(filled(b)) return Result(0,0);

  Result minV = Result(1,0);
  
  for(int r=0;r<BUF;r++)
    for(int c=0;c<BUF;c++){
      if(b.v[r][c]!=EMPTY) continue;

      b.v[r][c] = id;
      Result A = rec(!id,p[id][r][c],b,M);

      b.v[r][c] = !id;
      Result B = rec(!id,1-p[id][r][c],b,M);

      b.v[r][c] = EMPTY;
      
      if(id==SELF && firster(Result(A.win+B.win,A.lose+B.lose),minV))
        minV = Result(A.win+B.win,A.lose+B.lose);
      if(id==OPP  && seconder(Result(A.win+B.win,A.lose+B.lose),minV))
        minV = Result(A.win+B.win,A.lose+B.lose);
    }
  
  M[id][num] = Result(minV.lose,minV.win);
  return Result(pp*minV.lose,pp*minV.win);
}

void work(int cases){
  static Result M[2][MAP];
  State b;
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      b.v[i][j] = EMPTY;

  for(int i=0;i<2;i++)
    for(int j=0;j<MAP;j++)
      M[i][j].win = -1;

  Result ans = rec(SELF,1,b,M);
  printf("Case #%d: %.2lf\n",cases,100*ans.win);
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  
  return 0;
}
