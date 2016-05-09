#include<iostream>
using namespace std;
const int BUF = 10005;

int nVal, val[BUF];

bool read(){
  cin >> nVal;
  if(nVal==0) return false;
  for(int i=0;i<nVal;i++) cin >> val[i];
  return true;
}


void work(){
  int cnt = 0;
  for(int i=0;i<nVal;i++){
    int pre = (i-1+nVal)%nVal, nex = (i+1)%nVal;
    cnt += (val[pre]<val[i] && val[i]>val[nex]) || 
           (val[pre]>val[i] && val[i]<val[nex]);
  }
  cout << cnt << endl;
}


int main(){
  while(read()) work();
  return 0;
}
