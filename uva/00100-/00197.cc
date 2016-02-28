#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

class Piece{
public:
  int d, r, c;
  bool b[3][3][3];

  Piece(){}
  Piece(int dd, int rr, int cc, bool bb[2][3][3]){
    d = dd;
    r = rr;
    c = cc;
    memset(b, 0, sizeof(b));
    for(int i=0;i<d;i++)
      for(int j=0;j<r;j++)
        for(int k=0;k<c;k++)
          b[i][j][k] = bb[i][j][k];
  }

  void droll(){
    bool nex[3][3][3] = {};
    for(int dd=0;dd<d;dd++)
      for(int rr=0;rr<r;rr++)
        for(int cc=0;cc<c;cc++)
          nex[dd][cc][r-rr-1] = b[dd][rr][cc];
    swap(r,c);
    for(int dd=0;dd<d;dd++)
      for(int rr=0;rr<r;rr++)
        for(int cc=0;cc<c;cc++)
          b[dd][rr][cc] = nex[dd][rr][cc];
  }

  void rroll(){
    bool nex[3][3][3] = {};
    for(int rr=0;rr<r;rr++)
      for(int dd=0;dd<d;dd++)
        for(int cc=0;cc<c;cc++)
          nex[cc][rr][d-dd-1] = b[dd][rr][cc];
    swap(d,c);
    for(int dd=0;dd<d;dd++)
      for(int rr=0;rr<r;rr++)
        for(int cc=0;cc<c;cc++)
          b[dd][rr][cc] = nex[dd][rr][cc];
  }

  void croll(){
    bool nex[3][3][3] = {};
    for(int cc=0;cc<c;cc++)
      for(int rr=0;rr<r;rr++)
        for(int dd=0;dd<d;dd++)
          nex[r-rr-1][dd][cc] = b[dd][rr][cc];
    swap(d,r);
    for(int dd=0;dd<d;dd++)
      for(int rr=0;rr<r;rr++)
        for(int cc=0;cc<c;cc++)
          b[dd][rr][cc] = nex[dd][rr][cc];
  }

  vector<Piece> generate(){
    vector<Piece> ret;
    for(int i=0;i<6;i++){
      for(int j=0;j<4;j++){
        croll();
        ret.push_back(*this);
      }
      if(i&1)
        droll();
      else
        rroll();
    }
    sort(ret.begin(),ret.end());
    ret.erase(unique(ret.begin(),ret.end()),ret.end());
    return ret;
  }

  bool operator== (const Piece &p) const {
    if(d!=p.d) return false;
    if(r!=p.r) return false;
    if(c!=p.c) return false;
    for(int i=0;i<d;i++)
      for(int j=0;j<r;j++)
        for(int k=0;k<c;k++)
          if(b[i][j][k]!=p.b[i][j][k])
            return false;
    return true;
  }

  bool operator< (const Piece &p) const {
    if(d!=p.d) return d<p.d;
    if(r!=p.r) return r<p.r;
    if(c!=p.c) return c<p.c;
    for(int i=0;i<d;i++)
      for(int j=0;j<r;j++)
        for(int k=0;k<c;k++)
          if(b[i][j][k]!=p.b[i][j][k])
            return b[i][j][k]<p.b[i][j][k];
    return false;
  }
};

vector<Piece> pRot[7];

void makePiece(){
  int dList[7] = {1,2,1,2,2,2,2};
  int rList[7] = {2,1,3,2,2,2,1};
  int cList[7] = {2,3,2,2,2,2,3};
  bool pList[7][2][3][3] = {
    {{{1,1,0}, // b
      {1,0,0},
      {0,0,0}},
     
     {{0,0,0},
      {0,0,0},
      {0,0,0}}
    },
    
    {{{0,1,0}, // c
      {0,0,0},
      {0,0,0}},

     {{1,1,1},
      {0,0,0},
      {0,0,0}}
    },

    {{{1,0,0}, // d
      {1,1,0},
      {0,1,0}},

     {{0,0,0},
      {0,0,0},
      {0,0,0}}
    },

    {{{1,1,0}, // e
      {0,1,0},
      {0,0,0}},

     {{0,1,0},
      {0,0,0},
      {0,0,0}}
    },

    {{{0,0,0}, // f
      {0,1,0},
      {0,0,0}},

     {{1,1,0},
      {0,1,0},
      {0,0,0}}
    },

    {{{0,0,0}, // g
      {1,1,0},
      {0,0,0}},

     {{0,1,0},
      {0,1,0},
      {0,0,0}}
    },

    {{{1,1,1}, // a
      {0,0,0},
      {0,0,0}},

     {{0,0,1},
      {0,0,0},
      {0,0,0}}
    },    
  };
  

  for(int i=0;i<7;i++){
    Piece p = Piece(dList[i],rList[i],cList[i],pList[i]);
    pRot[i] = p.generate();
  }
}

