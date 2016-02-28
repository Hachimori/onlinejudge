#include<iostream>
#include<cstring>
#include<cstdio>
#define BUF 20000
using namespace std;

int nTh, nAlpha;

bool read(){
  scanf("%d%d",&nTh,&nAlpha);
  return !(nTh==0 && nAlpha==0);
}

bool isOk(int n, char str[BUF]){
  for(int len=1;len<=n/2;len++){
    bool same = true;
    for(int j=0;j<len;j++)
      if(str[n-1-j]!=str[n-1-len-j]){
        same = false;
        break;
      }
    if(same) return false;
  }
  return true;
}

bool rec(int idx, int &rank, char cur[BUF]){
  if(isOk(idx,cur)) 
    rank++;
  else 
    return false;

  if(rank==nTh){
    cur[idx] = '\0';
    return true;
  }
  
  for(int i=0;i<nAlpha;i++){
    cur[idx] = 'A'+i;
    if(rec(idx+1,rank,cur)) return true;
  }
  
  return false;
}

void work(){
  int rank = 0;
  char cur[BUF];
  
  for(int i=0;i<nAlpha;i++){
    cur[0] = 'A'+i;
    if(rec(1,rank,cur))
      break;
  }
  
  for(int i=0,n=strlen(cur);i<n;i+=4){
    if(i!=0 && i!=64) printf(" ");
    if(i==64) printf("\n");
    for(int j=i;j<min(i+4,n);j++)
      printf("%c",cur[j]);
  }
  printf("\n%d\n",strlen(cur));
}

int main(){
  while(read())
    work();
  
  return 0;
}
