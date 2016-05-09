#include<iostream>
using namespace std;

int gcd(int a, int b){
  return b==0 ? a : gcd(b,a%b);
}

int main(){
  int n;
  while(cin >> n,n){
    int sum = 0;
    for(int i=1;i<n;i++)
      for(int j=i+1;j<=n;j++)
        sum += gcd(i,j);
    cout << sum << endl;
  }
  return 0;
}
