#include<iostream>
using namespace std;

int main(){
  int n, cases = 1;
  while(cin >> n,n){
    long long ans = 0, cnt = 0;
    for(long long i=2;i*i<=n;i++)
      if(n%i==0){
        int toPush = 1;
        while(n%i==0){
          toPush *= i;
          n /= i;
        }
        cnt++;
        ans += toPush;
      }
    if(n>1){
      cnt++;
      ans += n;
    }
    cout << "Case " << cases++ << ": " << ans+max(0LL,2-cnt) << endl;
  }
  return 0;
}
