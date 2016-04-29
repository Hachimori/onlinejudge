#include<iostream>
using namespace std;

int eulerPhi(int n){
  int ret = n;
  for(int i=2;i*i<=n;i++)
    if(n%i==0){
      while(n%i==0) n /= i;
      ret -= ret/i;
    }
  if(n!=1) ret -= ret/n;
  return ret;
}

int gcd(int a, int b){
  return b==0 ? a : gcd(b,a%b);
}

int main(){
  long long n;
  while(cin >> n,n){
    if(n==1){
      cout << "0/1" << endl;
      continue;
    }
    n--;
    for(int deno=1;;deno++){
      if(eulerPhi(deno)<n){
        n -= eulerPhi(deno);
        continue;
      }
      for(int nume=1;;nume++){
        if(gcd(deno,nume)!=1) continue;
        if(n==1){
          cout << nume << '/' << deno << endl;
          goto _finish;
        }
        n--;
      }
    }
  _finish:;
  }
  return 0;
}
