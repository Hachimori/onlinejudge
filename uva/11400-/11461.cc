#include<iostream>
using namespace std;
const int BUF = 100005;

int L, R, tbl[BUF];

void makeTable(){
  memset(tbl,0,sizeof(tbl));
  for(int i=1;i*i<BUF;i++) tbl[i*i] = 1;
  for(int i=1;i<BUF;i++)
    tbl[i] += tbl[i-1];
}

bool read(){
  cin >> L >> R;
  return L>0 || R>0;
}

void work(){
  cout << tbl[R]-tbl[L-1] << endl;
}

int main(){
  makeTable();
  while(read()) work();
  return 0;
}
