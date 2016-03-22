#include<iostream>
#include<numeric>
#include<cstdio>
using namespace std;
const int BUF = 1005;

int nVal, val[BUF];

bool read(){
  cin >> nVal;
  if(nVal==0) return false;
  for(int i=0;i<nVal;i++){
    double t;
    cin >> t;
    val[i] = (int)(t*100+0.5);
  }
  return true;
}

void work(){  
  int sum1 = 0, sum2 = 0;
  int ave = accumulate(val,val+nVal,0)/nVal;
  bool divisible = accumulate(val,val+nVal,0)%nVal==0;
  for(int i=0;i<nVal;i++){
    if(divisible)
      sum1 += max(0,val[i]-ave);
    else
      sum1 += max(0,val[i]-ave-1);
    sum2 += max(0,ave-val[i]);
  }
  printf("$%.02lf\n",max(sum1,sum2)*0.01);    
}

int main(){
  while(read()) work();
  return 0;
}
