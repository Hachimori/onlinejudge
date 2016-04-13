#include<iostream>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    int x, k;
    cin >> x >> k;
 
    if(x%k==0)
      cout << 0 << ' ' << k << endl;
    else
      cout << -x << ' ' << x << endl;
 }
  return 0;
}
