#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double PI = acos(-1.0);

int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    int W, H, degree;
    cin >> W >> H >> degree;

    double angle = degree*PI/180, curX = 0, sum = 0;
    bool isUpper = false;
    for(int i=0;;i++){
      if(curX+H/tan(angle)>W){
        sum += hypot(W-curX,(W-curX)*tan(angle));
        double lastX = W;
        double lastY = isUpper ? H-(W-curX)*tan(angle) : (W-curX)*tan(angle);
        printf("%.3lf\n",sum/hypot(lastX,lastY));
        break;
      }
      sum += hypot(H,H/tan(angle));
      curX += H/tan(angle);
      isUpper = !isUpper;
    }
  }

  return 0;
}
