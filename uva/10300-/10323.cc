#include<iostream>
using namespace std;
typedef long long integer;

int main(){
  integer tbl[14];
  tbl[0] = 1;
  for(int i=1;i<14;i++)
    tbl[i] = tbl[i-1]*i;

  int n;
  while(cin >> n){
    if(n<0){
      if(-n%2==0)
        cout << "Underflow!" << endl;
      else
        cout << "Overflow!" << endl;
      continue;
    }

    if(n>13)
      cout << "Overflow!" << endl;
    else if(tbl[n]<10000)
      cout << "Underflow!" << endl;
    else
      cout << tbl[n] << endl;
  }

  return 0;
}
