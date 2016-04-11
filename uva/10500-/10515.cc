#include<iostream>
#include<cstdio>
#include<cstring>
#define BUF 105
using namespace std;

int p, cycle[]={1,1,4,4,2,1,1,4,4,2}; 
int expo[BUF], leng;

int mod(int v[], int len, int d){
  for(int i=len-1;i>=0;i--){
    if(i==len-1)
      v[i] %= d;
    else{
      v[i] = (v[i]+v[i+1]*10)%d;
      v[i+1] = 0;
    }
  }
  return v[0];  
}

bool read(){
  char a[BUF], b[BUF];
  scanf("%s%s",a,b);
  if(a[0]=='0' && b[0]=='0') return false;
  
  leng = strlen(b);
  p = a[strlen(a)-1]-'0';
  
  for(int i=leng-1,j=0;i>=0;i--,j++)
    expo[j] = b[i]-'0';

  return true;
}

void work(){
  if(leng==1 && expo[0]==0) printf("1\n");
  else {
    int ret = mod(expo,leng,cycle[p]);
    
    if(ret==0) ret = cycle[p];
    
    int cur = 1;
    for(int i=0;i<ret;i++)
      cur = (cur*p)%10;
    printf("%d\n",cur);
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}
