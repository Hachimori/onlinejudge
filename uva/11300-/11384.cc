#include<iostream>
using namespace std;

int main(){
  int n;
  while(cin >> n)
    for(int i=0,sum=0;;i++){
      sum += (1<<i);
      if(sum>=n){
        cout << i+1 << endl;
        break;
      }
    }
  return 0;
}
