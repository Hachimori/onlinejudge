#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int N, K;
  while(cin >> N >> K){
    double ans = 0;
    K = min(K,N-K);
    for(int i=1,j=N-K+1;i<=K;i++,j++)
      ans += log10(j)-log10(i);
    cout << (int)(ans+1) << endl;
  }
  return 0;
}
