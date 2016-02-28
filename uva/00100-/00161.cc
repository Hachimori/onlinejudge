#include<iostream>
#include<algorithm>
#define BUF 10000
using namespace std;

int nCycle, cycle[BUF];

bool read(){
  for(nCycle=0;;nCycle++){
    cin >> cycle[nCycle];
    if(cycle[nCycle]==0) break;
  }
  return nCycle>=2;
}

void work(){
  for(int i=*min_element(cycle,cycle+nCycle)+1;i<=5*60*60;i++){
    bool ok = true;
    for(int j=0;j<nCycle;j++)
      if(i%(cycle[j]*2)>=cycle[j]-5){
        ok = false;
        break;
      }
    if(ok){
      printf("%02d:%02d:%02d\n",i/3600,(i/60)%60,i%60);
      return;
    }
  }
  cout << "Signals fail to synchronise in 5 hours" << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
