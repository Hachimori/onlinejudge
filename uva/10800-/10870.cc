// フィボナッチ数をO(log n)で求めるのと同じ要領で
// 行列の累乗に帰着させて解く。
//
// f(0), f(1), ..., f(d) が与えられた時,
// 一番最初の行列は以下の通り
//
// { {f(d  ), f(d-1), ... ,f(1), f(0)},
//   {f(d-1), f(d-2), ... ,f(0),    0},
//   {f(d-2), f(d-3), ... ,   0,    0},
//                    ...
//   {  f(1),   f(0), ... ,   0,    0},
//   {  f(0),      0, ... ,   0,    0} }
//
//
//
// d の値に応じた、掛けるべき行列は以下の通り
//
// d = 2
// { {a1,a2},
//   { 1, 0} }
//
// d = 3
// { {a1,a2,a3},
//   { 1, 0, 0},
//   { 0, 1, 0} }
//
// d = 4
// { {a1,a2,a3,a4},
//   { 1, 0, 0, 0},
//   { 0, 1, 0, 0},
//   { 0, 0, 1, 0} }
//
// d = 5
// { {a1,a2,a3,a4,a5},
//   { 1, 0, 0, 0, 0},
//   { 0, 1, 0, 0, 0},
//   { 0, 0, 1, 0, 0},
//   { 0, 0, 0, 1, 0} }
//
// ....
//
// 
//
// 最初の行列に、上記の行列をn回掛けた時の行列は以下の通り
// 
// { {f(d+n  ), f(d-1+n), ... ,  f(1+n),   f(  n)},
//   {f(d-1+n), f(d-2+n), ... ,    f(n),   f(n-1)},
//   {f(d-2+n), f(d-3+n), ... ,  f(n-1),   f(n-2)},
//                        ...
//   {  f(1+n),     f(n), ... ,f(n-d+2), f(n-d+1)},
//   {    f(n),   f(n-1), ... ,f(n-d+1),   f(n-d)} }
// 
// 
// http://ja.wikipedia.org/wiki/フィボナッチ数

#include<iostream>
#include<vector>
#define BUF 16
using namespace std;
typedef vector<int> Row;
typedef vector<Row> Matrix;

int nTerm, nMul, mod, a[BUF], f[BUF];

bool read(){
  cin >> nTerm >> nMul >> mod;
  if((nTerm|nMul|mod)==0) return false;

  for(int i=0;i<nTerm;i++){ cin >> a[i]; a[i]%=mod; }
  for(int i=0;i<nTerm;i++){ cin >> f[i]; f[i]%=mod; }
  
  return true;
}

Matrix mul(Matrix a, Matrix b){
  Matrix ret(nTerm,Row(nTerm));
  
  for(int i=0;i<nTerm;i++)
    for(int j=0;j<nTerm;j++){
      int sum = 0;
      for(int k=0;k<nTerm;k++)
        sum = (sum+a[i][k]*b[k][j])%mod;

      ret[i][j] = sum;
    }

  return ret;
}

Matrix pow(int n, Matrix &m){
  if(n==0){
    Matrix ret(nTerm,Row(nTerm,0));
    for(int i=0;i<nTerm;i++) ret[i][i] = 1;
    return ret;
  }
  if(n==1) return m;
  
  Matrix p = pow(n/2,m);

  return n%2==1 ? mul(m,mul(p,p)): mul(p,p);
}

void work(){
  Matrix init, toMul;
  init = toMul = Matrix(nTerm,Row(nTerm));

  for(int i=0;i<nTerm;i++)
    for(int j=0;j<nTerm;j++)
      if(0<=(nTerm-1-j)-i)
        init[i][j] = f[nTerm-1-j-i];
      else
        init[i][j] = 0;
  
  for(int i=0;i<nTerm;i++)
    for(int j=0;j<nTerm;j++)
      if(i==0)
        toMul[i][j] = a[j];
      else
        toMul[i][j] = (j==i-1);

  if(nMul-nTerm>=0){
    Matrix ans = mul(pow(nMul-nTerm,toMul),init);
    cout << ans[0][0] << endl;
  }
  else
    cout << f[nMul-1] << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
