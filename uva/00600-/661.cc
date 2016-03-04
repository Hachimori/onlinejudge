#include<iostream>
using namespace std;
const int VALUE = 25, OPERATION = 10000;

int nVal, val[VALUE], nOpe, ope[OPERATION], capacity;

bool read(){
  cin >> nVal >> nOpe >> capacity;
  if(!(nVal|nOpe|capacity)) return false;
  for(int i=0;i<nVal;i++) 
    cin >> val[i];
  for(int i=0;i<nOpe;i++){
    cin >> ope[i];
    ope[i]--;
  }
  return true;
}

void work(int cases){
  bool isOn[OPERATION]={};
  int sum = 0, maxV = 0;
  cout << "Sequence " << cases << endl;
  for(int i=0;i<nOpe;i++){
    sum += isOn[ope[i]] ? -val[ope[i]] : val[ope[i]];
    isOn[ope[i]] = !isOn[ope[i]];
    if(sum>capacity){
      cout << "Fuse was blown." << endl;
      cout << endl;
      return;
    }
    maxV = max(maxV,sum);
  }
  cout << "Fuse was not blown." << endl;
  cout << "Maximal power consumption was " << maxV << " amperes." << endl;
  cout << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  return 0;
}
