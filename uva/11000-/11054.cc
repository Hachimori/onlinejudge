#include<iostream>
using namespace std;
const int BUF = 100005;

int main(){
  while(1){
    long long nNum, num[BUF];
    cin >> nNum;
    if(nNum==0) break;
    for(int i=0;i<nNum;i++) cin >> num[i];

    long long sum = 0;
    for(int i=0;i+1<nNum;i++){
      sum += llabs(num[i]);
      num[i+1] += num[i];
    }
    
    cout << sum << endl;
  }
  return 0;
}
