#include<iostream>
using namespace std;
const int BUF = 105;

int main(){
  int cases;
  cin >> cases;
  for(int caze=0;caze<cases;caze++){
    int nDay, nPpl, val[BUF];
    cin >> nDay >> nPpl;
    for(int i=0;i<nPpl;i++) cin >> val[i];
    int cnt = 0;
    for(int i=1;i<=nDay;i++){
      if((i-1)%7==5 || (i-1)%7==6) continue;
      for(int j=0;j<nPpl;j++)
        if(i%val[j]==0){
          cnt++;
          break;
        }
    }
    cout << cnt << endl;
  }
  return 0;
}
