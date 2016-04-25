#include<iostream>
#include<algorithm>
#define NUM 18
using namespace std;
typedef long long integer;

int nNum, num[NUM];

bool read(){
  if(!(cin >> nNum)) return false;
  for(int i=0;i<nNum;i++) cin >> num[i];
  return true;
}

void work(int cases){
  integer ans = 0;
  for(int i=0;i<nNum;i++){
    integer prod = 1;
    for(int j=i;j<nNum;j++){
      prod *= num[j];
      ans = max(ans,prod);
    }
  }

  cout << "Case #" << cases << ": The maximum product is " << ans << '.' << endl;
}

int main(){
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }

  return 0;
}
