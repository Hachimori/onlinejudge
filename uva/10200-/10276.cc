#include<iostream>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    int n;
    cin >> n;
    n++;
    cout << (n*n/2)-1 << endl;
  }
  return 0;
}
