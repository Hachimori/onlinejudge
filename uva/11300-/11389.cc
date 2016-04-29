#include<iostream>
#include<algorithm>
using namespace std;
const int BUF = 10005;

int main(){
  int n, limit, mul, val[2][BUF];
  while(cin >> n >> limit >> mul, n|limit|mul){
    for(int i=0;i<2;i++)
      for(int j=0;j<n;j++)
        cin >> val[i][j];
    sort(val[0],val[0]+n);
    sort(val[1],val[1]+n);
    int ans = 0;
    for(int i=0;i<n;i++)
      ans += max(0,val[0][i]+val[1][n-i-1]-limit)*mul;
    cout << ans << endl;
  }
  return 0;
}