string s;

bool read(){
  return cin >> s;
}

void rec(int id, int d, int r, int c, int used[3][3][3], int order[6]){
  if(id==6){
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
        for(int k=0;k<3;k++)
          printf("%c", used[i][j][k]+'a');
    printf("\n");
    return;
  }
  if(r==3){
    rec(id,d+1,0,0,used,order);
    return;
  }
  if(c==3){
    rec(id,d,r+1,0,used,order);
    return;
  }
  if(used[d][r][c]!=-1){
    rec(id,d,r,c+1,used,order);
    return;
  }

  for(int i=0;i<pRot[order[id]].size();i++){
    Piece &p = pRot[order[id]][i];
    for(int dd=0;dd+p.d<=3;dd++)
      for(int rr=0;rr+p.r<=3;rr++)
        for(int cc=0;cc+p.c<=3;cc++){
          if (!(dd<=d && d<dd+p.d && rr<=r && r<rr+p.r && cc<=c && c<cc+p.c))
            continue;
          
          bool chk = false;
          for(int ddd=0;ddd<p.d;ddd++)
            for(int rrr=0;rrr<p.r;rrr++)
              for(int ccc=0;ccc<p.c;ccc++){
                if(p.b[ddd][rrr][ccc] && used[dd+ddd][rr+rrr][cc+ccc]!=-1)
                  goto _fail;
                if(p.b[ddd][rrr][ccc] && dd+ddd==d && rr+rrr==r && cc+ccc==c) chk = true;
              }
          if(!chk) goto _fail;

          for(int ddd=0;ddd<p.d;ddd++)
            for(int rrr=0;rrr<p.r;rrr++)
              for(int ccc=0;ccc<p.c;ccc++)
                if(p.b[ddd][rrr][ccc])
                  used[dd+ddd][rr+rrr][cc+ccc] = order[id]+1;

          rec(id+1,d,r,c+1,used,order);
          
          for(int ddd=0;ddd<p.d;ddd++)
            for(int rrr=0;rrr<p.r;rrr++)
              for(int ccc=0;ccc<p.c;ccc++)
                if(p.b[ddd][rrr][ccc])
                  used[dd+ddd][rr+rrr][cc+ccc] = -1;

          _fail:;
        }
  }
}

void work(){
  Piece aPiece;

  for(int i=0;i<pRot[6].size();i++){
    Piece &a = pRot[6][i];
    for(int d=0;d+a.d<=3;d++)
      for(int r=0;r+a.r<=3;r++)
        for(int c=0;c+a.c<=3;c++){
          for(int dd=0;dd<a.d;dd++)
            for(int rr=0;rr<a.r;rr++)
              for(int cc=0;cc<a.c;cc++)
                if((a.b[dd][rr][cc])^(s[(d+dd)*9+(r+rr)*3+c+cc]=='a'))
                  goto _fail;
          aPiece = a;
          goto _finish;
          _fail:;
        }
  }

 _finish:
  int order[6];
  for(int i=0;i<6;i++)
    order[i] = i;
  
  do{
    for(int i=0;i+aPiece.d<=3;i++)
      for(int j=0;j+aPiece.r<=3;j++)
        for(int k=0;k+aPiece.c<=3;k++){
          int used[3][3][3];
          memset(used,-1,sizeof(used));
          for(int dd=0;dd<aPiece.d;dd++)
            for(int rr=0;rr<aPiece.r;rr++)
              for(int cc=0;cc<aPiece.c;cc++)
                used[i+dd][j+rr][k+cc] = aPiece.b[dd][rr][cc] ? 0 : -1;
          rec(0,0,0,0,used,order);
        }
  }while(next_permutation(order,order+6));
  printf("\n");
}

int main(){
  makePiece();
  while(read())
    work();

  return 0;
}
