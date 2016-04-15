#include<iostream>
using namespace std;
const int BUF = 200005;

int main(){
  int n, x[BUF], y[BUF];
  while(cin >> n, n){
    for(int i=0;i<n;i++)
      cin >> x[i] >> y[i];
    int a = 0, b = 0;
    for(int i=0;i<n;i++)
      if(x[i]!=x[n/2] && y[i]!=y[n/2])
        ((x[i]<x[n/2])^(y[i]<y[n/2]) ? b : a)++;
    cout << a << ' ' << b << endl;
  }
  return 0;
}
