#include<iostream>

#define INF 100000000
#define BUF 15

using namespace std;

class Matrix{
public:
  int r, c;

  Matrix(){}
  Matrix(int r, int c): r(r), c(c){}
};

int nMatrix;
Matrix mat[BUF];

bool read(){
  cin >> nMatrix;
  if(nMatrix==0) return false;

  for(int i=0;i<nMatrix;i++)
    cin >> mat[i].r >> mat[i].c;
  
  return true;
}

int rec(int l, int r, int dp[][BUF], int pi[][BUF]){
  if(dp[l][r]>=0) return dp[l][r];
  
  int minV = INF, minP;
  for(int i=l;i<r;i++)
    if(minV>rec(l,i,dp,pi)+rec(i+1,r,dp,pi)+mat[l].r*mat[i].c*mat[r].c){
      minV = rec(l,i,dp,pi)+rec(i+1,r,dp,pi)+mat[l].r*mat[i].c*mat[r].c;
      minP = i;
    }
  
  dp[l][r] = minV;
  pi[l][r] = minP;
  
  return dp[l][r];
}

void trace(int l, int r, int pi[][BUF]){
  if(pi[l][r]!=-1){
    cout << '(';
    trace(l,pi[l][r],pi);
    cout << " x ";
    trace(pi[l][r]+1,r,pi);
    cout << ')';
  }
  else
    cout << "A" << l+1;
}

void matrixMul(){
  int dp[BUF][BUF], pi[BUF][BUF];

  for(int i=0;i<nMatrix;i++)
    for(int j=0;j<nMatrix;j++)
      dp[i][j] = pi[i][j] = -1;

  for(int i=0;i<nMatrix;i++)
    dp[i][i] = 0;
    
  rec(0,nMatrix-1,dp,pi);

  trace(0,nMatrix-1,pi);
  cout << endl;
}

int main(){
  for(int i=0;read();i++){
    cout << "Case " << i+1 << ": ";
    matrixMul();
  }

  return 0;
}
