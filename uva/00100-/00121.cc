#include<iostream>
#include<cmath>
using namespace std;

double w, h;

bool read(){
  return cin >> w >> h;
}

int calc(double ww, double hh){
  int nYoko = floor(ww);
  int nTate = floor((hh-1)/(sqrt(3)/2)+1);

  if(ww-floor(ww)>=0.5)
    return nYoko*nTate;
  else
    return nYoko*nTate-nTate/2;
}

void work(){
  int grid = floor(w)*floor(h);
  int skew = max(calc(w,h),calc(h,w));
  
  if(grid>=skew)
    cout << grid << " grid" << endl;
  else
    cout << skew << " skew" << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
