#include<iostream>
using namespace std;

int main(){
  int n;
  while(cin >> n,n)
    cout << (n==1 || n*(n-1)/2%3 ? "NO" : "YES") << endl;
  return 0;
}
