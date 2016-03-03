#include<iostream>
#define EPS (1e-7)
using namespace std;

int main(){
  int height, up, down, decreaseRate;
  while(cin >> height >> up >> down >> decreaseRate,
        height|up|down|decreaseRate){
    double curHeight = 0;
    for(int i=0;;i++){
      curHeight += max(0.0,up*(1-0.01*decreaseRate*i));
      if(curHeight>=height+EPS){
        cout << "success on day " << i+1 << endl;
        break;
      }
      curHeight -= down;
      if(curHeight<=0-EPS){
        cout << "failure on day " << i+1 << endl;
        break;
      }
    }
  }

  return 0;
}
