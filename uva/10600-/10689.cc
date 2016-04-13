#include<iostream>
#include<vector>
using namespace std;
typedef vector< vector<int> > Matrix;

int a, b, n, mod;

void read(){
  int nDigit;
  cin >> a >> b >> n >> nDigit;
  
  mod = 1;
  for(int i=0;i<nDigit;i++)
    mod *= 10;
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

Matrix pow(Matrix &m, int nn){
  if(nn==0){
    Matrix ret(2);
    for(int i=0;i<4;i++)
      ret[i/2].push_back(i%3==0);
    return ret;
  }

  Matrix t = pow(m,nn/2);

  return nn&1 ? mul(m,mul(t,t)) : mul(t,t);
}

void work(){
  Matrix init(2);
  for(int i=0;i<4;i++)
    init[i/2].push_back(i!=0);
  
  Matrix ret;
  ret = pow(init,n);

  int coeffA, coeffB;
  
  if(n==0)
    coeffA = 1, coeffB = 0;
  else if(n==1)
    coeffA = 0, coeffB = 1;
  else
    coeffA = ret[0][0], coeffB = ret[0][1];

  cout << (coeffA*a+coeffB*b)%mod << endl;
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
