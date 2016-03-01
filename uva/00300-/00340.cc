#include<iostream>
#include<numeric>
using namespace std;
const int BUF = 1005;

int main(){
  int nVal, val[BUF];
  for(int loop=0;;loop++){
    cin >> nVal;
    if(nVal==0) break;
    for(int i=0;i<nVal;i++) cin >> val[i];

    cout << "Game " << loop+1 << ":" << endl;
    while(1){
      int guess[BUF];
      for(int i=0;i<nVal;i++) cin >> guess[i];
      if(accumulate(guess,guess+nVal,0)==0) break;

      int cntHit = 0, cntBlow = 0;
      bool usedV[BUF]={}, usedG[BUF]={};
      for(int i=0;i<nVal;i++)
        if(val[i]==guess[i]){
          usedV[i] = usedG[i] = true;
          cntHit++;
        }
      
      for(int i=0;i<nVal;i++)
        for(int j=0;j<nVal;j++)
          if(val[i]==guess[j] && !usedV[i] && !usedG[j]){
            usedV[i] = usedG[j] = true;
            cntBlow++;
          }

      cout << "    (" << cntHit << "," << cntBlow << ")" << endl;
    }
  }
  return 0;
}
