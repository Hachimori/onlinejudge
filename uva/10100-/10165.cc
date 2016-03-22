#include<iostream>
using namespace std;

int main(){
  int nNum;
  while(cin >> nNum, nNum){
    int ans = 0;
    for(int i=0;i<nNum;i++){
      int num;
      cin >> num;
      ans ^= num;
    }
    cout << (ans ? "Yes" : "No") << endl;
  }
  return 0;
}
