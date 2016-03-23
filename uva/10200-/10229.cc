#include<iostream>
#include<vector>
using namespace std;
typedef long long integer;
typedef vector< vector<integer> > Matrix;

int nMul, mod;

bool read(){
  if(!(cin >> nMul >> mod)) return false;

  mod = (1<<mod);
  
  return true;
}

Matrix mul(Matrix a, Matrix b){
  Matrix ret(2);
  for(int r=0;r<2;r++)
    for(int c=0;c<2;c++){
      int sum = 0;
      for(int i=0;i<2;i++)
        sum = (sum+a[r][i]*b[i][c])%mod;
      ret[r].push_back(sum);
    }
  return ret;
}

Matrix pow(Matrix &m, int n){
  if(n==0){
    Matrix ret(2);
    for(int i=0;i<4;i++)
      ret[i/2].push_back(i%3==0);
    return ret;
  }
  
  Matrix t = pow(m,n/2);
  
  return n&1 ? mul(m,mul(t,t)) : mul(t,t);
}

void work(){
  Matrix mat(2);
  for(int i=0;i<4;i++)
    mat[i/2].push_back(i!=0);
  
  Matrix ret = pow(mat,nMul+1);
  
  cout << ret[0][0] << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
