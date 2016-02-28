#include<stdio.h>

#define MAX_SIZE 55

int main(){
  int i, j, tmp, cases;
  int nTrain, train[MAX_SIZE], ans;
  
  scanf("%d",&cases);
  
  while(cases--){
    scanf("%d",&nTrain);

    for(i=0;i<nTrain;i++)
      scanf("%d",&train[i]);
    
    ans = 0;
    
    for(i=0;i<nTrain;i++)
      for(j=0;j<nTrain-1;j++)
	if(train[j]>train[j+1]){
	  tmp = train[j];
	  train[j] = train[j+1];
	  train[j+1] = tmp;
	  ans++;
	}

    printf("Optimal train swapping takes %d swaps.\n",ans);
  }
  
  return 0;
}
