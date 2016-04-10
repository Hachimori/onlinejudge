#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  double n;
  while(cin >> n, n>=0){
    if(n==1)
      printf("0%%\n");
    else
      printf("%.f%%\n",n*25);
  }
  return 0;
}
