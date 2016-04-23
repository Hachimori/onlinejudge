#include<iostream>
#define GAP 1000
using namespace std;

void work(){
  int nGap, sub[GAP];
  cin >> nGap;
  
  for(int i=0;i<nGap;i++){
    int up, low;
    cin >> up >> low;
    sub[i] = up-low;
  }
  
  for(int i=1;i<nGap;i++)
    if(sub[i-1]!=sub[i]){
      cout << "no" << endl;
      return;
    }
  cout << "yes" << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    work();
  }

  return 0;
}
