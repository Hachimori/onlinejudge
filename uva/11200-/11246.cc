#include<iostream>
using namespace std;

int n, k;

void read(){
  cin >> n >> k;
}

void work(){
  int ans = 0, cur = n;

  while(cur>0){
    int ub = cur/k;
    ans += cur-ub;
    cur = ub/k;
  }

  cout << ans << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
