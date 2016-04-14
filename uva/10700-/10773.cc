#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double len, river, swim;

void read(){
  cin >> len >> river >> swim;
}

void work(int cases){
  cout << "Case " << cases << ": ";
  if(swim<=river || river==0){
    cout << "can't determine" << endl;
    return;
  }
  double theta = asin(river/swim);
  printf("%.3lf\n",len/swim*(1/cos(theta)-1));
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
