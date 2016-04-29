#include<iostream>
using namespace std;

// http://en.wikipedia.org/wiki/Josephus_problem より引用
// しかし、これでは再帰が深くなりすぎて RTE となる。
int f(int n, int k){
  return n==0 ? 0 : (f(n-1,k)+k)%n;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int j=1;j<=n;j++)
      ans = (ans+k)%j;
    cout << "Case " << i+1 << ": " << ans+1 << endl;
  }
  return 0;
}
