#include<iostream>
#include<cmath>
using namespace std;
const int INF = 1<<20;

int main(){
  int N;
  while(cin >> N, N){
    for(int x=1;;x++){
      if(x*x*x-(x-1)*(x-1)*(x-1)>N) break;
      double dblY = pow(1LL*x*x*x-N,1.0/3);
      if(fabs(dblY-(int)(dblY+0.5))<1e-4){
        cout << x << ' ' << (int)(dblY+0.5) << endl;
        goto _finish;
      }
    }
    cout << "No solution" << endl;
  _finish:;
  }
  return 0;
}
