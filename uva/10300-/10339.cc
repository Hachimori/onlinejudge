#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int daySec = 24*60*60, watchSec = 12*60*60;

int late1, late2;

bool read(){
  return cin >> late1 >> late2;
}

void work(){
  int delta = abs(late1-late2);
  int second = (int)(fmod(1.0*watchSec*(daySec-late1)/delta+30,watchSec));
  int hour = second/60/60;
  int minute = second/60%60;
  printf("%d %d %02d:%02d\n",late1,late2,hour==0?12:hour,minute);
}

int main(){
  while(read()) work();
  return 0;
}
