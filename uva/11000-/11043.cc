#include<iostream>
#include<cstdio>
#define CHAR 256
#define BUF 1000000
using namespace std;
typedef unsigned char unch;

int nCh;
unch str[BUF];

void read(){
  nCh = 0;
  while(true){
    if(scanf("%c",&str[nCh])==EOF) break;
    nCh++;
  }
}

void work(){
  int change[CHAR][CHAR];
  for(int i=0;i<CHAR;i++)
    for(int j=0;j<CHAR;j++)
      change[i][j] = -1;

  for(int i=0;i<nCh;i+=6){
    int mask = 0;
    
    for(int j=i;j<i+6 && j<nCh;j++){
      if(j<2) continue;
      if(change[str[j-2]][str[j-1]]!=str[j]){
	change[str[j-2]][str[j-1]] = str[j];	  
	continue;
      }
      mask |= (1<<(j-i));
    }
    
    cout << (unch)(64+mask);
    for(int j=i;j<i+6 && j<nCh;j++)
      if((mask&(1<<(j-i)))==0)
	cout << str[j];
  }
}

int main(){
  read();
  work();

  return 0;
}