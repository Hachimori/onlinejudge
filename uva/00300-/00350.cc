#include<iostream>
using namespace std;
const int BUF = 10000;

int toMul, toAdd, mod, last;

bool read(){
  cin >> toMul >> toAdd >> mod >> last;
  return toMul|toAdd|mod|last;
}


void work(int cases){
  int cycle[BUF];
  memset(cycle,-1,sizeof(cycle));

  for(int i=0;;i++){
    if(cycle[last]!=-1){
      cout << "Case " << cases << ": " << i-cycle[last] << endl;
      break;
    }
    cycle[last] = i;
    last = (last*toMul+toAdd)%mod;
  }
}


int main(){
  for(int i=0;read();i++) work(i+1);
  return 0;
}
