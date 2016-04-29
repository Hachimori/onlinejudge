#include<iostream>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    int a, b;
    cin >> a >> b;
    if(b%a==0)
      cout << a << ' ' << b << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
