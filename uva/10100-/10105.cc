#include<iostream>
using namespace std;
const int BUF = 15;

int n, k, toSearch[BUF];

bool read(){
  if(!(cin >> n >> k)) return false;
  for(int i=0;i<k;i++) cin >> toSearch[i];
  return true;
}


long long frac(int t){
  long long ret = 1;
  for(int i=1;i<=t;i++) ret *= i;
  return ret;
}


void work(){
  long long ans = 1;
  ans *= frac(n);
  for(int i=0;i<k;i++) ans /= frac(toSearch[i]);
  cout << ans << endl;
}


int main(){
  while(read()) work();
  return 0;
}
