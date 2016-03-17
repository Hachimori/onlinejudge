#include<iostream>
#include<cstdio>
using namespace std;
const int VAL = 1000005;

int limit, nVal, val[VAL];

bool read(){
  if(scanf("%d%d",&limit,&nVal)==EOF) return false;
  for(int i=0;i<nVal;i++) scanf("%d",&val[i]);
  return true;
}

void work(){
  int L = 0, R = 0, maxV = 0, maxY1, maxY2;
  while(R<nVal){
    while(val[R]-val[L]+1>limit) L++;
    if(maxV<R-L+1){
      maxV = R-L+1;
      maxY1 = L;
      maxY2 = R;
    }
    R++;
  }

  cout << maxV << ' ' << val[maxY1] << ' ' << val[maxY2] << endl;
}

int main(){
  while(read()) work();
  return 0;
}
