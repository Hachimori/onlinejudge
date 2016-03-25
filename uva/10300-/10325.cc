#include<iostream>
#define BUF 15
using namespace std;
typedef long long integer;

int n, nDiv, toDiv[BUF];

bool read(){
  if(!(cin >> n >> nDiv)) return false;
  for(int i=0;i<nDiv;i++)
    cin >> toDiv[i];
  return true;
}

int cntBit(int mask){
  int ret = 0;
  while(mask){
    ret += mask&1;
    mask >>= 1;
  }
  return ret;
}

int gcd(int a, int b){
  return b==0 ? a : gcd(b,a%b);
}

integer lcm(int a, int b){
  return 1LL*a/gcd(a,b)*b;
}

void work(){
  integer sum = 0;
  for(int mask=1;mask<(1<<nDiv);mask++){
    integer v = 1;
    for(int i=0;i<nDiv;i++)
      if(mask&(1<<i)){
        v = lcm(v,toDiv[i]);
        if(v>n) break;
      }
    if(cntBit(mask)%2==0)
      sum -= n/v;    
    else
      sum += n/v;
  }
  cout << n-sum << endl;
}

int main(){
  while(read()) work();
  return 0;
}
