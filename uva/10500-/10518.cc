#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VII;


unsigned long long _n;
int mod;

bool read(){
  cin >> _n >> mod;
  return !(_n==0 && mod==0);
}


VII mul(VII a, VII b){
  VII c(a.size(),VI(b[0].size(),0));
  for(int i=0;i<a.size();i++)
    for(int j=0;j<b[0].size();j++)
      for(int k=0;k<a[0].size();k++)
        c[i][j] = (c[i][j]+a[i][k]*b[k][j])%mod;
  return c;
}


VII pow(VII &p, unsigned long long n){
  if(n==0){
    VII ret(2,VI(2,0));
    ret[0][0] = ret[1][1] = 1;
    return ret;
  }
  VII t = pow(p,n/2);
  return n&1 ? mul(t,mul(t,p)) : mul(t,t);
}


void work(int cases){
  VII p(2,VI(2,0));
  p[0][0] = p[0][1] = p[1][0] = 1;

  VII ret = pow(p,_n);
  cout << "Case " << cases << ": " << _n << ' ' << mod << ' ' << (ret[0][0]*2-1+mod)%mod << endl;
}


int main(){
  for(int i=0;read();i++)
    work(i+1);
  return 0;
}
