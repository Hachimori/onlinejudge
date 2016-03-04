#include<iostream>
#include<stdio.h>
#define MAX 1000000

int digits[7]={0,0,0,0,0,0,0};
bool self_nums[MAX+1];

int generator(int n, int digits[7]){
  
  int sum=n;

  for(int i=0;i<7;i++)
    sum+=digits[i];
  
  return sum;

}

void Kuriage(int digits[7]){

  for(int i=0;i<7;i++){
    if(digits[i]==10){
      digits[i]=0;
      digits[i+1]++;
    }
  }

}

main(){
  
  for(int i=0;i<=MAX;i++){
    self_nums[i] = true;
  }

  for(int i=0;i<=MAX;i++,digits[0]++){
    
    if(digits[0]==10){
      Kuriage(digits);
      self_nums[generator(i,digits)] = false;
    }
    else self_nums[generator(i,digits)] = false;

  }

  for(int i=1;i<=MAX;i++){
    if(self_nums[i]==true) printf("%d\n",i);
  }

}
