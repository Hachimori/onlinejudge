#include<iostream>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    int r, c;
    cin >> r >> c;
    r -= 2;
    c -= 2;
    cout << (r/3+(r%3>0))*(c/3+(c%3>0)) << endl;
  }
  return 0;
}
