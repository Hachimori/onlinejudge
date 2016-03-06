#include<iostream>
#include<numeric>
using namespace std;
const int BUF = 50005;

int row, col, nPt, r[BUF], c[BUF];

void read(){
  cin >> row >> col >> nPt;
  for(int i=0;i<nPt;i++)
    cin >> r[i] >> c[i];
}

int calc(int sz, int pos[BUF]){
  sort(pos,pos+nPt);
  int nLeft = 0, nRight = nPt, idx = 0;
  int curV = accumulate(pos,pos+nPt,0), minV = accumulate(pos,pos+nPt,0), minIdx = 0;
  for(int i=0;i<=sz;i++){
    while(idx<nPt && pos[idx]==i){
      nRight--;
      nLeft++;
      idx++;
    }
    curV += nLeft-nRight;
    if(minV>curV){
      minV = curV;
      minIdx = i+1;
    }
  }
  return minIdx;
}

void work(){
  cout << "(Street: " << calc(row,r) << ", Avenue: " << calc(col,c) << ")" << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
