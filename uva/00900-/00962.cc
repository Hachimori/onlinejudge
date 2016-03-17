#include<iostream>
#include<algorithm>
#include<cstdio>
#define CUBE 1105
#define RANGE 100005
using namespace std;

int nCube, cube[CUBE];
int bgn, end;

void makeCube(){
  nCube = 0;
  for(int i=1;i*i*i<=1000100005;i++)
    cube[nCube++] = i*i*i;
}

bool read(){
  if(scanf("%d%d",&bgn,&end)==EOF) return false;
  end += bgn;
  return true;
}

void work(){
  int cnt[RANGE];
  fill(cnt,cnt+RANGE,0);
  
  for(int i=0;i<nCube && cube[i]<=end;i++){
    int idx = lower_bound(cube,cube+nCube,bgn-cube[i])-cube;
    
    for(int num=bgn;idx<=i && num<=end;num++){
      if(idx<nCube && cube[idx]+cube[i]==num)
	cnt[num-bgn]++;
      while(idx<nCube && cube[idx]+cube[i]<num) idx++;
      if(idx<nCube && num!=cube[idx]+cube[i]) num = cube[idx]+cube[i]-1;
    }
  }

  bool none = true;
  for(int i=bgn;i<=end;i++)
    if(cnt[i-bgn]>=2){
      none = false;
      printf("%d\n",i);
    }
      
  if(none) printf("None\n");
}

int main(){
  makeCube();

  while(read())
    work();
  
  return 0;
}