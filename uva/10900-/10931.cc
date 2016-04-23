#include<iostream>
using namespace std;

int n;

bool read(){
  cin >> n;
  return n;
}

void work(){
  int cnt = 0;
  string s;
  while(n){
    cnt += n&1;
    s = (char)((n&1)+'0')+s;
    n >>= 1;
  }
  cout << "The parity of " << s << " is " << cnt << " (mod 2)." << endl;
}

int main(){
  while(read()) work();
  return 0;
}
