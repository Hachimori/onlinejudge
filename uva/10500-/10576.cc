#include<iostream>
using namespace std;

int main(){
  int a, b;
  while(cin >> a >> b){
    int maxV = -1;
    for(int i=1;i<=4;i++){
      if(a*i-b*(5-i)>=0) continue;
      int sum = 0;
      for(int j=0;j<12;j++){
        if(j%5<=i-1)
          sum += a;
        else
          sum -= b;
      }
      maxV = max(maxV,sum);
    }

    if(maxV<0)
      cout << "Deficit" << endl;
    else
      cout << maxV << endl;
  }
  return 0;
}
