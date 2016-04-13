#include<iostream>
using namespace std;

int main(){
  int n;
  while(1){
    cin >> n;
    if(n==0) break;

    int cnt = 0, nn = n;
    for(int i=2;i*i<=n;i++)
      if(n%i==0){
        while(n%i==0) n/=i;
        cnt++;
      }
    if(n>1) cnt++;
    cout << nn << " : " << cnt << endl;
  }
  return 0;
}
