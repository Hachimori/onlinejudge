#include<iostream>
using namespace std;


int main(){
  int cases, L, R;
  cin >> cases;
  for(int k=0;k<cases;k++){
    cin >> L >> R;
    R -= L;
    if(R<=2){
      cout << R << endl;
      continue;
    }
    R-=2;
    int ans = 3;
    for(int i=2;;i++){
      R -= i;
      if(R<=0){
        cout << ans << endl;
        break;
      }
      R -= i;
      if(R<=0){
        cout << ans+1 << endl;
        break;
      }
      ans += 2;
    }
  }
  return 0;
}
