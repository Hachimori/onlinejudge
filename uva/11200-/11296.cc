#include<iostream>
using namespace std;
const int BUF = 1000001;

int main(){
  static long long tbl[BUF];
  
  tbl[0] = 1;
  for(long long i=2;i<BUF;i+=2)
    tbl[i] = tbl[i-2]+(i/2+1);

  int v;
  while(cin >> v) cout << tbl[v-v%2] << endl;

  return 0;
}
