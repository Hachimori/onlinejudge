#include<iostream>
#define BUF 55
using namespace std;

unsigned long long tbl[BUF];

void makeTable(){
  tbl[1] = 1;
  tbl[2] = 2;
  
  for(int i=3;i<BUF;i++)
    tbl[i] = tbl[i-1]+tbl[i-2];
}

int N;

bool read(){
  cin >> N;
  return N!=0;
}

void work(){
  cout << tbl[N] << endl;
}

int main(){
  makeTable();
  
  while(read())
    work();
  
  return 0;
}
