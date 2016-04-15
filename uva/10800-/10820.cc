#include<iostream>
#define BUF 50001
using namespace std;

int N, table[BUF];

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

void makeTable(){
  table[1] = 1;
  for(int i=2;i<BUF;i++)
    table[i] = table[i-1] + eulerPhi(i)*2;
}

bool read(){
  cin >> N;
  return N!=0;
}

void work(){
  cout << table[N] << endl;
}

int main(){
  makeTable();
  
  while(read())
    work();
  
  return 0;
}
