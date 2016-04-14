#include<iostream>
using namespace std;

int main(){
  unsigned int mask, L, R;
  while(cin >> mask >> L >> R){
    unsigned int cur = 0;
    for(int i=31;i>=0;i--){
      if((cur|(1<<i))>R) 
        continue;
      if(cur+(1<<i)-1<L){
        cur |= (1<<i);
        continue;
      }
      if(mask&(1<<i))
        continue;
      else
        cur |= (1<<i);
    }
    cout << cur << endl;
  }
  return 0;
}
