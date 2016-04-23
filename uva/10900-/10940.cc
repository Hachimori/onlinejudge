#include<iostream>
#include<cmath>
using namespace std;


int n;

bool read(){
  cin >> n;
  return n!=0;
}


void work(){
  if(n==1)
    cout << 1 << endl;
  else
    cout << (n-(1<<(int)log2(n)))*2 << endl;
}


int main(){
  while(read()) work();
  return 0;
}
