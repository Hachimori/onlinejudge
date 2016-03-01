#include<iostream>
using namespace std;
const int BUF = 10;

int nVal, val[BUF];

bool read(){
  cin >> nVal;
  if(nVal==0) return false;
  for(int i=0;i<nVal;i++) cin >> val[i];
  return true;
}


void rec(int &cnt){
  bool swapped = false;
  for(int i=0;i+1<nVal;i++)
    if(val[i]>val[i+1]){
      swap(val[i],val[i+1]);
      rec(cnt);
      swap(val[i],val[i+1]);
      swapped = true;
    }
  if(!swapped) cnt++;
}


void work(int cases){
  bool sorted = true;
  for(int i=0;i+1<nVal;i++) 
    if(val[i]>val[i+1])
      sorted = false;

  int cnt = sorted ? -1 : 0;
  rec(cnt);
  cout << "There are " << cnt << " swap maps for input data set " << cases << "." << endl;
}


int main(){
  for(int i=0;read();i++) work(i+1);
  return 0;
}
