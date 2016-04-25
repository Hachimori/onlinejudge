#include<iostream>
#include<algorithm>
using namespace std;
const int BUF = 10005;

int nNum,num[BUF],sum;

bool read(){
  if(!(cin >> nNum)) return false;
  for(int i=0;i<nNum;i++) cin >> num[i];
  cin >> sum;
  return true;
}

void work(){
  sort(num,num+nNum);
  int minV = 1<<30, a, b;
  for(int i=0;i<nNum;i++){
    int *ptr = lower_bound(num,num+nNum,sum-num[i]);
    if(ptr!=num+nNum && sum==(*ptr)+num[i] && minV>abs((*ptr)-num[i])){
      minV = abs(*ptr-num[i]);
      a = min(*ptr,num[i]);
      b = max(*ptr,num[i]);
    }
  }
  cout << "Peter should buy books whose prices are " 
       << a << " and " << b << "." << endl << endl;
}

int main(){
  while(read()) work();
  return 0;
}
