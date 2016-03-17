#include<iostream>
using namespace std;
const int VAL = 605;

int nVal, val[VAL], K;

bool read(){
  if(!(cin >> nVal >> K)) return false;
  nVal++;
  for(int i=0;i<nVal;i++)
    cin >> val[i];
  return true;
}

void work(){
  int L = 0, R = 1<<30;
  while(L!=R){
    int mid = (L+R)/2;
    int sum = 0, cnt = 0;
    for(int i=0;i<nVal;i++){
      if(val[i]>mid){
        cnt = K+1;
        break;
      }
      if(sum+val[i]>mid){
        cnt++;
        sum = val[i];
      }
      else
        sum += val[i];
    }
    if(cnt<=K)
      R = mid;
    else
      L = mid+1;
  }
  cout << L-1 << endl;
}

int main(){
  while(read()) work();
  return 0;
}
