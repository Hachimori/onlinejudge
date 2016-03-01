#include<stdio.h>

int main(){
  int i;
  int n, sum;
  
  printf("PERFECTION OUTPUT\n");
  
  while(1){
    scanf("%d",&n);
    if(n==0) break;
    
    sum = 0;
    
    for(i=1;i<=n/2;i++)
      if(n%i==0) 
	sum += i;

    if(sum==n)
      printf("%5d  PERFECT\n",n);
    if(sum<n)
      printf("%5d  DEFICIENT\n",n);
    if(sum>n)
      printf("%5d  ABUNDANT\n",n);
  }
  
  printf("END OF OUTPUT\n");

  return 0;
}
