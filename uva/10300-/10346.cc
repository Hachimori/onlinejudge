#include<iostream>
using namespace std;

int main(){
  int a, b;
  while(cin >> a  >> b){
    int cnt = a, nDust = a;
    while(nDust>=b){
      cnt += nDust/b;
      nDust = nDust%b+nDust/b;
    }
    cout << cnt << endl;
  }

  return 0;
}
