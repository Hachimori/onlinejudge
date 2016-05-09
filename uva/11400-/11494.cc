#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
  int r1, c1, r2, c2;
  while(cin >> r1 >> c1 >> r2 >> c2, r1|c1|r2|c2)
    if(r1==r2 && c1==c2)
      cout << 0 << endl;
    else if(abs(r1-r2)==abs(c1-c2) || r1==r2 || c1==c2)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  return 0;
}
