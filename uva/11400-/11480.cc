#include<iostream>
using namespace std;

int main(){
  int n;
  for(int kk=0;cin >> n,n;kk++){
    long long ans = 0;
    for(int i=1;i*3+2<=n;i++)
      ans += (n-i-1)/2-i;
    cout << "Case " << kk+1 << ": " << ans << endl;
  }
  return 0;
}
