#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const double PI = acos(-1);

double rad, x, y;

bool read(){
  cin >> rad >> x >> y;
  if(rad<0.1-1e-8) return false;
  rad /= 2;
  return true;
}

int get(){
  int ret = 0;

  for(int yy=1;yy<=30;yy++){
    for(int xx=1;xx<=30;xx++){
      double arg1 = asin((yy-y)/hypot(xx-x,yy-y))-asin(rad/hypot(xx-x,yy-y));
      double arg2 = asin((yy-y)/hypot(xx-x,yy-y))+asin(rad/hypot(xx-x,yy-y));

      bool ok = true;
      for(int px=1;px<=xx;px++)
        for(int py=1;py<=yy;py++){
          if(px==xx && py==yy) continue;
          double arg3 = asin((py-y)/hypot(px-x,py-y))-asin(rad/hypot(px-x,py-y));
          double arg4 = asin((py-y)/hypot(px-x,py-y))+asin(rad/hypot(px-x,py-y));
          if(max(arg1,arg3)<=min(arg2,arg4)+0.01/180*PI){
            ok = false;
            goto _finish;
          }
        }
    _finish:

      if(ok) ret++;
    }
  }
  return ret;
}

void work(){
  int cnt = 0;
  for(int i=0;i<2;i++,x=fabs(1-x))
    for(int j=0;j<2;j++,y=fabs(1-y))
      cnt += get();

  cout << cnt << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}