#include<stdio.h>

#define MAX_SIZE 55

int main(){
  int i, cases=1;
  int nBlock, height[MAX_SIZE], average, ans;
    
  while(1){
    scanf("%d",&nBlock);
    if(nBlock==0) break;

    for(i=0;i<nBlock;i++)
      scanf("%d",&height[i]);

    
    average = 0;
    for(i=0;i<nBlock;i++)
      average += height[i];

    average /= nBlock;

    
    ans = 0;
    for(i=0;i<nBlock;i++)
      if(average>height[i])
	ans += average-height[i];

    printf("Set #%d\n",cases);
    printf("The minimum number of moves is %d.\n\n",ans);
    cases++;
  }
  
  return 0;
}
