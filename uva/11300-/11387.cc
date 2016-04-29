#include<iostream>
using namespace std;

int main(){
  int n;
  while(cin >> n, n){
    if(n==4){
      cout << 6 << endl;
      for(int i=0;i<4;i++)
        for(int j=i+1;j<4;j++)
          cout << i+1 << ' ' << j+1 << endl;
    }
    else if(n%2==0 && n>2){
      cout << n/2*3 << endl;
      for(int i=0;i<n/2;i++){
        cout << i+1 << ' ' << (i==n/2-1 ? 1 : i+2) << endl;
        cout << i+1 << ' ' << i+n/2+1 << endl;
      }
      for(int i=n/2;i<n;i++)
        cout << i+1 << ' ' << (i==n-1 ? n/2+1 : i+2) << endl;
    }
    else
      cout << "Impossible" << endl;
  }
  return 0;
}
