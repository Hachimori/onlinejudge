#include<iostream>
#include<algorithm>
using namespace std;
const int BUF = 20005;

int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    int n, val[BUF];
    cin >> n;
    for(int i=0;i<n;i++) cin >> val[i];
    sort(val,val+n);

    int sum = 0;
    for(int i=n-3;i>=0;i-=3)
      sum += val[i];
    cout << sum << endl;
  }
  return 0;
}
