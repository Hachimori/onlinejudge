#include<iostream>
using namespace std;
const int BUF = 40005;

bool tbl[BUF];

void makeTable(){
  for(int v=2;v<BUF;v++){
    for(int p=10;p<=v*v;p*=10){
      int hi = v*v/p, lo = v*v%p;
      if(hi+lo==v && hi>0 && lo>0){
        tbl[v] = true;
        goto _finish;
      }
    }
    tbl[v] = false;
  _finish:;
  }
}

int L, R;

void read(){
  cin >> L >> R;
}

void work(int cases){
  cout << "case #" << cases << endl;
  int cnt = 0;
  for(int i=L;i<=R;i++)
    if(tbl[i]){
      cnt++;
      cout << i << endl;
    }
  if(cnt==0)
    cout << "no kaprekar numbers" << endl;
}

int main(){
  makeTable();

  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work(i+1);
  }
  return 0;
}
