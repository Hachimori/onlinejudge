#include<iostream>
using namespace std;

int main(){
  int n;
  while(cin >> n){
    int n8  = (n>> 0)&((1<<8)-1);
    int n16 = (n>> 8)&((1<<8)-1);
    int n24 = (n>>16)&((1<<8)-1);
    int n32 = (n>>24)&((1<<8)-1);
    cout << n << " converts to " << (n8<<24)+(n16<<16)+(n24<<8)+n32 << endl;
  }
  return 0;
}
