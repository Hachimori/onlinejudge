#include<stdio.h>
#define EoF -1
#define MAX 10

int Input(void);

main()
{

  int i,j,n,k,l,t,left,right,chk=0;
  int array[MAX][MAX];

  while(1){
    
    scanf("%d",&n);
    if(n==0) break;
  
    scanf("%d",&l);
  
    for(i=0;i<l;i++){ 
      scanf("%d%d",&left,&right);
    
      if(left<right) array[left][right]=1;
      else array[right][left]=1;
    }
    /* for(i=0;i<5;i++){ for(l=0;l<5;l++) printf("%d ",array[i][l]); printf("\n"); } */


    for(i=1;i<n;i++){
      for(j=i+1;j<n;j++){
      
	if(array[i][j]==1)
	  for(k=0;k<i;k++){
	    if(array[k][i]==1 && array[k][j]==1){   
	      for(l=0;l<n;l++) for(t=0;t<n;t++) array[l][t]=0;
	      printf("NOT BICOLORABLE.\n"); chk=1; 
	    }
	  }

	if(chk==1) break;

      }

      if(chk==1) break;

    }

    if( chk==0){
      for(l=0;l<n;l++) for(t=0;t<n;t++) array[l][t]=0;
      printf("BICOLORABLE.\n");
    }

    chk=0;

  }

}
