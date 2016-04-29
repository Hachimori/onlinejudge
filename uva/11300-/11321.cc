#include<iostream>
using namespace std;
const int BUF = 10005;

class Sorter{
public:
  int mod;
  Sorter(){}
  Sorter(int mod): mod(mod){}
  bool operator() (int a, int b) const {
    if(a%mod!=b%mod) return a%mod<b%mod;
    if(a%2  && b%2) return a>b;
    if(a%2==0 && b%2==0) return a<b;
    return a%2 && b%2==0;
  }
};

int N, M, val[BUF];

bool read(){
  cin >> N >> M;
  if(N==0 && M==0) return false;
  for(int i=0;i<N;i++)
    cin >> val[i];
  return true;
}

void work(){
  sort(val,val+N,Sorter(M));
  cout << N << ' ' << M << endl;
  for(int i=0;i<N;i++)
    cout << val[i] << endl;
}

int main(){
  while(read()) work();
  cout << "0 0" << endl;
  return 0;
}
