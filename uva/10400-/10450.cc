#include<iostream>
using namespace std;
typedef long long integer;
const int BUF = 51;


integer rec(int cur, integer tbl[BUF]){
  if(cur==0) return 1;
  if(cur==1) return 2;
  integer &ret = tbl[cur];
  if(ret) return ret;
  return ret = rec(cur-1,tbl)+rec(cur-2,tbl);
}

int main(){
  integer tbl[BUF] = {0};
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    int n;
    cin >> n;
    cout << "Scenario #" << i+1 << ":" << endl;
    cout << rec(n,tbl) << endl << endl;
  }
  return 0;
}
