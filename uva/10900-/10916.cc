#include<iostream>
#include<cmath>
using namespace std;

int year;

bool read(){
  cin >> year;
  return year!=0;
}

void work(){
  int allow = 4;
  for(int cur=1960;cur+10<=year;cur+=10,allow*=2);
  
  double sum = 0;  
  for(int n=1;;n++){
    // log2(n)
    sum += log10(1.0*n)/log10(2.0);
    if(sum>allow){
      cout << n-1 << endl;
      return;
    }
  }
}

int main(){
  while(read())
    work();

  return 0;
}
