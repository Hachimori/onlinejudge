#include<iostream>
using namespace std;
const int INF = 100000000;


long long S, D;

bool read(){
  return cin >> S >> D;
}


long long f(long long n){
  return n*(n+1)/2;
}


void work(){
  long long L = 0, R = INF;
  while(L!=R){
    long long mid = (L+R)/2;
    if(f(mid)-f(S-1)<D)
      L = mid+1;
    else
      R = mid;
  }
  cout << L << endl;
}


int main(){
  while(read()) work();
  return 0;
}
