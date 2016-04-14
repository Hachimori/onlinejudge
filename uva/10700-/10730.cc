#include<iostream>
#include<cstdio>
using namespace std;
const int BUF = 100005;

int nVal, val[BUF];

bool read(){
  scanf("%d:",&nVal);
  if(nVal==0) return false;
  for(int i=0;i<nVal;i++)
    scanf("%d",&val[i]);
  return true; 
}

void work(){
  bool need[BUF]={0};
  for(int i=0;i<nVal;i++){
    if(need[val[i]]){
      cout << "no" << endl;
      return;
    }
    for(int j=0;j<i;j++)
      if(0<=val[i]+val[i]-val[j] && val[i]+val[i]-val[j]<nVal)
        need[val[i]+val[i]-val[j]] = true;
  }
  cout << "yes" << endl;
}

int main(){
  while(read()) work();
  return 0;
}
