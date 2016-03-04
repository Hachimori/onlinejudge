#include<iostream>
#include<cstdio>
using namespace std;
const int BUF = 100000;

int main(){
  double ans[BUF];
  ans[0] = 0;
  for(int i=1;i<BUF;i++) ans[i] = ans[i-1]+0.5/i;

  cout << "# Cards Overhang" << endl;

  int n;
  while(cin >> n)
    printf("%5d     %.3lf\n",n,ans[n]);
  
  return 0;
}
