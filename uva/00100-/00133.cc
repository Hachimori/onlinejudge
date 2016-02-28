#include<iostream>
#include<cstdio>
#define BUF 22
using namespace std;

int nMan, moveR, moveL;

bool read(){
  cin >> nMan >> moveR >> moveL;
  return !(nMan==0 && moveR==0 && moveL==0);
}

void work(){
  bool killed[BUF];
  int curR = -1, curL = nMan, remain = nMan;

  for(int i=0;i<nMan;i++) killed[i] = false;

  while(remain!=0){
    for(int cnt=0;cnt<moveR;){
      curR = (curR+1)%nMan;
      if(!killed[curR]) cnt++;
    }

    for(int cnt=0;cnt<moveL;){
      curL = (curL+nMan-1)%nMan;
      if(!killed[curL]) cnt++;
    }
    
    if(remain!=nMan) printf(",");
    if(curR!=curL) {
      printf("%3d%3d",curR+1,curL+1);
      remain -= 2;
    }
    else {
      printf("%3d",curR+1);
      remain--;
    }

    killed[curR] = true;
    killed[curL] = true;
  }
  printf("\n");
}

int main(){
  while(read())
    work();
  
  return 0;
}